// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� CLIBOARDQQSENDER_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// CLIBOARDQQSENDER_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef CLIBOARDQQSENDER_EXPORTS
#define CLIBOARDQQSENDER_API extern "C" __declspec(dllexport)
#else
#define CLIBOARDQQSENDER_API __declspec(dllimport)
#endif

CLIBOARDQQSENDER_API void setHwnd(UINT32 value);

CLIBOARDQQSENDER_API void send(void);
