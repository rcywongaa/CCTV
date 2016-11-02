// playCamera.cpp : Defines the entry point for the console application.
//

/*
TODO:
Distinguish table and chair based on size
*/

#define SAVE
#define LIGHT
#define TIMER
//#define DEBUG
#define DETECT

#define START_TIME 19
#define END_TIME 22
#define OFF_TIME 7
#define MIN_UNCHANGED 10
#define DIFF_THRESH 1.5
#define MAX_FAILURES 1000

#include "stdafx.h"
#include "VideoRecorder.h"
#include "MultithreadCam.h"

int _tmain(int argc, _TCHAR* argv[])
{
	MultithreadCam multicam;
	if (!multicam.isInit())
	{
		cout << "Camera init failed! Rebooting in 10 secs..." << endl;
		Sleep(10000);
		rebootSystem();
	}
#ifdef SAVE
	VideoRecorder recorder(&multicam);
#endif
	while (true)
	{
		int hour = getCurrentHour();
		int minute = getCurrentMinute();
		cout << hour << ":" << minute << endl;
		if (hour == 12 && minute == 00)
		{
			Sleep(60 * 1000);
			rebootSystem();
		}
		Sleep(30 * 1000);
    }
	return 0;
}
