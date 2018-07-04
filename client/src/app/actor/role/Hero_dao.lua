
local LuaGameActor = require("app.actor.LuaGameActor")

local Hero_dao = class("Hero_dao", LuaGameActor)


-----------------------------------------------------------------------------------

local RoleConfig = require("app.config.RoleConfig")
local CommonActorConfig = require("app.config.CommonActorConfig")


--------------------------------------override--------------------------------------

function Hero_dao:ctor()
	Hero_dao.super.ctor(self)

	self:setActorType(AT_PLAYER)


	self.actorSpeedController:setGravityEnable(true)

	self.armatureSpeedController:setGravity(0, -800)
	self.armatureSpeedController:setGravityEnable(true)
	self.armatureSpeedController:setMinValue(0, 0)
	self.armatureSpeedController:setMinValueEnable(true)
	self.armatureSpeedController:setStopUpdate(true)

	self.actorSpeedController:setFrictionEnable(true)
end

function Hero_dao:override_attOtherActorCallback(otherActor)

	local stateName = self.FSM:getCurState():getStateName()

	if stateName == "State_Attack4" 
	or stateName == "State_Upcut" then
		otherActor:override_beAttacked(self, true)
	else
		otherActor:override_beAttacked(self, false)
	end
end

function Hero_dao:override_beAttacked(attackActor, isPickUp)
	self.super.override_beAttacked(self, attackActor, isPickUp)

	if not isPickUp then
		self:handle("CMD_hit")
	else
		local JumpUpTime = CommonActorConfig.playerCollapseJumpTime
		local JumpHeight = CommonActorConfig.playerCollapseJumpHeight
		if self:handle("CMD_Collapse") then
			local move = cc.MoveBy:create(JumpUpTime, {x = 0, y = JumpHeight})
			local call1 = cc.CallFunc:create(function()
				self:handle("CMD_To_Collapse2")
			end)
			local call2 = cc.CallFunc:create(function()
				self:handle("CMD_To_Collapse3")
			end)
			local q = cc.Sequence:create(move, call1, move:reverse(), call2)
			self:getArmature():runAction(q)
	
			local word = getGameWord()
			if word ~= nil and word:getLocalPlayer() == self then
				local winSize = cc.Director:getInstance():getVisibleSize()
				local subheight = winSize.height - word:getMapSize().height
				subheight = subheight * 0.5
				subheight = math.max(subheight, -JumpHeight)
	
				local mapMove = cc.MoveBy:create(JumpUpTime, {x = 0, y = subheight})
				word:getRootNode():runAction(cc.Sequence:create(mapMove, mapMove:reverse()))
			end
		end
	end
end

--------------------------------------logic--------------------------------------

--切换角色
function Hero_dao:changeRole(name)

	if self.roleName == name then
		return
	end
	self.roleName = name

	self:loadConfig(RoleConfig[name])

	ccs.ArmatureDataManager:getInstance():addArmatureFileInfo("uianimation/juhe_texiao.ExportJson")
	local ArmatureNode = ccs.Armature:create()
	ArmatureNode:init("juhe_texiao")
	ArmatureNode:getAnimation():play("juhe_texiao")
	ArmatureNode:setPosition({x = 0, y = 110})
	self:addChild(ArmatureNode)

	self.isRun = false
	self.isJump = false
	self.isAttack1 = false
	self.isAttack2 = false
	self.isAttack3 = false
	self.isAttack4 = false

	self:initFSM()

	self.FSM:start("State_Stand")
end

function Hero_dao:changeValueByOri(x)
	if self:getOrientation() == GAME_ORI_LEFT then
		return -x
	end
	return x
end

function Hero_dao:setMoveStop()
	self.actorSpeedController:setGravityEnable(false)
	self.actorSpeedController:setForceEnable(false)
end

function Hero_dao:setMove(x, y)

	self.actorSpeedController:setGravityEnable(true)
	self.actorSpeedController:setForceEnable(true)

	local posotiveX = 0
	if x > 0.0 then
		self:setOrientation(GAME_ORI_RIGHT)
		posotiveX = 1

	elseif x < 0.0 then
		self:setOrientation(GAME_ORI_LEFT)
		posotiveX = -1
	end

	self.actorSpeedController:setGravityPositive(posotiveX, 0)
	self.armatureSpeedController:setGravityPositive(posotiveX, 0)
end

