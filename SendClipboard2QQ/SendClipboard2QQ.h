// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� SENDCLIPBOARD2QQ_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// SENDCLIPBOARD2QQ_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef SENDCLIPBOARD2QQ_EXPORTS
#define SENDCLIPBOARD2QQ_API __declspec(dllexport)
#else
#define SENDCLIPBOARD2QQ_API __declspec(dllimport)
#endif

// �����Ǵ� SendClipboard2QQ.dll ������
class SENDCLIPBOARD2QQ_API CSendClipboard2QQ {
public:
	CSendClipboard2QQ(void);
	// TODO:  �ڴ�������ķ�����
};

extern SENDCLIPBOARD2QQ_API int nSendClipboard2QQ;

SENDCLIPBOARD2QQ_API int fnSendClipboard2QQ(void);
