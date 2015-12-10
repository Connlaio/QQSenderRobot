// CliboardQQSender.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "CliboardQQSender.h"

namespace CliboardQQSender 
{
	extern void pushStringToClipboard(HWND hwnd, string source);
	extern void sendClipboard(HWND hwnd);
	extern void sendClipboardln(HWND hwnd);
	extern void sendClipboardAndSumbit(HWND hwnd);
	extern void sendSumbit(HWND hwnd);
}

// ���ǵ���������һ��ʾ����
CLIBOARDQQSENDER_API void Paste(HWND value)
{
	CliboardQQSender::sendClipboard(value);
}

// ���ǵ���������һ��ʾ����
CLIBOARDQQSENDER_API void Pasteln(HWND value)
{
	CliboardQQSender::sendClipboardln(value);
}

// ���ǵ���������һ��ʾ����
CLIBOARDQQSENDER_API void PasteAndSumbit(HWND value)
{
	CliboardQQSender::sendClipboardAndSumbit(value);
}

// ���ǵ���������һ��ʾ����
CLIBOARDQQSENDER_API void Sumbit(HWND value)
{
	CliboardQQSender::sendSumbit(value);
}