function Hero_dao:jump()
	if self:handle("CMD_JumpUpStart") then
		self.armatureSpeedController:setStopUpdate(false)
		self.armatureSpeedController:setForceEnable(true)
		self.armatureSpeedController:setFrictionEnable(true)

		local isUpCut = false

		if self.FSM:getCurState():getStateName() == "State_Upcut" then
			self.armatureSpeedController:setForce(0, 10)
			self.armatureSpeedController:setFriction(-100)
			isUpCut = true
		else
			self.armatureSpeedController:setForce(0, 2000)
			self.armatureSpeedController:setFriction(2000)
		end

		local stage = 0
		local jumpTime = 0
		if isUpCut then
			stage = -2
		end

		local jumpH = 350
		local percent = 1.0
		local mapBeginY = 0
		local gameword = getGameWord()
		local rootNode = nil
		if gameword then
			rootNode = gameword:getRootNode()
			mapBeginY = 0

			local winSize = cc.Director:getInstance():getVisibleSize()
			local subheight = gameword:getMapSize().height - winSize.height
			subheight = subheight * 0.5
			subheight = math.min(subheight, jumpH)

			percent = subheight / jumpH
		end
		

		local function jumpFinishCall()
			self.armatureSpeedController:setStopUpdate(true)
			self.armatureSpeedController:clearLuaUpdateCall()
			self.armatureSpeedController:setForceEnable(false)
			self.armatureSpeedController:setFrictionEnable(false)

			--print("stage == 3")
			if self.actorSpeedController:isGravityEnable() 
				and math.abs(self.actorSpeedController:getGravityX()) > 0 then
				self:handle("CMD_JumpTo_MoveStart")
			else
				self:handle("CMD_JumpDownEnd")
			end
		end

		self.armatureSpeedController:setLuaUpdateCall(function(x, y, time)

			jumpTime = jumpTime + time

			if stage == -2 and jumpTime > 0.15 then
				self.armatureSpeedController:setForce(0, 0)
				self.armatureSpeedController:setFriction(0)
				stage = -1
			end
			if stage == -1 and jumpTime > 0.27 then
				self.armatureSpeedController:setForce(0, 700)
				self.armatureSpeedController:setFriction(-2000)
				stage = 0
			end

			local curHeight = self.armatureSpeedController:getTarget():getPositionY()

			if stage == 0 then
				if not isUpCut then
					if self.armatureSpeedController:getAppendY() < 0 then
						self:handle("CMD_JumpDownStart")
						stage = 1
					end
				else
					if curHeight >= jumpH then
						self.armatureSpeedController:setForce(0, 830)
						self.armatureSpeedController:setFriction(2000)
						self:handle("CMD_JumpDownStart")
						stage = 1
						--print("stage == 1")
					end
				end
			end
			if stage == 1 and self.armatureSpeedController:getForceY() <= 400 then
				self.armatureSpeedController:setForce(0, -10)
				self.armatureSpeedController:setFriction(-500)
				stage = 2
				--print("stage == 2")
			end
			if y == 0 then
				if isUpCut then
					if stage > 0 then
						jumpFinishCall()
					end
				else
					jumpFinishCall()
				end
			end

			-- 地图Y轴滚动
			--subheight
			--curHeight
			if rootNode then
				local tmp = mapBeginY - curHeight * percent
				rootNode:setPositionY(tmp)
			end

		end)
	end
end

--------------------------------------FSM--------------------------------------

