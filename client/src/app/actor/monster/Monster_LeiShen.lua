local Monster_Base = require("app.actor.monster.Monster_Base")
local Monster_Leizhu = require("app.actor.monster.Monster_Leizhu")
local Monster_Leiqiu = require("app.actor.monster.Monster_Leiqiu")

local Monster_LeiShen = class("Monster_LeiShen", Monster_Base)


local LeiShenConfig = require("app.config.monster.LeiShenConfig")

function Monster_LeiShen:ctor()
	Monster_LeiShen.super.ctor(self)
	
	self:setActorType(AT_MONSTER)

	self:loadConfig(LeiShenConfig)

	self:override_forceSwitchClean()

	self:initFSM()
	self.FSM:start("State_Stand")

	self.AI = require("app.AI.AIM_LeiShen"):new()
end

function Monster_LeiShen:onEnter()
	Monster_LeiShen.super.onEnter(self)
	if self.AI then
		self.AI:setOwner(self)
		self.AI:start()
	end
end

function Monster_LeiShen:override_loadArmature(filePath)
	changeParticleSystemPositionType(self:getArmature())
end


function Monster_LeiShen:override_updateArmatureInfo()
end

function Monster_LeiShen:override_attOtherActorCallback(otherActor)

	local stateName = self.FSM:getCurState():getStateName()

	if stateName == "State_Kill" then
		otherActor:override_beAttacked(self, true)
	else
		otherActor:override_beAttacked(self, false)
	end
end

function Monster_LeiShen:override_beAttacked(attackActor, isPickUp)
	
	Monster_LeiShen.super.override_beAttacked(self, attackActor, isPickUp)

	if not isPickUp then
		self:handle("CMD_Hit")
	else
		self:handle("CMD_Collapase_EndToStand")		
	end
end


function Monster_LeiShen:override_logicUpdate(time)
	Monster_LeiShen.super.override_logicUpdate(self, time)
	local curStateName = self.FSM:getCurState():getStateName()
	-- 奔跑状态
	if curStateName == "State_Run" then
		if self.startMoveCMD then
			self:setVelocityXByImpulse(self:getVelocityByMoveOrientation(LeiShenConfig.BaseConfig.MoveVelocity))
		else
			self:clearForceX()
		end
	end
end

--------------------------------------Logic--------------------------------------
function Monster_LeiShen:getVelocityByMoveOrientation(value)
	if self.moveToLeft then
		return -value
	end
	return value
end

function Monster_LeiShen:moveLeft()
	self.startMoveCMD = true
	self.moveToLeft = true
	local ret = self:handle("CMD_MoveStart")
	return ret
end

function Monster_LeiShen:moveRight()
	self.startMoveCMD = true
	self.moveToLeft = false
	local ret = self:handle("CMD_MoveStart")
	return ret
end

function Monster_LeiShen:moveStop()
	self.startMoveCMD = false
	self:clearForceX()
	local ret = self:handle("CMD_MoveStand")
	return ret
end

function Monster_LeiShen:skill1()
	local ret = self:handle("CMD_Skill1")
	return ret
end

function Monster_LeiShen:skill2()
	local ret = self:handle("CMD_Kill2")
	return ret
end

function Monster_LeiShen:skill3()
	local ret = self:handle("CMD_Kill3")
	if ret then
		local call = cc.CallFunc:create(function()
			self:handle("CMD_Kill3_Finish")
		end)

		self:getArmature():stopAllActions()
		local q = cc.Sequence:create(cc.DelayTime:create(2.0), call)
		self:getArmature():runAction(q)
	end
	return ret
end

function Monster_LeiShen:skill5(endPos)
	local ret = self:handle("CMD_Kill5_1")
	if ret then
		self.skill5EndPos = endPos
	end
	return ret
end

function Monster_LeiShen:skill6()
	local ret = self:handle("CMD_Kill6")
	if ret then
		local callfunc = cc.CallFunc:create(function()
			self:handle("CMD_Kill6_Finish")
		end)

		local q = cc.Sequence:create(cc.DelayTime:create(0.6), callfunc)
		self:getArmature():stopAllActions()
		self:getArmature():runAction(q)
	end
	return ret
end

--------------------------------------------FSM--------------------------------

