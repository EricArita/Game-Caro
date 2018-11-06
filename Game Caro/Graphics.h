#pragma once

class Graphics {
	public:
		static int ConsoleScreenColumns;
		static int ConsoleScreenRows;
	public:
		static void InitializeComponent();
		static void SetColor(int);
		static void gotoXY(int, int);
		static void HideCursor(bool);
		static void getConsoleScreenSize();
};