function Hero_dao:initFSM()

	--站立
	self.FSM:addTranslation("State_Run", "CMD_MoveStand", "State_Stand")
	self.FSM:addTranslation("State_Run2", "CMD_MoveStand", "State_Brak")
	self.FSM:addTranslation("State_Brak", "State_Brak_stop", "State_Stand")

	--移动
	self.FSM:addTranslation("State_Stand", "CMD_MoveStart", "State_Run")
	self.FSM:addTranslation("State_Brak", "CMD_MoveStart", "State_Run")
	self.FSM:addTranslation("State_Run", "State_Run_stop", "State_Run2")

	--跳跃
	self.FSM:addTranslation("State_Stand", "CMD_JumpUpStart", "State_JumpUp")
	self.FSM:addTranslation("State_Run", "CMD_JumpUpStart", "State_JumpUp")
	self.FSM:addTranslation("State_Run2", "CMD_JumpUpStart", "State_JumpUp")
	self.FSM:addTranslation("State_Brak", "CMD_JumpUpStart", "State_JumpUp")
	self.FSM:addTranslation("State_Attack1", "CMD_JumpUpStart", "State_Upcut")
	self.FSM:addTranslation("State_Attack2", "CMD_JumpUpStart", "State_Upcut")
	self.FSM:addTranslation("State_Attack3", "CMD_JumpUpStart", "State_Upcut")
	--self.FSM:addTranslation("State_Attack4", "CMD_JumpUpStart", "State_JumpUp")

	self.FSM:addTranslation("State_Upcut", "CMD_JumpDownStart", "State_JumpDown")
	self.FSM:addTranslation("State_Upcut", "CMD_JumpDownEnd", "State_JumpDownEnd")
	self.FSM:addTranslation("State_Upcut", "CMD_JumpTo_MoveStart", "State_Run")
	self.FSM:addTranslation("State_Upcut", "State_JumpDownEnd_stop", "State_Stand")


	self.FSM:addTranslation("State_JumpUp", "CMD_JumpDownStart", "State_JumpDown")
	self.FSM:addTranslation("State_JumpDown", "CMD_JumpDownEnd", "State_JumpDownEnd")
	self.FSM:addTranslation("State_JumpDown", "CMD_JumpTo_MoveStart", "State_Run")
	self.FSM:addTranslation("State_JumpDownEnd", "State_JumpDownEnd_stop", "State_Stand")

	--换刀
	self.FSM:addTranslation("State_Stand", "CMD_change", "State_Replace")
	self.FSM:addTranslation("State_Run", "CMD_change", "State_Replace")
	self.FSM:addTranslation("State_Run2", "CMD_change", "State_Replace")
	self.FSM:addTranslation("State_Brak", "CMD_change", "State_Replace")
	self.FSM:addTranslation("State_Replace", "State_Replace_stop", "State_Stand")

	--受到攻击
	self.FSM:addTranslation("State_Stand", "CMD_hit", "State_Hit")
	self.FSM:addTranslation("State_Run", "CMD_hit", "State_Hit")
	self.FSM:addTranslation("State_Run2", "CMD_hit", "State_Hit")
	self.FSM:addTranslation("State_Brak", "CMD_hit", "State_Hit")
	self.FSM:addTranslation("State_Hit", "State_Hit_stop", "State_Stand")

	--受到攻击并向后倒
	self.FSM:addTranslation("State_Stand", "CMD_Collapse", "State_Collapse1")
	self.FSM:addTranslation("State_Run", "CMD_Collapse", "State_Collapse1")
	self.FSM:addTranslation("State_Run2", "CMD_Collapse", "State_Collapse1")
	self.FSM:addTranslation("State_Brak", "CMD_Collapse", "State_Collapse1")

	self.FSM:addTranslation("State_Collapse1", "CMD_To_Collapse2", "State_Collapse2")
	self.FSM:addTranslation("State_Collapse2", "CMD_To_Collapse3", "State_Collapse3")
	self.FSM:addTranslation("State_Collapse3", "State_Collapse3_stop", "State_Stand")

	--普通攻击
	self.FSM:addTranslation("State_Stand", "CMD_Attack", "State_Attack1")
	self.FSM:addTranslation("State_Run", "CMD_Attack", "State_Attack1")
	self.FSM:addTranslation("State_Run2", "CMD_Attack", "State_Attack1")
	self.FSM:addTranslation("State_Brak", "CMD_Attack", "State_Attack1")

	self.FSM:addTranslation("State_Stand", "CMD_To_Attack1", "State_Attack1")
	self.FSM:addTranslation("State_Attack1", "State_Attack1_stop", "State_Stand")

	self.FSM:addTranslation("State_Stand", "CMD_To_Attack2", "State_Attack2")
	self.FSM:addTranslation("State_Attack2", "State_Attack2_stop", "State_Stand")

	self.FSM:addTranslation("State_Stand", "CMD_To_Attack3", "State_Attack3")
	self.FSM:addTranslation("State_Attack3", "State_Attack3_stop", "State_Stand")

	self.FSM:addTranslation("State_Stand", "CMD_To_Attack4", "State_Attack4")
	self.FSM:addTranslation("State_Attack4", "State_Attack4_stop", "State_Stand")

	--跳跃攻击
	self.FSM:addTranslation("State_JumpUp", "CMD_Attack", "State_JumpAttack3")
	self.FSM:addTranslation("State_JumpAttack3", "State_JumpAttack3_stop", "State_JumpDown")
	self.FSM:addTranslation("State_JumpAttack3", "CMD_JumpTo_MoveStart", "State_Run")
	self.FSM:addTranslation("State_JumpAttack3", "CMD_JumpDownEnd", "State_JumpDownEnd")
end

function Hero_dao:enter_State_Stand()
	if self.actorSpeedController:isGravityEnable() and math.abs(self.actorSpeedController:getGravityX()) > 0 then
		local call = cc.CallFunc:create(function()
			self:handle("CMD_MoveStart")
		end)
		self:runAction(call)
	end
end

function Hero_dao:enter_State_Run()
	self.isRun = true

	local x = self:changeValueByOri(CommonActorConfig.playerMoveSpeed.x * 0.9)
	local y = CommonActorConfig.playerMoveSpeed.y
	self.actorSpeedController:setGravity(x, y)
end

function Hero_dao:leave_State_Run()
	self.isRun = false
	self.actorSpeedController:setGravity(0, 0)
