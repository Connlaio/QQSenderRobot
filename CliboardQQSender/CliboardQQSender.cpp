// CliboardQQSender.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "CliboardQQSender.h"

namespace CliboardQQSender 
{
	extern HWND g_QQHwnd;
	extern void pushStringToClipboard(string source);
	extern void sendClipboardMessage();
}



// ���ǵ���������һ��ʾ����
CLIBOARDQQSENDER_API void send(void)
{
	CliboardQQSender::sendClipboardMessage();
}

// ���ǵ���������һ��ʾ����
CLIBOARDQQSENDER_API void setHwnd(UINT32 value)
{
	CliboardQQSender::g_QQHwnd = (HWND)value;
}