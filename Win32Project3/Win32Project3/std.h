#ifndef _std
#define _std

#include <windows.h>
#include<stdio.h>
LRESULT CALLBACK WinPro( HWND hWnd ,UINT uMsg ,WPARAM wParam ,LPARAM lParam );


BOOL MyRegister( LPSTR pszClassName ,HINSTANCE g_hInst );


HWND CreateWnd( LPSTR pszClassName ,HINSTANCE g_hInst );


void DisplayWnd( HWND hWnd );


void MessageLoop(   );

void OnCreate( HWND hWnd ,UINT uMsg ,WPARAM wParam ,LPARAM lParam );

#endif