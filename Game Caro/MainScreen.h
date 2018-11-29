#pragma once
#include <string>
using namespace std;

class MainScreen{
	private:
		int ScreenColumns;
		int ScreenRows;
		int TypeMenu;
		const int SizeofMenu[10] = { 6, 3, 1, 4};
	private:
		void PrintMenu(int, char, int, int);
		bool HandleOptionMenu(int, char&, int&, int&);
	public:
		MainScreen();
		int getTypeMenu() { return TypeMenu; }
		void PrintTitle();
		void SetFeatures(int, string&, char&, int&, int&);
};
