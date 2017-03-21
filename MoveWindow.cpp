// MoveWindow.cpp : Move Window from one monitor to another.
//

#include "stdafx.h"
#include <Windows.h>
#include <vector>

using namespace std;

vector<RECT> g_monitors;


BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData)
{
	g_monitors.push_back(*lprcMonitor);
	return TRUE;
}


int main()
{
	EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, NULL);

	if (HWND winH = FindWindow(NULL, L"Untitled - Notepad"))
	{
		if (g_monitors.size())
		{
			RECT rect = g_monitors[1];
			BOOL result = MoveWindow(winH, 
				rect.left, 
				rect.top, 
				rect.right - rect.left, 
				rect.bottom - rect.top, 
				TRUE);
		}
	}
    return 0;
}
