#pragma once

#include "TCPSocket.h"
#include "TCPSession.h"

NS_NET_UV_BEGIN

class NET_UV_EXTERN TCPClient : public Client
{
protected:
	enum CONNECTSTATE
	{
		CONNECT,		//������
		CONNECTING,		//��������
		DISCONNECTING,	//���ڶϿ�
		DISCONNECT,		//�ѶϿ�
	};

	struct clientSessionData
	{
		clientSessionData() {}
		~clientSessionData() {}
		CONNECTSTATE connectState;
		bool removeTag; // �Ƿ񱻱���Ƴ�
		bool reconnect;	// �Ƿ��������
		float curtime;
		float totaltime;
		std::string ip;
		unsigned int port;
		TCPSession* session;
	};

	//�ͻ��������׶�
	enum class clientStage
	{
		START,
		CLEAR_SESSION,//����Ự
		WAIT_EXIT,//�����˳�
		STOP
	};
public:

	TCPClient();
	TCPClient(const TCPClient&) = delete;
	virtual ~TCPClient();

	/// Client
	virtual void connect(const char* ip, unsigned int port, unsigned int sessionId)override;

	virtual void disconnect(unsigned int sessionId)override;

	virtual void closeClient()override;
	
	virtual void updateFrame()override;

	virtual void send(unsigned int sessionId, char* data, unsigned int len)override;

	virtual void removeSession(unsigned int sessionId)override;

	/// SessionManager
	virtual void send(Session* session, char* data, unsigned int len)override;

	virtual void disconnect(Session* session)override;

	/// TCPClient
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

protected:

	/// Runnable
	virtual void run()override;

	/// SessionManager
	virtual void executeOperation()override;

	/// Client
	virtual void onIdleRun()override;

	virtual void onSessionUpdateRun()override;

	/// TCPClient
	void onSocketConnect(Socket* socket, int status);

	void onSessionClose(Session* session);

	void onSessionRecvData(Session* session, char* data, unsigned int len);

	void createNewConnect(void* data);

	void clearData();

	clientSessionData* getClientSessionDataBySessionId(unsigned int sessionId);

	clientSessionData* getClientSessionDataBySession(Session* session);

	void onClientUpdate();

protected:
	uv_timer_t m_clientUpdateTimer;

	bool m_reconnect;		// �Ƿ��Զ���������
	float m_totalTime;		// ��������ʱ��
	bool m_enableNoDelay;	
	int m_enableKeepAlive; 
	int m_keepAliveDelay;

	// ���лỰ
	std::map<unsigned int, clientSessionData*> m_allSessionMap;
	
	clientStage m_clientStage;
	bool m_isStop;
protected:

	static void uv_client_update_timer_run(uv_timer_t* handle);
};
NS_NET_UV_END


