#include "Graphics.h"
#include "windows.h"
#include<string>
using namespace std;

int Graphics::ConsoleScreenColumns = 0;
int Graphics::ConsoleScreenRows = 0;

void Graphics::gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Graphics::InitializeComponent() {
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void Graphics::SetColor(int i){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void Graphics::VisibleCursor(bool visible) {
	CONSOLE_CURSOR_INFO infoCursor;
	infoCursor.bVisible = visible;
	infoCursor.dwSize = 10;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &infoCursor);
}

void Graphics::Blink(int x, int y, string content) {
		for (int i = 1; i <= 4; i++) {
			Graphics::gotoXY(x, y);

			if (i == 1)
				Graphics::SetColor(14);
			else if (i == 2)
				Graphics::SetColor(12);
			else if (i == 3)
				Graphics::SetColor(13);
			else if (i == 4)
				Graphics::SetColor(10);

			cout << content;
			Sleep(120);
		}
}

void Graphics::getConsoleScreenSize(void) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	ConsoleScreenColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	ConsoleScreenRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

	
