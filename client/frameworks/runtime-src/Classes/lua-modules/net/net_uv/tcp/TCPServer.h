#pragma once


#include "TCPSocket.h"
#include "TCPSession.h"

NS_NET_UV_BEGIN

class NET_UV_EXTERN TCPServer : public Server
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
		TCPSession* session;
		bool isInvalid;
	};

public:

	TCPServer();
	TCPServer(const TCPServer&) = delete;

	virtual ~TCPServer();

	/// Server
	virtual void startServer(const char* ip, unsigned int port, bool isIPV6)override;

	virtual bool stopServer()override;

	virtual void updateFrame()override;

	/// SessionManager
	virtual void send(Session* session, char* data, unsigned int len)override;

	virtual void disconnect(Session* session)override;

	/// TCPServer
	bool isCloseFinish();

protected:

	/// Runnable
	virtual void run()override;

	/// SessionManager
	virtual void executeOperation()override;

	/// TCPServer
	void onNewConnect(uv_stream_t* server, int status);

	void onServerSocketClose(Socket* svr);
	
	void onSessionRecvData(Session* session, char* data, unsigned int len);

	/// Server
	virtual void onIdleRun()override;

	virtual void onSessionUpdateRun()override;
	
protected:

	void addNewSession(TCPSession* session);

	void onSessionClose(Session* session);

	void clearData();

protected:
	bool m_start;

	TCPSocket* m_server;
		
	// �����������׶�
	ServerStage m_serverStage;

	// �Ự����
	std::map<unsigned int, serverSessionData> m_allSession;

	unsigned int m_sessionID;
};



NS_NET_UV_END
