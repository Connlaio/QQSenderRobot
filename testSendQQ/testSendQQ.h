
// testSendQQ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

// CtestSendQQApp: 
// �йش����ʵ�֣������ testSendQQ.cpp
//

class CtestSendQQApp : public CWinApp
{
public:
	CtestSendQQApp();
// ��д
public:
	virtual BOOL InitInstance();
// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CtestSendQQApp theApp;