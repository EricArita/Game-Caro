#include "Graphics.h"
#include "windows.h"

int Graphics::ConsoleScreenColumns = 0;
int Graphics::ConsoleScreenRows = 0;

void Graphics::gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Graphics::InitializeComponent() {
	//HWND consoleWindow = GetConsoleWindow();
	//SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MINIMIZEBOX);
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void Graphics::SetColor(int i){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void Graphics::HideCursor(bool visible) {
	CONSOLE_CURSOR_INFO infoCursor;
	infoCursor.bVisible = visible;
	infoCursor.dwSize = 10;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &infoCursor);
}

void Graphics::getConsoleScreenSize(void) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	ConsoleScreenColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	ConsoleScreenRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

	
