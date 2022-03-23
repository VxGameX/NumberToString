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

	cout << ConvertNumber(number);
}

string ConvertNumber(string number)
{
	int numberLength = number.length();

	string numberDigit, numberString = "";

	if (number == "0")
		return "ZERO PESOS DOMINICANOS\n";

	for (int j = 0, i = numberLength; i > 0; i--)
	{
		numberDigit = number[j];
		j++;

		if (numberDigit == "0")
			continue;

		switch (i)
		{
			// Unidades
			case 1:
				numberString += unit[stoi(numberDigit) - 1];
				break;
			// Decenas
			case 2:
				if ((numberDigit == "1") && (number[j] == '0'))
				{
					numberString += teen[stoi(numberDigit) - 1];
				}
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
			// Centenas
			case 3:
				numberString += unit[stoi(numberDigit) - 1];
				numberString += (" " + other[0]);
				break;
			// Unidad de mil
			case 4:
				numberString += unit[stoi(numberDigit) - 1];
				numberString += (" " + other[1]);
				break;
			// Decena de mil
			case 5:
				if ((numberDigit == "1") && (number[j] == '0'))
				{
					numberString += teen[stoi(numberDigit) - 1];
				}
				else if ((numberDigit == "1") && (number[j] != '0'))
				{
					numberDigit = number[j];
					numberString += teen[stoi(numberDigit)];
					i--;
				}
				else
				{
					numberString += ten[stoi(numberDigit) - 2];
					numberString += " " + unit[stoi(numberDigit) - 2];
					i--;
				}
				numberString += " " + other[1];
				break;
			// Centena de mil
			case 6:
				numberString += unit[stoi(numberDigit) - 1];
				numberString += " " + other[0];
				break;
			// Unidad de millón
			case 7:
				numberString += unit[stoi(numberDigit) - 1];
				numberString += (" " + other[0]);
				break;
			// Decena de millón
			case 8:
				numberString += unit[stoi(numberDigit) - 1];
				numberString += (" " + other[0]);
				break;
			// Centena de millón
			case 9:
				numberString += unit[stoi(numberDigit) - 1];
				numberString += (" " + other[0]);
				break;
			default:
				break;
		}
		numberString += " ";
	}
	return numberString += "PESOS DOMINICANOS\n";
}

string CheckNumber(int number)
{

}
