#pragma once

#include "TCPCommon.h"

NS_NET_UV_BEGIN

//����
char* tcp_uv_encode(const char* data, unsigned int len, unsigned int &outLen);
//����
char* tcp_uv_decode(const char* data, unsigned int len, unsigned int &outLen);
// �������
uv_buf_t* tcp_packageData(char* data, unsigned int len, int* bufCount);
// ���������Ϣ
char* tcp_packageHeartMsgData(NET_HEART_TYPE msg, unsigned int* outBufSize);

NS_NET_UV_END