#pragma once

#include "cocos2d.h"
#include "tcp/TCPClient.h"
#include "lua_function/LuaFunction.h"
#include "lua_function/LuaFunctionBond.h"

class TCPLuaClient : public cocos2d::Ref, public LuaFunctionBond
{
	static TCPLuaClient* Instance;

	TCPLuaClient();
	~TCPLuaClient();
public:

	static TCPLuaClient* getInstance();

	static void destroy();

	void connect(const char* ip, unsigned int port, unsigned int sessionId);

	void disconnect(unsigned int sessionId);

	void closeClient();

	void send(unsigned int sessionId, char* data, unsigned int len);

	void removeSession(unsigned int sessionId);

	void send(Session* session, char* data, unsigned int len);

	void disconnect(Session* session);

	bool isCloseFinish();

	//�Ƿ�����TCP_NODELAY
	bool setSocketNoDelay(bool enable);

	//��������
	bool setSocketKeepAlive(int enable, unsigned int delay);

	//��������socket�Ƿ��Զ�����
	void setAutoReconnect(bool isAuto);

	//��������socket�Զ�����ʱ��(��λ��S)
	void setAutoReconnectTime(float time);

	//�Ƿ��Զ�����
	void setAutoReconnectBySessionID(unsigned int sessionID, bool isAuto);

	//�Զ�����ʱ��(��λ��S)
	void setAutoReconnectTimeBySessionID(unsigned int sessionID, float time);

	inline TCPClient* getTCPClient();

protected:

	void update(float);

	void onClientConnectCall(Client* client, Session* session, int status);

	void onClientDisconnectCall(Client* client, Session* session);

	void onClientRecvCall(Client* client, Session* session, char* data, unsigned int len);

	void onClientCloseCall(Client* client);

	void onClientRemoveSessionCall(Client* client, Session* session);

protected:

	TCPClient* m_client;
};

TCPClient* TCPLuaClient::getTCPClient()
{
	return m_client;
}

