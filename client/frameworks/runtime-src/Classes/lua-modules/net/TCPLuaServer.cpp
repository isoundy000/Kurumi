#include "TCPLuaServer.h"

TCPLuaServer::TCPLuaServer()
{
	m_server = new net_uv::TCPServer();

	m_server->setStartCallback(CC_CALLBACK_2(TCPLuaServer::onServerStartCall, this));
	m_server->setCloseCallback(CC_CALLBACK_1(TCPLuaServer::onServerCloseCall, this));
	m_server->setNewConnectCallback(CC_CALLBACK_2(TCPLuaServer::onServerNewConnectCall, this));
	m_server->setRecvCallback(std::bind(&TCPLuaServer::onServerRecvCall, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
	m_server->setDisconnectCallback(CC_CALLBACK_2(TCPLuaServer::onServerDisconnectCall, this));

	auto scheduler = cocos2d::Director::getInstance()->getScheduler();
	scheduler->schedule(schedule_selector(TCPLuaServer::update), this, 1 / 60.0f, false);
}

TCPLuaServer::~TCPLuaServer()
{
	auto scheduler = cocos2d::Director::getInstance()->getScheduler();
	scheduler->unscheduleAllForTarget(this);

	CC_SAFE_DELETE(m_server);
}

void TCPLuaServer::startServer(const char* ip, unsigned int port, bool isIPV6)
{
	m_server->startServer(ip, port, isIPV6);
}

bool TCPLuaServer::stopServer()
{
	return m_server->stopServer();
}

void TCPLuaServer::send(net_uv::Session* session, char* data, unsigned int len)
{
	m_server->send(session, data, len);
}

void TCPLuaServer::disconnect(net_uv::Session* session)
{
	m_server->disconnect(session);
}

bool TCPLuaServer::isCloseFinish()
{
	return m_server->isCloseFinish();
}

void TCPLuaServer::update(float)
{
	m_server->updateFrame();
}

void TCPLuaServer::onServerStartCall(net_uv::Server* svr, bool success)
{
	auto handle = getLuaHandle("onServerStartCall");
	if (handle && handle->isvalid())
	{
		handle->ppush();
		handle->pushusertype(svr, "net_uv::KCPServer");
		handle->pusharg(success);
		handle->pcall();
	}
}

void TCPLuaServer::onServerCloseCall(net_uv::Server* svr)
{
	auto handle = getLuaHandle("onServerCloseCall");
	if (handle && handle->isvalid())
	{
		handle->ppush();
		handle->pushusertype(svr, "net_uv::KCPServer");
		handle->pcall();
	}
}

void TCPLuaServer::onServerNewConnectCall(net_uv::Server* svr, net_uv::Session* session)
{
	auto handle = getLuaHandle("onServerNewConnectCall");
	if (handle && handle->isvalid())
	{
		handle->ppush();
		handle->pushusertype(svr, "net_uv::KCPServer");
		handle->pushusertype(session, "net_uv::KCPSession");
		handle->pcall();
	}
}

void TCPLuaServer::onServerRecvCall(net_uv::Server* svr, net_uv::Session* session, char* data, unsigned int len)
{
	auto handle = getLuaHandle("onServerRecvCall");
	if (handle && handle->isvalid())
	{
		handle->ppush();
		handle->pushusertype(svr, "net_uv::KCPServer");
		handle->pushusertype(session, "net_uv::KCPSession");
		handle->pushlstring(data, len);
		handle->pusharg(len);
		handle->pcall();
	}
}

void TCPLuaServer::onServerDisconnectCall(net_uv::Server* svr, net_uv::Session* session)
{
	auto handle = getLuaHandle("onServerDisconnectCall");
	if (handle && handle->isvalid())
	{
		handle->ppush();
		handle->pushusertype(svr, "net_uv::KCPServer");
		handle->pushusertype(session, "net_uv::KCPSession");
		handle->pcall();
	}
}