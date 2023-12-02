// GladiatorGame.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

char name[] = "Qwerty";

HINSTANCE hInst;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE , LPSTR lpCmdLine, int nCmdShow)
{
	hInst = hInstance;
	// 1. �������� �������� ���� ����.
	WNDCLASS win;
	win.style = CS_HREDRAW | CS_VREDRAW;
	win.lpfnWndProc = WFunc;
	win.cbClsExtra = win.cbWndExtra = 0;
	win.hInstance = hInstance;
	win.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	win.hCursor = LoadCursor(NULL, IDC_ARROW);
	win.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	win.lpszMenuName = NULL;
	win.lpszClassName = name;

	// 2. ����������� ���� � ������������ �������.
	if (!RegisterClass(&win))
	{
		MessageBox(NULL, "���� �� ����������������", "������", MB_OK);
		return -1;
	}

	// 3. �������� ����.
	HWND hwnd;
	hwnd = CreateWindow(name, "Gladiator Game",
						WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX | WS_VISIBLE,
						50, 50, 1600, 800, HWND_DESKTOP, NULL, hInstance, NULL);

	// 4. �������� ������ ���������.
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
