_MyG = {}

require("lua_code.utils.functions")

OPEN_DEBUG = 1

local function main()
	json = require("lua_code.utils.json")
    require("lua_code.utils.tools")
    require("lua_code.net.registerMsg")

    _MyG.NetMsgDispatcher = require("lua_code.utils.dispatcher"):new()
    _MyG.PlayerManager = require("lua_code.players.playerManager"):new()

    local clients = {}
    local sendMsg = ""

    local server = DUServer:new()
    server:startServer("0.0.0.0", 1234)
    server:setCallFunc(function(msgtype, client, msgdata)
    	if msgtype == "recv" then
            local msgName, msgTab = recvMsg(msgdata)
            _MyG.NetMsgDispatcher:call(msgName, client, msgTab)
    	elseif msgtype == "connect" then
            _MyG.PlayerManager:connectToServer(client)
    	elseif msgtype == "disconnect" then
            _MyG.PlayerManager:disconnectToServer(client)
    	elseif msgtype == "loopexit" then
    		print("loopexit")
    	end
    end)

    local obj = TestOBJ:new()
    obj:Test()
    -- obj:delete()
    obj = nil

    local time = 0.0
    local scheduKey = DUScheduler:getInstance():registerScripSchedule(function(dt)
        time = time + dt
        print(time)
        collectgarbage("collect")
        if time >= 10.0 then
            print(scheduKey)
            DUScheduler:getInstance():unRegisterScripSchedule(scheduKey)
        end
    end, 1.0, false)
    print("scheduKey = ", scheduKey)
end




__G__TRACKBACK__ = function(msg)
    local msg = debug.traceback(msg, 3)
    local logmsg = os.date() .. ":"..msg
    print(logmsg)
    return msg
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
end