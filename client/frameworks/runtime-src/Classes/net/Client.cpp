#include "Client.h"


Client* Client::Instance = NULL;

void tcp_com_log_func(const char* log)
{
	CCLOG("%s", log);
}

Client* Client::getInstance()
{
	if (Instance == NULL)
	{
		setUVLogPrintFunc(tcp_com_log_func);
		Instance = new Client();
	}
	return Instance;
}

void Client::destroy()
{
	if (Instance)
	{
		delete Instance;
		Instance = NULL;
	}
}

Client::Client()
{
	m_luaHandleInvalid = false;
	m_client = new TCPClient();

	auto scheduler = cocos2d::Director::getInstance()->getScheduler();
	scheduler->schedule(schedule_selector(Client::update), this, 1 / 60.0f, false);
}

Client::~Client()
{
	auto scheduler = cocos2d::Director::getInstance()->getScheduler();
	scheduler->unscheduleAllForTarget(this);

	delete m_client;
}

void Client::setCallFunc(const netClientCallFunc& func)
{
	m_func = func;
}

void Client::setCallFunc(const LuaFunction& handle)
{
	m_luaHandle = handle;
	m_luaHandleInvalid = true;
}

//��ʼ����
bool Client::connect(const char* ip, int port, unsigned int key)
{
	return m_client->connect(ip, port, key);
}

void Client::disconnect(unsigned int key)
{
	m_client->disconnect(key);
}

//�رտͻ��ˣ����ô˺���֮��ͻ��˽�׼���˳��̣߳���������������ͳͳ�޷�����
void Client::closeClient()
{
	m_client->closeClient();
}

//��ѯ�ͻ����Ƿ��Ѿ��ر����
//�������true������Խ��и�����ڴ��ͷ�
//������false�ͽ����ڴ��ͷ�ʱ�����ཫ�������߳���ȫ�˳�
bool Client::isCloseFinish()
{
	return m_client->isCloseFinish();
}

bool Client::send(unsigned int key, char* data, unsigned int len)
{
	return m_client->send(key, data, len, TCPMsgTag::MT_DEFAULT);
}

bool Client::send(unsigned int key, char* data)
{
	return m_client->send(key, data, strlen(data), TCPMsgTag::MT_DEFAULT);
}

//�Ƿ�����TCP_NODELAY
bool Client::setNoDelay(bool enable)
{
	return m_client->setSocketNoDelay(enable);
}

//��������
bool Client::setKeepAlive(int enable, unsigned int delay)
{
	return m_client->setSocketKeepAlive(enable, delay);
}

TCPSocket* Client::getSocketByKey(unsigned int key)
{
	return m_client->getSocketByKey(key);
}

TCPClient::CONNECTSTATE Client::checkState(unsigned int key)
{
	return m_client->checkState(key);
}

TCPClient::CONNECTSTATE Client::checkState(const char* ip, unsigned int port)
{
	return m_client->checkState(ip, port);
}

//��������socket�Ƿ��Զ�����
void Client::setAutoReconnect(bool isAuto)
{
	m_client->setAutoReconnect(isAuto);
}

//��������socket�Զ�����ʱ��(��λ��S)
void Client::setAutoReconnectTime(float time)
{
	m_client->setAutoReconnectTime(time);
}

//�Ƿ��Զ�����
void Client::setAutoReconnectByKey(unsigned int key, bool isAuto)
{
	m_client->setAutoReconnectByKey(key, isAuto);
}

//�Զ�����ʱ��(��λ��S)
void Client::setAutoReconnectTimeByKey(unsigned int key, float time)
{
	m_client->setAutoReconnectTimeByKey(key, time);
}


void Client::update(float)
{
	m_client->getAllThreadMsg(&m_threadMsg);
	if (!m_threadMsg.empty())
	{
		if (m_func)
		{
			for (auto& it : m_threadMsg)
			{
				m_func(it);
			}
		}

		if (m_luaHandleInvalid)
		{
			for (auto& msg : m_threadMsg)
			{
				switch (msg.msgType)
				{
				case CONNECT_FAIL:	//����ʧ��
				{
					UV_LOG("uv CONNECT_FAIL");
					m_luaHandle("fail", msg.key);
				}break;
				case CONNECT_ING:	//��������
				{
					UV_LOG("uv CONNECT_ING");
					m_luaHandle("connecting", msg.key);
				}break;
				case CONNECT:		//���ӳɹ�
				{
					UV_LOG("uv CONNECT");
					m_luaHandle("connect", msg.key);
				}break;
				case DIS_CONNECT:	//�Ͽ�����
				{
					UV_LOG("uv DIS_CONNECT");
					m_luaHandle("disconnect", msg.key);
				}break;
				case EXIT_LOOP:		//�˳�loop
				{
					UV_LOG("uv EXIT_LOOP");
					m_luaHandle("loop exit");
				}break;
				case RECV_DATA:		//�յ���Ϣ
				{
					//UV_LOG("uv RECV_DATA");
					if (msg.tag == TCPMsgTag::MT_DEFAULT)
					{

						m_luaHandle.ppush();
						m_luaHandle.pusharg("recv");
						m_luaHandle.pushlstring((const char*)msg.data, (unsigned int)msg.dataLen);
						m_luaHandle.pcall();
					}
				}break;
				default:
					break;
				}
			}
		}

		for (auto& it : m_threadMsg)
		{
			fc_free(it.data);
		}
	}
}