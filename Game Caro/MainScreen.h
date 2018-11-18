#pragma once
#include <string>
using namespace std;

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
		int getTypeMenu() { return TypeMenu; }
		void PrintTitle();
		void SetFeatures(int, string&);
};
