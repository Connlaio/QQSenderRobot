// CliboardQQSender.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "CliboardQQSender.h"

namespace CliboardQQSender 
{
	extern void pushStringToClipboard(HWND hwnd,string source);
	extern void sendClipboardMessage(HWND hwnd);
}



// ���ǵ���������һ��ʾ����
CLIBOARDQQSENDER_API void Send(HWND value)
{
	CliboardQQSender::sendClipboardMessage(value);
}