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
string other[3] { "HUNDRED", "THOUSAND", "MILLION" };

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
	int digitPosition = 0, numberLength = number.length();

	string numberDigit, numberString = "";

	if (number == "0")
		return "ZERO PESOS DOMINICANOS\n";

	for (int i = numberLength; i > 0; i--)
	{
		numberDigit = number[digitPosition];

		if (numberDigit == "0")
			continue;

		// Millón
		if (i % 7 == 0)
		{
			numberString += unit[stoi(numberDigit) - 1];
			numberString += (" " + other[2]);
		}
		// Mil
		else if (i % 4 == 0)
		{
			numberString += unit[stoi(numberDigit) - 1];
			numberString += (" " + other[1]);
		}
		// Centena
		else if (i % 3 == 0)
		{
			numberString += unit[stoi(numberDigit) - 1];
			numberString += (" " + other[0]);
		}
		// Decena
		else if (i % 2 == 0)
		{
			// Diez
			if ((numberDigit == "1") && (number[digitPosition + 1] == '0'))
			{
				numberString += teen[stoi(numberDigit) - 1];
			}
			// 11 - 19
			else if ((numberDigit == "1") && (number[digitPosition + 1] != '0'))
			{
				numberDigit = number[digitPosition + 1];
				numberString += teen[stoi(numberDigit)];
				i--;
			}
			// +20
			else
			{
				numberString += ten[stoi(numberDigit) - 2];
			}
		}
		// Unidad
		else if (i == 1)
		{
			numberString += (numberString == "") ? unit[stoi(numberDigit) - 1] : " " + unit[stoi(numberDigit) - 1];
		}

		digitPosition++;

		/*numberString += CheckNumber(number, i, digitPosition);
		digitPosition++;*/
	}
	return numberString += " PESOS DOMINICANOS\n";
}

//string CheckNumber(string number, int numberLength, int digitPosition)
//{
//	string numberDigit, numberString;
//
//	numberDigit = number[digitPosition];
//
//	if (numberDigit == "0")
//		return "";
//	
//	// Millón
//	if (numberLength % 7 == 0)
//	{
//		numberString += unit[stoi(numberDigit) - 1];
//		numberString += (" " + other[2]);
//	}
//	// Mil
//	else if (numberLength % 4 == 0)
//	{
//		numberString += unit[stoi(numberDigit) - 1];
//		numberString += (" " + other[1]);
//	}
//	// Centena
//	else if (numberLength % 3 == 0)
//	{
//		numberString += unit[stoi(numberDigit) - 1];
//		numberString += (" " + other[0]);
//	}
//	// Decena
//	else if (numberLength % 2 == 0)
//	{
//		// Diez
//		if ((numberDigit == "1") && (number[digitPosition + 1] == '0'))
//		{
//			numberString += teen[stoi(numberDigit) - 1];
//		}
//		// 11 - 19
//		else if ((numberDigit == "1") && (number[digitPosition + 1] != '0'))
//		{
//			numberDigit = number[digitPosition + 1];
//			numberString += teen[stoi(numberDigit)];
//			//digitPosition;
//		}
//		// +20
//		else
//		{
//			numberString += ten[stoi(numberDigit) - 2];
//		}
//	}
//	// Unidad
//	else if (numberLength == 1)
//	{
//		numberString += unit[stoi(numberDigit) - 1];
//	}
//
//	return numberString + " ";
//}

//switch (i)
		//{
		//	// Unidades
		//	case 1:
		//		numberString += unit[stoi(numberDigit) - 1];
		//		break;
		//	// Decenas
		//	case 2:


		//		/*if ((numberDigit == "1") && (number[j] == '0'))
		//		{
		//			numberString += teen[stoi(numberDigit) - 1];
		//		}
		//		else if ((numberDigit == "1") && (number[j] != '0'))
		//		{
		//			numberDigit = number[j]; 
		//			numberString += teen[stoi(numberDigit)];
		//			i--;
		//		}
		//		else
		//		{
		//			numberString += ten[stoi(numberDigit) - 2];
		//		}*/
		//		break;
		//	// Centenas
		//	case 3:
		//		numberString += unit[stoi(numberDigit) - 1];
		//		numberString += (" " + other[0]);
		//		break;
		//	// Unidad de mil
		//	case 4:
		//		numberString += unit[stoi(numberDigit) - 1];
		//		numberString += (" " + other[1]);
		//		break;
		//	// Decena de mil
		//	case 5:
		//		if ((numberDigit == "1") && (number[j] == '0'))
		//		{
		//			numberString += teen[stoi(numberDigit) - 1];
		//		}
		//		else if ((numberDigit == "1") && (number[j] != '0'))
		//		{
		//			numberDigit = number[j];
		//			numberString += teen[stoi(numberDigit)];
		//			i--;
		//		}
		//		else
		//		{
		//			numberString += ten[stoi(numberDigit) - 2];
		//			numberString += " " + unit[stoi(numberDigit) - 2];
		//			i--;
		//		}
		//		numberString += " " + other[1];
		//		break;
		//	// Centena de mil
		//	case 6:
		//		numberString += unit[stoi(numberDigit) - 1];
		//		numberString += " " + other[0];
		//		break;
		//	// Unidad de millón
		//	case 7:
		//		numberString += unit[stoi(numberDigit) - 1];
		//		numberString += (" " + other[0]);
		//		break;
		//	// Decena de millón
		//	case 8:
		//		numberString += unit[stoi(numberDigit) - 1];
		//		numberString += (" " + other[0]);
		//		break;
		//	// Centena de millón
		//	case 9:
		//		numberString += unit[stoi(numberDigit) - 1];
		//		numberString += (" " + other[0]);
		//		break;
		//	default:
		//		break;
		//}