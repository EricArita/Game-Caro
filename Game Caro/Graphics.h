#pragma once
#include<iostream>
using namespace std;

class Graphics {
	public:
		static int ConsoleScreenColumns;
		static int ConsoleScreenRows;
	public:
		static void SetFullConsoleScreen();
		static void SetColor(int);
		static void gotoXY(int, int);
		static void VisibleCursor(bool);
		static void Blink(int, int, string);
		static void getConsoleScreenSize();
};
