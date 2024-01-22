#include "GameManager.h"
#include <Windows.h>
#include <iostream>

GameManager::GameManager(string levelFileName)
{
	_player.init(100, 10, 10, 0, 1);
	_level.loadLevel(levelFileName, _player);
	//_level.displayLevel();
}

GameManager::~GameManager()
{
}

void GameManager::runGame()
{
	mainMenu();
	int input = 3;
	bool gameOver = false;

	/*while ((input == 3) || (input == 4))
	{
		switch (input)
		{
			case 1:
				break;

			case 2:
				break;

			case 3: system("cls");

				break;

			case 4: system("cls");
				break;

			default:
				break;
		}
	}*/

	while (!gameOver)
	{
		_level.displayLevel();
		playerInput();
		_level.updateEnemyPosition(_player);
		_level.incrementTurnCounter();
	}
}

void GameManager::playerInput()
{
	char input;
	printf("\nConsole.. (w/a/s/d)>> ");
	input = _getch();
	_level.movePlayer(input, _player);
}

void GameManager::mainMenu() {
	system("cls");
	CONSOLE_SCREEN_BUFFER_INFO csbi;	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;	int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	std::cout << std::string((consoleWidth - 26) / 2, ' ') << "Welcome to RogueLike Console Game!!\n" << std::endl;	std::cout << std::string((consoleWidth - 14) / 2, ' ') << "Press 'space' to start\n" << std::endl;
	int input = 0;
	while (input != 32) { // Ожидание нажатия пробела		
		input = _getch();
	}	system("cls");
}
