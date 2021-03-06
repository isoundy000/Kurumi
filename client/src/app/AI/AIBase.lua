local AIBase = class("AIBase")

function AIBase:ctor()
	print("AIBase:ctor()")
	self.curAITime = 0.0
	self.owner = nil
	self.enemy = nil
	self.disEventList = {}
	self:setAIEnable(true)

	local scheduler=cc.Director:getInstance():getScheduler()
    self.preInitScriptEntryID = scheduler:scheduleScriptFunc(function(...) self:override_AIPreInit(...) end,1 / 10.0,false)
end

function AIBase:registerAll()
	if _MyG.DEBUG then
		self:register("control_1")
		self:register("control_2")
		self:register("control_3")
		self:register("control_4")
		self:register("control_5")
		self:register("control_6")
		self:register("control_7")
		self:register("control_8")
		self:register("control_9")
	end
end

function AIBase:register(key)
	local func = function(...) 
		if self["dis_"..key] then
			self["dis_"..key](self, ...)
		end
	end
	_MyG.PlayerDispatcher:register(key, func)
	self.disEventList[key] = func
end

function AIBase:unRegisterAll()
	for k,v in pairs(self.disEventList) do
		_MyG.PlayerDispatcher:unRegister(k, v)
	end	
	self.disEventList = {}
end

function AIBase:setAIEnable(enable)
	self.isAIEnable = enable
end

function AIBase:start()
	-- print("AIBase:start")
	if self.owner == nil then
		print("ERROR:[owner 未设置]")
		return false
	end

	self.isStart = true

	if self.preInit then
		self:stop()
		self:registerAll()

		local scheduler=cc.Director:getInstance():getScheduler()
    	self.scriptEntryID = scheduler:scheduleScriptFunc(function(...) self:override_AIUpdate(...) end,1 / 20.0,false)
	end

	return true
end

function AIBase:stop()
	self:unRegisterAll()
	if self.scriptEntryID ~= nil then
		local scheduler=cc.Director:getInstance():getScheduler()
		scheduler:unscheduleScriptEntry(self.scriptEntryID)
	end
	self.scriptEntryID = nil
end

function AIBase:override_Exit()
	if self.scriptEntryID ~= nil then
		assert(0)
		print("ERROR:[AIBase 定时器未停止]")
	end
	self:stop()

	if self.preInitScriptEntryID then
		local scheduler=cc.Director:getInstance():getScheduler()
		scheduler:unscheduleScriptEntry(self.preInitScriptEntryID)
		self.preInitScriptEntryID = nil
	end
end

function AIBase:override_AIPreInit()
	self.preInit = true

	local scheduler=cc.Director:getInstance():getScheduler()
	if self.preInitScriptEntryID then
		scheduler:unscheduleScriptEntry(self.preInitScriptEntryID)
		self.preInitScriptEntryID = nil
	end

	if self.isStart then
		self:start()
	end
end

function AIBase:override_AIUpdate(time)
end

function AIBase:setOwner(InOwner)
	self.owner = InOwner
	if InOwner == nil then
		self:stop()
	end
end

function AIBase:getValueByWigetData(wigetData)
	local totalWeight = 0
	for k,v in pairs(wigetData) do
		totalWeight = totalWeight + v
	end
	local randNum = math.random(1, totalWeight)
	totalWeight = 0
	for k,v in pairs(wigetData) do
		totalWeight = totalWeight + v
		if randNum <= totalWeight then
			return k
		end
	end
	print("[ERROR]: getValueByWigetData")
	for k,v in pairs(table_name) do
		print(k,v)
	end
	print("[ERROR] end\n\n")
	return nil
end

return AIBase