function Monster_LeiShen:initFSM()

	--站立
	self.FSM:addTranslation("State_Run", "CMD_MoveStand", "State_Brake")

	self.FSM:addTranslation("State_Brake", "State_Brake_stop", "State_Stand")

	--移动
	self.FSM:addTranslation("State_Stand", "CMD_MoveStart", "State_Run")
	self.FSM:addTranslation("State_Brake", "CMD_MoveStart", "State_Run")

	--skill1
	self.FSM:addTranslation("State_Stand", "CMD_Skill1", "State_Kill1")
	self.FSM:addTranslation("State_Run", "CMD_Skill1", "State_Kill1")
	self.FSM:addTranslation("State_Brake", "CMD_Skill1", "State_Kill1")
	self.FSM:addTranslation("State_Kill1", "State_Kill1_stop", "State_Stand")

	--skill2
	self.FSM:addTranslation("State_Stand", "CMD_Kill2", "State_Kill2")
	self.FSM:addTranslation("State_Run", "CMD_Kill2", "State_Kill2")
	self.FSM:addTranslation("State_Brake", "CMD_Kill2", "State_Kill2")
	self.FSM:addTranslation("State_Kill2", "State_Kill2_stop", "State_Stand")

	--skill3
	self.FSM:addTranslation("State_Stand", "CMD_Kill3", "State_Kill3")
	self.FSM:addTranslation("State_Run", "CMD_Kill3", "State_Kill3")
	self.FSM:addTranslation("State_Brake", "CMD_Kill3", "State_Kill3")
	self.FSM:addTranslation("State_Kill3", "CMD_Kill3_Finish", "State_Stand")

	--skill5
	self.FSM:addTranslation("State_Stand", "CMD_Kill5_1", "State_Kill5_1")
	self.FSM:addTranslation("State_Run", "CMD_Kill5_1", "State_Kill5_1")
	self.FSM:addTranslation("State_Brake", "CMD_Kill5_1", "State_Kill5_1")
	self.FSM:addTranslation("State_Hit", "CMD_Kill5_1", "State_Kill5_1")
	self.FSM:addTranslation("State_Kill5_1", "State_Kill5_1_stop", "State_Kill5_2")
	self.FSM:addTranslation("State_Kill5_2", "State_Kill5_2_stop", "State_Stand")

	--skill6
	self.FSM:addTranslation("State_Stand", "CMD_Kill6", "State_Kill6_Begin")
	self.FSM:addTranslation("State_Run", "CMD_Kill6", "State_Kill6_Begin")
	self.FSM:addTranslation("State_Brake", "CMD_Kill6", "State_Kill6_Begin")
	self.FSM:addTranslation("State_Hit", "CMD_Kill6", "State_Kill6_Begin")
	self.FSM:addTranslation("State_Kill6_Begin", "State_Kill6_Begin_stop", "State_Kill6_Run")
	self.FSM:addTranslation("State_Kill6_Begin", "CMD_Kill6_Finish", "State_Kill6_Finish")
	self.FSM:addTranslation("State_Kill6_Run", "CMD_Kill6_Finish", "State_Kill6_Finish")
	self.FSM:addTranslation("State_Kill6_Finish", "State_Kill6_Finish_stop", "State_Stand")

	--受到攻击
	self.FSM:addTranslation("State_Stand", "CMD_Hit", "State_Hit")
	self.FSM:addTranslation("State_Run", "CMD_Hit", "State_Hit")
	self.FSM:addTranslation("State_Brake", "CMD_Hit", "State_Hit")
	self.FSM:addTranslation("State_Kill6_Begin", "CMD_Hit", "State_Hit")
	self.FSM:addTranslation("State_Kill6_Finish", "CMD_Hit", "State_Hit")
	self.FSM:addTranslation("State_Turn", "CMD_Hit", "State_Hit")
	self.FSM:addTranslation("State_Hit", "State_Hit_stop", "State_Stand")

	--受到攻击并被击飞
	self.FSM:addTranslation("State_Stand", "CMD_Collapase_EndToStand", "State_Collapase_EndToStand")
	self.FSM:addTranslation("State_Run", "CMD_Collapase_EndToStand", "State_Collapase_EndToStand")
	self.FSM:addTranslation("State_Brake", "CMD_Collapase_EndToStand", "State_Collapase_EndToStand")
	self.FSM:addTranslation("State_Kill6_Begin", "CMD_Collapase_EndToStand", "State_Collapase_EndToStand")
	self.FSM:addTranslation("State_Kill6_Finish", "CMD_Collapase_EndToStand", "State_Collapase_EndToStand")
	self.FSM:addTranslation("State_Turn", "CMD_Collapase_EndToStand", "State_Collapase_EndToStand")

	self.FSM:addTranslation("State_Collapase_EndToStand", "State_Collapase_EndToStand_stop", "State_Stand")
