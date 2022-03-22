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

string unit[9] { "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
string teen[10] { "TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN" };
string ten[8] { "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY" };
string other[4] { "HUNDRED", "THOUSAND", "MILLION", "BILLION" };

int main()
{
	do
	{
		MainMenu();
	} while (true);
}

void MainMenu()
{
	string number;
    cout << "Number: ";
	cin >> number;

	cout << CheckNumber(number);
}

string CheckNumber(string number)
{
	int numberLength = number.length();

	string numberDigit, numberString = "";

	if (number == "0") return "ZERO PESOS DOMINICANOS ";

	for (int j = 0, i = numberLength; i > 0; i--)
	{
		numberDigit = number[j];
		j++;

		if (numberDigit == "0") continue;

		switch (i)
		{
			//case 0:
			//	// Does nothing
			//	break;
			case 1:
				numberString += unit[stoi(numberDigit) - 1];
				break;
			case 2:
				if ((numberDigit == "1") && (number[j] == '0')) numberString += teen[stoi(numberDigit) - 1];
				else if ((numberDigit == "1") && (number[j] != '0'))
				{
					numberDigit = number[j];
					numberString += teen[stoi(numberDigit)];
					i--;
				}
				else
				{
					numberString += ten[stoi(numberDigit) - 2];
				}
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			default:
				break;
		}
		numberString += " ";
	}
	return numberString += "PESOS DOMINICANOS ";
}
