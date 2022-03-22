// IDS344-01 - 2022-01 - Grupo #1 - Number To String
// 
// Nikita Kravchenko - 1101607
// Omar Núñez - 1101587
// Oliver Infante - 1100292
// Lervis Pinales - 1096323
// Daniel Báez - 1073597

#include <iostream>
#include <string>

#include "NumberToString.h"
#include "GenericFunctions.h"

using namespace std;

int main()
{
	do
	{
		MainMenu();
	} while (true);
}

void MainMenu()
{
    cout << "";
}

string CheckNumber(string number)
{
	for (int i = number.length(); i > 0; i--)
	{
		if (i % 4 == 0)
		{
			switch (atoi(number[i]))
			{
				case 0:
					return;
				case 1:
					return;
				case 2:
					return;
				case 3:
					return;
				case 4:
					return;
				case 5:
					return;
				case 6:
					return;
				case 7:
					return;
				case 8:
					return;
				case 9:
					return;
				default:
					break;
			}
		}
	}
}
