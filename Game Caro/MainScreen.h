#pragma once

class MainScreen{
	private:
		int ScreenColumns;
		int ScreenRows;
		int TypeMenu;
		const int SizeofMenu[10] = { 6, 2 };
	private:
		void PrintMenu(int);
	public:
		MainScreen();
		void PrintTitle();
		void MenuProcessing(int);
};