end

function Hero_dao:enter_State_Run2()
	self.isRun = true
	local x = self:changeValueByOri(CommonActorConfig.playerMoveSpeed.x)
	local y = CommonActorConfig.playerMoveSpeed.y
	self.actorSpeedController:setGravity(x, y)
end

function Hero_dao:leave_State_Run2()
	self.isRun = false
	self.actorSpeedController:setGravity(0, 0)
end

function Hero_dao:enter_State_Brak()
	self.actorSpeedController:setForce(self:changeValueByOri(800), 0)
	self.actorSpeedController:setForceEnable(true)
	self.actorSpeedController:setFriction(700)
end

function Hero_dao:leave_State_Brak()
	self.actorSpeedController:setForce(0, 0)
	self.actorSpeedController:setFriction(0)
	self.actorSpeedController:setForceEnable(false)
end

function Hero_dao:enter_State_JumpUp()
	self.isJump = true
	local x = self:changeValueByOri(CommonActorConfig.playerMoveSpeed.x * 0.5)
	local y = CommonActorConfig.playerMoveSpeed.y
	self.actorSpeedController:setGravity(x, y)
end

function Hero_dao:enter_State_JumpDownEnd()
	self.isJump = false
end

function Hero_dao:enter_State_Attack1()
	self.isAttack1 = true
	self.actorSpeedController:setForce(self:changeValueByOri(200), 0)
	self.actorSpeedController:setFriction(450)
end

function Hero_dao:leave_State_Attack1()
	self.isAttack1 = false
	self.actorSpeedController:setForce(0, 0)
	self.actorSpeedController:setFriction(0)
end

function Hero_dao:enter_State_Attack2()
	self.isAttack2 = true
	self.actorSpeedController:setForce(self:changeValueByOri(100), 0)
	self.actorSpeedController:setFriction(400)
end

function Hero_dao:leave_State_Attack2()
	self.isAttack2 = false
	self.actorSpeedController:setForce(0, 0)
	self.actorSpeedController:setFriction(0)
end

function Hero_dao:enter_State_Attack3()
	self.isAttack3 = true
	self.actorSpeedController:setForce(self:changeValueByOri(80), 0)
	self.actorSpeedController:setFriction(300)
end

function Hero_dao:leave_State_Attack3()
	self.isAttack3 = false
	self.actorSpeedController:setForce(0, 0)
	self.actorSpeedController:setFriction(0)
end

function Hero_dao:enter_State_Attack4()
	self.isAttack4 = true
	self.actorSpeedController:setForce(self:changeValueByOri(50), 0)
	self.actorSpeedController:setFriction(-300)
	self.actorSpeedController:setLuaUpdateCall(function(x, y, time)
		local tmp = self.actorSpeedController:getAppendX()
		if math.abs(tmp) >= 3 then
			self.actorSpeedController:clearLuaUpdateCall()
			self.actorSpeedController:setForce(0, 0)
			self.actorSpeedController:setFriction(0)
		end
	end)
end

function Hero_dao:leave_State_Attack4()
	self.isAttack4 = false
	self.actorSpeedController:setForce(0, 0)
	self.actorSpeedController:setFriction(0)
	self.actorSpeedController:clearLuaUpdateCall()
end

function Hero_dao:enter_State_Replace()
	self:lockOrientation()
end

function Hero_dao:leave_State_Replace()
	self:unLockOrientation()
end

function Hero_dao:enter_State_Hit()
	self.actorSpeedController:setForce(self:changeValueByOri(-100), 0)
	self.actorSpeedController:setFriction(300)
	self.actorSpeedController:setForceEnable(true)
	self.actorSpeedController:setFrictionEnable(true)
	self:lockOrientation()
end

function Hero_dao:leave_State_Hit()
	self.actorSpeedController:setForceEnable(false)
	self.actorSpeedController:setFrictionEnable(false)
	self.actorSpeedController:setForce(0, 0)
	self.actorSpeedController:setFriction(0)
	self:unLockOrientation()
end

function Hero_dao:enter_State_Collapse1()
	self.actorSpeedController:setForce(self:changeValueByOri(-200), 0)
	self.actorSpeedController:setFriction(150)
	self.actorSpeedController:setForceEnable(true)
	self.actorSpeedController:setFrictionEnable(true)
	self:lockOrientation()
end

function Hero_dao:leave_State_Collapse2()
	self.actorSpeedController:setForceEnable(false)
	self.actorSpeedController:setFrictionEnable(false)
	self.actorSpeedController:setForce(0, 0)
	self.actorSpeedController:setFriction(0)
	self:unLockOrientation()
end

function Hero_dao:leave_State_Collapse3()
	self:unLockOrientation()
end

return Hero_dao