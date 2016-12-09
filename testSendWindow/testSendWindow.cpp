// testSendWindow.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
HWND iResult = NULL;
BOOL __stdcall enumWindow(HWND hwnd, LPARAM args)
{
	HWND f1 = FindWindowEx(hwnd, 0, NULL, (LPCTSTR)args);
	if (f1 == NULL)
		return true;
	else
	{
		iResult = f1;
		return false;
	}
}
HWND MyFindWindowEx(HWND hwnd, LPCTSTR lpszWindow, bool bChild);
int main()
{
	HMODULE   hDllInst = LoadLibrary(_T("ClipboardQQSender.dll"));
	if (hDllInst)
	{
		typedef   VOID(  *SENDFUNC)(HWND);
		SENDFUNC Paste = NULL;   //   youFuntionNameAlias   �������� 
		Paste = (SENDFUNC)GetProcAddress
			(hDllInst, "Paste");
		//   youFuntionName   ��DLL�������ĺ����� 
		if (Paste)
		{
			//Paste((HWND)724026);
		}

		
		//PostMessage((HWND)724026, WM_IME_CHAR, (LPARAM)_T('��'), 0);
		//PostMessage((HWND)724026, WM_IME_CHAR, (LPARAM)_T('��'), 0);
		Sleep(200);
		//keybd_event(VK_MENU, 0x38, 0, 0);
		PostMessage((HWND)724026, WM_SYSKEYDOWN, VK_MENU, 0x20380001);
		PostMessage((HWND)724026, WM_SYSKEYDOWN, 0x53, 0x201F0001);
		Sleep(200);
		//PostMessage((HWND)724026, WM_SYSCHAR, 0x73, 0x201F0001);
		PostMessage((HWND)724026, WM_SYSKEYUP, 0x53, 0xC01F0001);
		Sleep(200);
		PostMessage((HWND)724026, WM_KEYUP, VK_MENU, 0xC0380001);
		//keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
		//SendMessage((HWND)724026, WM_CHAR, 10, 0x011C0001);
		//PostMessage((HWND)724026, WM_SYSKEYUP, 0x53, 0x201F0001);
		//SendMessage((HWND)724026, WM_KEYUP, VK_CONTROL, 0x011D0001);

		/*
		SENDFUNC submit = (SENDFUNC)GetProcAddress
			(hDllInst, "Sumbit");
		if (submit)
		{
			submit((HWND)724026);
		}
		*/
		FreeLibrary(hDllInst);
	}
	//SendMessage((HWND)0x140BA6, WM_SETTEXT, NULL, (LPARAM)_T("����"));
	//MyFindWindowEx((HWND)0x140BA6, _T("Edit"), TRUE);
	//HWND EditNumHwnd = ::FindWindowEx((HWND)0x140BA6, NULL, NULL, _T("QQEdit"));
	//PostMessage((HWND)0x140BA6, WM_KEYDOWN, VK_RETURN, 0);
	//EnumChildWindows((HWND)0x7043E, enumWindow, 0);
	return 0;
}
/// <summary>
/// ���Ҵ����Ͽؼ����
/// </summary>
/// <param name="hwnd">��������</param>
/// <param name="lpszWindow">�ؼ�����(Text)</param>
/// <param name="bChild">�趨�Ƿ����Ӵ����в���</param>
/// <returns>�ؼ������û�ҵ�����IntPtr.Zero</returns>
HWND MyFindWindowEx(HWND hwnd, LPCTSTR lpszWindow, bool bChild)
{
	// �����ڸ������ϲ��ҿؼ�
	iResult = FindWindowEx(hwnd, 0, NULL, lpszWindow);
	// ����ҵ�ֱ�ӷ��ؿؼ����
	if (iResult != NULL) return iResult;

	// ����趨�˲����Ӵ����в���
	if (!bChild) return iResult;

	// ö���Ӵ��壬���ҿؼ����
	int i = EnumChildWindows(
		hwnd,
		enumWindow,
		(LPARAM)lpszWindow);
	// ���ز��ҽ��
	return iResult;
}



