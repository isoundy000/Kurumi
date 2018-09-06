_MyG = {}

cc.FileUtils:getInstance():setPopupNotify(false)
cc.FileUtils:getInstance():addSearchPath("src/")
cc.FileUtils:getInstance():addSearchPath("res/")

require "config"
require "cocos.init"


local function main()
    require("app.common.PreInit")
    _MyG.APP = require("app.MyApp"):create()
    _MyG.APP:run()
end

__G__TRACKBACK__ = function(msg)
    local msg = debug.traceback(msg, 3)
    local logmsg = os.date() .. ":"..msg
    print(logmsg)

    local targetPlatform = cc.Application:getInstance():getTargetPlatform()
	if targetPlatform == cc.PLATFORM_OS_ANDROID 
	or targetPlatform == cc.PLATFORM_OS_IPHONE
	or targetPlatform == cc.PLATFORM_OS_IPAD then
    	local data = {exception = logmsg}
		_MyG.Net:sendMsgToGame("debug.C2S_luaexception", data)
	end
    return msg
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then	
end
