#ifndef _Console
#define  _Console

#include<windows.h>
#include <stdio.h>



HANDLE  OnCreateConsole();

void Cout( const LPSTR pszStr ,HANDLE g_hStdOut  );

#endif
