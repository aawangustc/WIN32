#include "std.h"
#include "Console.h"
extern HANDLE g_hStdOut;
HMENU hMainMenu;
LRESULT CALLBACK WinPro( HWND hWnd ,UINT uMsg ,WPARAM wParam ,LPARAM lParam )
{
	switch(uMsg)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case 1004:
			PostQuitMessage(0);
			break;
		case 1003:
			{
				
				EnableMenuItem(hMainMenu,1004,MF_GRAYED);
				Cout("项目\n",g_hStdOut);
			}
			break;
		}
		break;
	case WM_CREATE:
		OnCreate( hWnd, uMsg, wParam, lParam );
		break;
	case WM_TIMER:
		
	case  WM_CHAR:
		{
			CHAR text[256] = { 0 };
			sprintf_s(text,"WM_CHAR:  %c\n",wParam);
			WriteConsole(g_hStdOut,text,strlen(text),NULL,NULL);
			sprintf_s(text,"%c",wParam);	
			
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc( hWnd ,uMsg ,wParam ,lParam );

}


BOOL MyRegister( LPSTR pszClassName ,HINSTANCE g_hInst )
{
	WNDCLASSEX wce = { 0 };
	wce.cbClsExtra = NULL;
	wce.cbSize     = sizeof( wce );
	wce.cbWndExtra = NULL;
	wce.hCursor    = NULL;
	wce.hIcon      = NULL;
	wce.hIconSm    = NULL;
	wce.hInstance  = g_hInst;
	wce.style      = CS_VREDRAW|CS_HREDRAW;
	wce.lpfnWndProc   = WinPro;
	wce.lpszClassName = pszClassName;
	wce.lpszMenuName  = NULL;
	wce.hbrBackground =( HBRUSH )( COLOR_BACKGROUND );
	ATOM tag=RegisterClassEx ( &wce );
	//if ( 0 == tag )
	//{
	//	MessageBox(NULL ,"MyRegister failed" ,"MyRegister" ,MB_OK );
	//	return FALSE;
	//}
	//else
	//{
	//	MessageBox(NULL ,"MyRegister Success" ,"MyRegister" ,MB_OK );
	//	return TRUE;   
	//}	
	return TRUE;
}

HWND CreateWnd( LPSTR pszClassName ,HINSTANCE g_hInst )
{
	HWND hWnd = CreateWindowEx(0 ,pszClassName ,"MyWindow",WS_OVERLAPPEDWINDOW ,CW_USEDEFAULT ,CW_USEDEFAULT ,
		CW_USEDEFAULT ,CW_USEDEFAULT ,NULL ,NULL ,g_hInst ,NULL );
	//if ( 0 == hWnd )
	//{
	//	MessageBox( NULL ,"CreateWnd failed","CreateWnd",MB_OK);
	//}
	//else
	//{
	//	MessageBox( NULL ,"CreateWnd Sucess","CreateWnd",MB_OK);
	//}

	return hWnd;
}
void DisplayWnd( HWND hWnd )
{
	ShowWindow( hWnd ,SW_SHOW );
	UpdateWindow( hWnd );

}
void MessageLoop( )
{
	MSG msg = { 0 };
	while(GetMessage( &msg, NULL, 0, 0))
	{
		TranslateMessage( &msg );
		DispatchMessage ( &msg );
	}
}

void OnCreate(  HWND hWnd ,UINT uMsg ,WPARAM wParam ,LPARAM lParam )
{
	 hMainMenu = CreateMenu( );
	//创建子菜单
	HMENU hFileMenu = CreatePopupMenu( );
	//增加菜单项
	
	
	HMENU hFileMenu1 = CreatePopupMenu( );
	AppendMenu( hFileMenu1 ,MF_STRING ,1004 ,"退出");
	AppendMenu( hMainMenu ,MF_STRING|MF_POPUP ,(UINT)hFileMenu1 ,"文件");

	AppendMenu( hMainMenu ,MF_STRING ,1001 ,"编辑");
	AppendMenu( hMainMenu ,MF_STRING ,1002 ,"视图");
	AppendMenu( hMainMenu ,MF_STRING ,1003 ,"项目");
	//给窗口设置主菜单
	SetMenu( hWnd, hMainMenu );

}