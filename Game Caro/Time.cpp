#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"
#include "Windows.h"
#include "Graphics.h"
#include <ctime>
#include <iostream>
#include <mutex>
using namespace std;

Time::Time() {
	this->hour = -1;
	this->minute = -1;
}

void Time::PrintTime(int PosTimeX, int PosTimeY) {
	Graphics::VisibleCursor(false);
	Graphics::SetColor(13);
	time_t t = time(0);
	tm* currTime = localtime(&t);

	Graphics::gotoXY(PosTimeX - 1, PosTimeY + 4);
	if (currTime->tm_mday <= 9)
		cout << "0" << currTime->tm_mday << "/";
	else
		cout << currTime->tm_mday << "/";

	if (currTime->tm_mon + 1 <= 9)
		cout << "0" << currTime->tm_mon + 1 << "/";
	else
		cout << currTime->tm_mon + 1 << "/";

	cout << currTime->tm_year + 1900;
	
	t = time(0);
	currTime = localtime(&t);
	int second = -1;

	if (currTime->tm_hour != hour || currTime->tm_min != minute || currTime->tm_sec != second) {
		hour = currTime->tm_hour;
		minute = currTime->tm_min;
		second = currTime->tm_sec;
		Graphics::gotoXY(PosTimeX, PosTimeY + 2);
		hour <= 9 ? cout << "0" << hour << ":" : cout << hour << ":";
		minute <= 9 ? cout << "0" << minute << ":" : cout << minute << ":";
		second <= 9 ? cout << "0" << second : cout << second;
	}
}