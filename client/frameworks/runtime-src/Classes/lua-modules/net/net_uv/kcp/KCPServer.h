#pragma once


#include "KCPSocket.h"
#include "KCPSession.h"

NS_NET_UV_BEGIN

class NET_UV_EXTERN KCPServer : public Server
{
	//�����������׶�
	enum class ServerStage
	{
		START,		//������
		RUN,		//������
		WAIT_CLOSE_SERVER_SOCKET,// �ȴ��������׽��ֹر�
		CLEAR,		//����Ự
		WAIT_SESSION_CLOSE,// �ȴ��Ự�ر�
		STOP		//�˳�
	};

	struct serverSessionData
	{
		serverSessionData()
		{
			isInvalid = false;
			session = NULL;
		}
		KCPSession* session;
		bool isInvalid;
	};

public:

	KCPServer();
	KCPServer(const KCPServer&) = delete;

	virtual ~KCPServer();

	/// Server
	virtual void startServer(const char* ip, unsigned int port, bool isIPV6)override;

	virtual bool stopServer()override;

	virtual void updateFrame()override;

	/// SessionManager
	virtual void send(Session* session, char* data, unsigned int len)override;

	virtual void disconnect(Session* session)override;

	/// KCPServer
	bool isCloseFinish();

protected:

	/// Runnable
	virtual void run()override;

	/// SessionManager
	virtual void executeOperation()override;

	/// KCPServer
	void onNewConnect(Socket* socket);

	void onServerSocketClose(Socket* svr);

	bool onServerSocketConnectFilter(const struct sockaddr* addr);

	void onSessionRecvData(Session* session, char* data, unsigned int len);

	/// Server
	virtual void onIdleRun()override;

	virtual void onSessionUpdateRun()override;

protected:

	void addNewSession(KCPSession* session);

	void onSessionClose(Session* session);

	void clearData();

protected:
	bool m_start;

	KCPSocket* m_server;

	// �����������׶�
	ServerStage m_serverStage;

	// �Ự����
	std::map<unsigned int, serverSessionData> m_allSession;
};



NS_NET_UV_END