end

--强制切换清理
function Monster_LeiShen:override_forceSwitchClean()
	Monster_LeiShen.super.override_forceSwitchClean(self)
	
	if self.b2Body then
		self:clearForceXY()
	end

	local armature = self:getArmature()
	if armature then
		armature:setPosition({x = 0, y = 0})
		armature:stopAllActions()
	end
end

function Monster_LeiShen:enter_State_Stand()
	self:clearForceX()
end

function Monster_LeiShen:enter_State_Run()
	self:clearForceX()
end

function Monster_LeiShen:leave_State_Run()
	self:clearForceX()
end

function Monster_LeiShen:enter_State_Hit()
	self:lockOrientation()
	self:clearForceX()
	--
	local impluse = self:getVelocityByOrientation(LeiShenConfig.BaseConfig.HitImpluse)
	self:setVelocityXByImpulse(impluse)
end

function Monster_LeiShen:leave_State_Hit()
	self:unLockOrientation()
	self:clearForceX()
end

function Monster_LeiShen:enter_State_Kill1()
	self:lockOrientation()
end

function Monster_LeiShen:leave_State_Kill1()
	self:unLockOrientation()

	local qiu = Monster_Leiqiu:create()
	getGameWord():addActor(qiu)

	if self:getOrientation() == GAME_ORI_LEFT then
		qiu:start(200)
		qiu:setOrientation(GAME_ORI_LEFT)
		qiu:setPosition({x = self:getPositionX() - 20, y = 0})
	else
		qiu:start(200)
		qiu:setOrientation(GAME_ORI_RIGHT)
		qiu:setPosition({x = self:getPositionX() + 20, y = 0})
	end
end

function Monster_LeiShen:enter_State_Kill2()
	self:lockOrientation()
end

function Monster_LeiShen:leave_State_Kill2()
	self:unLockOrientation()
end

function Monster_LeiShen:enter_State_Kill3()
	self:lockOrientation()
end

function Monster_LeiShen:leave_State_Kill3()
	self:unLockOrientation()
end

function Monster_LeiShen:enter_State_Kill4()
	self:lockOrientation()
end

function Monster_LeiShen:leave_State_Kill4()
	self:unLockOrientation()
end

function Monster_LeiShen:enter_State_Kill5_1()
	self:lockOrientation()
end

function Monster_LeiShen:leave_State_Kill5_1()
	self:unLockOrientation()

	if self.skill5EndPos == nil then
		local movex = math.random(200, 1000)
		if math.random(1, 2) == 1 then
			movex = -movex
		end
		self.skill5EndPos = movex
	end

	self:setActorPositionInValidRect({x = self.skill5EndPos, y = self:getPositionY()})
	self.skill5EndPos = nil
end

function Monster_LeiShen:enter_State_Kill5_2()
	self:lockOrientation()
end

function Monster_LeiShen:leave_State_Kill5_2()
	self:unLockOrientation()
end

function Monster_LeiShen:enter_State_Kill6_Begin()
	self:lockOrientation()
end

function Monster_LeiShen:leave_State_Kill6_Begin()
	self:unLockOrientation()

	local zhu = Monster_Leizhu:create()
	zhu:setActorPositionInValidRect({x = self:getPositionX(), y = 0})
	zhu:setOrientation(self:getOrientation())
	zhu:startRun()
	getGameWord():addActor(zhu)
end

function Monster_LeiShen:enter_State_Kill6_Run()
	self:lockOrientation()
end

function Monster_LeiShen:leave_State_Kill6_Run()
	self:unLockOrientation()
end

return Monster_LeiShen