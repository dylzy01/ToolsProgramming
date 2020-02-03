#include <afxwin.h>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // main window class name

class CMyFrame : public CFrameWnd
{
public:
	CMyFrame() {
		///Create(NULL, _T("Simple MFC Example"));
		Create(NULL, _T("Simple MFC Example"));
	}
};

class CExample : public CWinApp
{
	BOOL InitInstance() {
		CMyFrame *frame = new CMyFrame();
		m_pMainWnd = frame;

		frame->ShowWindow(SW_NORMAL);
		frame->UpdateWindow();

		return TRUE;
	}

	int Run() {
		MSG msg;
		BOOL bGotMsg;
		PeekMessage(&msg, NULL, 0U, 0U, PM_NOREMOVE);

		while (WM_QUIT != msg.message)
		{
			if (true) { bGotMsg = (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE) != 0); }
			else { bGotMsg = (GetMessage(&msg, NULL, 0U, 0U) != 0); }

			if (bGotMsg)
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);

				if (msg.message == WM_KEYDOWN) {}
			}
			else {}
		}
		return (int)msg.wParam;
	}
};

CExample theApp;