#include "Console.h"


HANDLE  OnCreateConsole()
{
	AllocConsole();
	HANDLE hdl = GetStdHandle(STD_OUTPUT_HANDLE);
	return hdl;


}


void Cout(const LPSTR pszStr ,HANDLE g_hStdOut )
{
	WriteConsole( g_hStdOut , pszStr , strlen( pszStr ), NULL ,NULL );
}