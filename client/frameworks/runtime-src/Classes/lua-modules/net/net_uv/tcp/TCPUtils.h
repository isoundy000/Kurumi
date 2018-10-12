#pragma once

#include "TCPCommon.h"

NS_NET_UV_BEGIN

//����
NET_UV_EXTERN char* tcp_uv_encode(const char* data, unsigned int len, unsigned int &outLen);
//����
NET_UV_EXTERN char* tcp_uv_decode(const char* data, unsigned int len, unsigned int &outLen);
// �������
NET_UV_EXTERN uv_buf_t* tcp_packageData(char* data, unsigned int len, int* bufCount);
// ���������Ϣ
NET_UV_EXTERN char* tcp_packageHeartMsgData(NET_HEART_TYPE msg, unsigned int* outBufSize);

NS_NET_UV_END