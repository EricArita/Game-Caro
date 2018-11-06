#pragma once

class MainScreen{
	private:
		int ScreenColumns;
		int ScreenRows;
	private:
		void PrintMenu(int, int);
	public:
		MainScreen();
		void PrintTitle();
		int MenuProcessing();
};
