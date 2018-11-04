#include "MainScreen.h"
#include "Windows.h"
#include "Graphics.h"
#include <stdio.h>

MainScreen::MainScreen() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	ScreenColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1; 
	ScreenRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; 
}

void MainScreen::PrintTitle(){
	int initX = (ScreenColumns - 74) / 2 + 8;
	int initY = 6;

	/*
		print 'C'
	*/
	Sleep(900);

	Graphics::gotoXY(initX, initY);
	printf_s("CCCCCCCCCCCCC");

	Graphics::gotoXY(initX - 3, initY + 1);
	printf_s("CCC::::::::::::C");

	Graphics::gotoXY(initX - 5, initY + 2);
	printf_s("CC:::::::::::::::C");

	Graphics::gotoXY(initX - 6, initY + 3);
	printf_s("C:::::CCCCCCCC::::C");


	Graphics::gotoXY(initX - 7, initY + 4);
	printf_s("C:::::C       CCCCCC");

	for (int i = 1; i <= 6; i++) {
		Graphics::gotoXY(initX - 8, initY + 4 + i);
		printf_s("C:::::C");
	}

	Graphics::gotoXY(initX - 7, initY + 11);
	printf_s("C:::::C       CCCCCC");

	Graphics::gotoXY(initX - 6, initY + 12);
	printf_s("C:::::CCCCCCCC::::C");

	Graphics::gotoXY(initX - 5, initY + 13);
	printf_s("CC:::::::::::::::C");

	Graphics::gotoXY(initX - 3, initY + 14);
	printf_s("CCC::::::::::::C");

	Graphics::gotoXY(initX, initY + 15);
	printf_s("CCCCCCCCCCCCC");

	Sleep(900);

	/*
		print 'A'
	*/
	initX += 15;
	initY += 4;

	Graphics::gotoXY(initX, initY);
	printf_s("aaaaaaaaaaaaa");

	Graphics::gotoXY(initX, initY + 1);
	printf_s("a::::::::::::a");

	Graphics::gotoXY(initX, initY + 2);
	printf_s("aaaaaaaaa:::::a");

	Graphics::gotoXY(initX + 9, initY + 3);
	printf_s("a::::a");

	Graphics::gotoXY(initX + 2, initY + 4);
	printf_s("aaaaaaa:::::a");

	Graphics::gotoXY(initX, initY + 5);
	printf_s("aa::::::::::::a");

	Graphics::gotoXY(initX - 1, initY + 6);
	printf_s("a::::aaaa::::::a");

	for (int i = 1; i <= 2; i++) {
		Graphics::gotoXY(initX - 2, initY + 6 + i);
		printf_s("a::::a    a:::::a");
	}

	Graphics::gotoXY(initX - 2, initY + 9);
	printf_s("a:::::aaaa::::::a");

	Graphics::gotoXY(initX -1, initY + 10);
	printf_s("a::::::::::aa:::a");

	Graphics::gotoXY(initX, initY + 11);
	printf_s("aaaaaaaaaa  aaaa");

	Sleep(900);

	/*
		print 'R'
	*/
	initX += 15;

	Graphics::gotoXY(initX, initY);
	printf_s("rrrrrrrrrrrrrrrrr");

	Graphics::gotoXY(initX, initY + 1);
	printf_s("r::::rrr:::::::::r");

	Graphics::gotoXY(initX, initY + 2);
	printf_s("r:::::::::::::::::r");

	Graphics::gotoXY(initX, initY + 3);
	printf_s("rr::::::rrrrr::::::r");

	Graphics::gotoXY(initX + 1, initY + 4);
	printf_s("r:::::r     r:::::r");

	Graphics::gotoXY(initX + 1, initY + 5);
	printf_s("r:::::r     rrrrrrr");

	for (int i = 1; i <= 5; i++) {
		Graphics::gotoXY(initX + 1, initY + 5 + i);
		printf_s("r:::::r");
	}

	Graphics::gotoXY(initX + 1, initY + 11);
	printf_s("rrrrrrr");

	Sleep(900);

	/*
		print 'O'
	*/
	initX += 23;

	Graphics::gotoXY(initX, initY);
	printf_s("ooooooooooo");

	Graphics::gotoXY(initX - 2, initY + 1);
	printf_s("oo:::::::::::oo");

	Graphics::gotoXY(initX - 3, initY + 2);
	printf_s("o:::::::::::::::o");

	Graphics::gotoXY(initX - 3, initY + 3);
	printf_s("o:::::ooooo:::::o");

	for (int i = 1; i <= 4; i++) {
		Graphics::gotoXY(initX - 3, initY + 3 + i);
		printf_s("o::::o     o::::o");
	}

	Graphics::gotoXY(initX - 3, initY + 8);
	printf_s("o:::::ooooo:::::o");

	Graphics::gotoXY(initX - 3, initY + 9);
	printf_s("o:::::::::::::::o");

	Graphics::gotoXY(initX - 2, initY + 10);
	printf_s("oo:::::::::::oo");

	Graphics::gotoXY(initX, initY + 11);
	printf_s("ooooooooooo");
}

void MainScreen::ProcessMenu(){
	

	//Graphics::gotoXY(srColumns / 2, srRows / 2);
	//printf_s("%d %d", columns, rows);
}