#include "Shopkeep.h"
#include "windows.h"
#include <iostream>

class Player;

void Shopkeep::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)m_color);
	std::cout << "H";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}