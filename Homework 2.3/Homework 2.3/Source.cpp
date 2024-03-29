﻿#include<Windows.h>
#include<tchar.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Домашнее задание");

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpfnWndProc = WindowProc;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hInstance = hInst;
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = szClassWindow;
	wcl.hIconSm = NULL;

	if(!RegisterClassEx(&wcl))
	{
		return 0;
	}

	hWnd = CreateWindowEx(0, szClassWindow, TEXT("Домашнее задание 3"),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, NULL, NULL, hInst, NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MessageBox(hWnd, TEXT("Откройте, пожалуйста, \"Калькулятор\""), TEXT("Работа с калькулятором"), MB_OK | MB_ICONINFORMATION);

	while(GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return lpMsg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	switch(uMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
	{
						   HWND h = FindWindow(TEXT("CalcFrame"), TEXT("Калькулятор"));
						   if(!h)
						   {
							   MessageBox(hWnd, TEXT("Необходимо открыть \"Калькулятор\"!"), NULL, MB_OK | MB_ICONERROR);
						   }
						   else
						   {
							   SetWindowText(h, TEXT("Calculator"));

						   }
	}
		break;
	case WM_RBUTTONDOWN:
	{
						   HWND h1 = FindWindow(TEXT("CalcFrame"), TEXT("Калькулятор"));
						   HWND h2 = FindWindow(TEXT("CalcFrame"), TEXT("Calculator"));
						   if(h1)
						   {
							   MoveWindow(h1, 100, 100, 423, 423, TRUE);
						   }
						   else if(h2)
						   {
							   MoveWindow(h2, 100, 100, 423, 423, TRUE);
						   }
						   else
						   {
							   MessageBox(hWnd, TEXT("Необходимо открыть \"Калькулятор\"!"), NULL, MB_OK | MB_ICONERROR);
						   }
	}
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}