// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� CLIBOARDQQSENDER_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// CLIBOARDQQSENDER_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef CLIPBOARDQQSENDER_EXPORTS
#define CLIPBOARDQQSENDER_API extern "C" __declspec(dllexport)
#else
#define CLIPBOARDQQSENDER_API __declspec(dllimport)
#endif

CLIPBOARDQQSENDER_API void Paste(HWND value);

CLIPBOARDQQSENDER_API void Pasteln(HWND value);

CLIPBOARDQQSENDER_API void PasteAndSumbit(HWND value);

CLIPBOARDQQSENDER_API void Heartbeat(HWND value);

CLIPBOARDQQSENDER_API void Return(HWND value);

CLIPBOARDQQSENDER_API void Sumbit(HWND value);

CLIPBOARDQQSENDER_API void Sumbit2(HWND value);