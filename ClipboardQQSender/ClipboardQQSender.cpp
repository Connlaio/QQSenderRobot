// CliboardQQSender.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "ClipboardQQSender.h"

namespace ClipboardQQSender 
{
	extern void pushStringToClipboard(HWND hwnd, string source);
	extern void sendClipboard(HWND hwnd);
	extern void sendClipboardln(HWND hwnd);
	extern void sendClipboardAndSumbit(HWND hwnd);
	extern void sendVoid(HWND hwnd);
	extern void sendReturn(HWND hwnd);
	extern void sendSumbit(HWND hwnd);
	extern void sendSumbit2(HWND hwnd);
}

// ���ǵ���������һ��ʾ����
CLIPBOARDQQSENDER_API void Paste(HWND value)
{
	ClipboardQQSender::sendClipboard(value);
}

// ���ǵ���������һ��ʾ����
CLIPBOARDQQSENDER_API void Pasteln(HWND value)
{
	ClipboardQQSender::sendClipboardln(value);
}

// ���ǵ���������һ��ʾ����
CLIPBOARDQQSENDER_API void PasteAndSumbit(HWND value)
{
	ClipboardQQSender::sendClipboardAndSumbit(value);
}

// ���ǵ���������һ��ʾ����
CLIPBOARDQQSENDER_API void Heartbeat(HWND value)
{
	ClipboardQQSender::sendVoid(value);
}

CLIPBOARDQQSENDER_API void Return(HWND value) 
{
	ClipboardQQSender::sendReturn(value);
}

// ���ǵ���������һ��ʾ����
CLIPBOARDQQSENDER_API void Sumbit(HWND value)
{
	ClipboardQQSender::sendSumbit(value);
}

CLIPBOARDQQSENDER_API void Sumbit2(HWND value)
{
	ClipboardQQSender::sendSumbit2(value);
}