// testQQRobot.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "testQQRobot.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;


void sendStringToClipboard(HWND hwnd, CString source)
{
	if (OpenClipboard(hwnd))
	{
		HGLOBAL clipbuffer;
		char * buffer;
		EmptyClipboard();
		clipbuffer = GlobalAlloc(GMEM_DDESHARE, source.GetLength() + 1);
		buffer = (char*)GlobalLock(clipbuffer);
		strcpy_s(buffer, source.GetLength() + 1, source.GetBuffer());
		GlobalUnlock(clipbuffer);
		SetClipboardData(CF_TEXT, clipbuffer);
		CloseClipboard();
		source.ReleaseBuffer(-1);
	}
}

void sendClipboardMessage(CWnd *pwnd)
{
	keybd_event(VK_CONTROL, 0x1D, 0, 0);
	pwnd->PostMessage(WM_KEYDOWN, 0x00000056, 0x002F0001);
	Sleep(500);
	pwnd->PostMessage(WM_KEYUP, 0x00000056, 0xC02F0001);
	pwnd->PostMessage(WM_KEYDOWN, 0x0000000D, 0x001C0001);
	Sleep(500);
	pwnd->PostMessage(WM_KEYUP, 0x0000000D, 0xC01C0001);
	keybd_event(VK_CONTROL, 0x1D, KEYEVENTF_KEYUP, 0);
}


int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // ��ʼ�� MFC ����ʧ��ʱ��ʾ����
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: ���Ĵ�������Է���������Ҫ
            wprintf(L"����: MFC ��ʼ��ʧ��\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: �ڴ˴�ΪӦ�ó������Ϊ��д���롣
			HWND hw = (HWND)0x00150060;
			CWnd* pQQWnd;
			pQQWnd = CDialog::FromHandle(hw);
			sendStringToClipboard(hw, CString("����Ϣ��robot ����"));
			sendClipboardMessage(pQQWnd);
        }
    }
    else
    {
        // TODO: ���Ĵ�������Է���������Ҫ
        wprintf(L"����: GetModuleHandle ʧ��\n");
        nRetCode = 1;
    }

    return nRetCode;
}
