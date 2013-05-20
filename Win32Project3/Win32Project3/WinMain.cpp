#include "std.h"
#include "Console.h"
HANDLE g_hStdOut;


int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd )
{
	MyRegister( "MyClass" ,hInstance );
	HWND hWnd = CreateWnd( "MyClass" ,hInstance );
	
	g_hStdOut = OnCreateConsole();
	
	
	DisplayWnd( hWnd );
	MessageLoop(   );
	return 0;
}