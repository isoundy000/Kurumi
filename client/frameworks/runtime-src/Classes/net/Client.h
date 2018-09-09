#pragma once

#include "cocos2d.h"
#include "tcpSocket/TCPClient.h"
#include "lua_function/LuaFunction.h"

typedef std::function<void(const ThreadMsg_C&)> netClientCallFunc;

class Client : public cocos2d::Ref
{
	static Client* Instance;

	Client();
	~Client();
public:

	static Client* getInstance();

	static void destroy();

	void setCallFunc(const netClientCallFunc& func);

	void setCallFunc(const LuaFunction& handle);

	//��ʼ����
	bool connect(const char* ip, int port, unsigned int key);

	void disconnect(unsigned int key);

	//�رտͻ��ˣ����ô˺���֮��ͻ��˽�׼���˳��̣߳���������������ͳͳ�޷�����
	void closeClient();
	//��ѯ�ͻ����Ƿ��Ѿ��ر����
	//�������true������Խ��и�����ڴ��ͷ�
	//������false�ͽ����ڴ��ͷ�ʱ�����ཫ�������߳���ȫ�˳�
	bool isCloseFinish();

	bool send(unsigned int key, char* data, unsigned int len);

	bool send(unsigned int key, char* data);

	//�Ƿ�����TCP_NODELAY
	bool setNoDelay(bool enable);

	//��������
	bool setKeepAlive(int enable, unsigned int delay);

	TCPSocket* getSocketByKey(unsigned int key);

	TCPClient::CONNECTSTATE checkState(unsigned int key);

	TCPClient::CONNECTSTATE checkState(const char* ip, unsigned int port);

	//��������socket�Ƿ��Զ�����
	void setAutoReconnect(bool isAuto);

	//��������socket�Զ�����ʱ��(��λ��S)
	void setAutoReconnectTime(float time);

	//�Ƿ��Զ�����
	void setAutoReconnectByKey(unsigned int key, bool isAuto);

	//�Զ�����ʱ��(��λ��S)
	void setAutoReconnectTimeByKey(unsigned int key, float time);

protected:

	void update(float);

protected:

	TCPClient* m_client;
	netClientCallFunc m_func;
	std::vector<ThreadMsg_C> m_threadMsg;

	LuaFunction m_luaHandle;
	bool m_luaHandleInvalid;
};
