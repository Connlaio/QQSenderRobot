
// testSendQQDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "testSendQQ.h"
#include "testSendQQDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CtestSendQQDlg �Ի���



CtestSendQQDlg::CtestSendQQDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTSENDQQ_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestSendQQDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtestSendQQDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()

void sendStringToClipboard(HWND hwnd,CString source)
{
	if (OpenClipboard(hwnd))
	{
		HGLOBAL clipbuffer;
		char * buffer;
		EmptyClipboard();
		clipbuffer = GlobalAlloc(GMEM_DDESHARE, source.GetLength() + 1);
		buffer = (char*)GlobalLock(clipbuffer);
		strcpy_s(buffer, source.GetLength() + 1,source.GetBuffer());
		GlobalUnlock(clipbuffer);
		SetClipboardData(CF_TEXT, clipbuffer);
		CloseClipboard();
	}
}

void sendClipboardMessage(CWnd *pwnd)
{
	keybd_event(VK_CONTROL, 0x1D, 0, 0);
	pwnd->PostMessageA(WM_KEYDOWN, 0x00000056, 0x002F0001);
	Sleep(500);
	pwnd->PostMessageA(WM_KEYUP, 0x00000056, 0xC02F0001);
	pwnd->PostMessageA(WM_KEYDOWN, 0x0000000D, 0x001C0001);
	Sleep(500);
	pwnd->PostMessageA(WM_KEYUP, 0x0000000D, 0xC01C0001);
	keybd_event(VK_CONTROL, 0x1D, KEYEVENTF_KEYUP, 0);
}

// CtestSendQQDlg ��Ϣ�������

BOOL CtestSendQQDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CWnd *hCurrentWindow;
	CString WndText;
	CString SendText;
	HWND hw = (HWND)0x0011035A;
	hCurrentWindow = CDialog::FromHandle(hw);
	sendStringToClipboard(hw,CString("����Ϣ��robot ����"));
	sendClipboardMessage(hCurrentWindow);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CtestSendQQDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CtestSendQQDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CtestSendQQDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
