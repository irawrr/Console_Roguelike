#include <iostream>
#include <string>
#include <conio.h>

#include "GameManager.h"

using std::cout;
using std::cin;
using std::string;

int main()
{
	GameManager gameManger("C:\\Users\\ira-k\\source\\repos\\Game_ASCIIRogueLike\\ASCIIRogueLike\\Levels\\Level_2.level");

	gameManger.runGame();

	cout << "\nPress ENTER to continue...\n";
	_getch();
	return 0;
}