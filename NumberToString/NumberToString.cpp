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

string unidades[9] { "UN", "DOS", "TRES", "CUATRO", "CINCO", "SEIS", "SIETE", "OCHO", "NUEVE" };
string dieces[6] { "DIEZ", "ONCE", "DOCE", "TRECE", "CATORCE", "QUINCE" };
string decenas[8] { "VEINTE", "TREINTA", "CUARENTA", "CINCUENTA", "SESENTA", "SETENTA", "OCHENTA", "NOVENTA" };
string otros[6] { "CIEN", "CIENTO", "CIENTOS", "MIL", "MILLON", "MILLONES" };
string aux[6]{ "UN0", "DIECI", "VEINTI", "QUINIENTOS", "SETE", "NOVE" };

int main()
{
	MainMenu();
	do
	{
		MainMenu();
	} while (true);
}

void MainMenu()
{
	string number;
    cout << "Numero: ";
	cin >> number;

	cout << ConvertNumber(number);

	//for (long i = 0; i < 100; i++)
	//{
	//	//cout << ConvertNumber(to_string(i));
	//}
}

string ConvertNumber(string number)
{
	int digitPosition = 0, numberLength = number.length();

	string numberDigit, numberString = "";

	for (numberLength; numberLength > 0; numberLength--)
	{
		numberDigit = number[digitPosition];

		// Cero
		if (numberDigit == "0")
		{
			digitPosition++;
			continue;
		}
		// Millón
		if (numberLength % 7 == 0)
		{
			numberString += unidades[stoi(numberDigit) - 1];
			numberString += " " + otros[2];
		}
		// Mil
		else if (numberLength % 4 == 0)
		{
			numberString += unidades[stoi(numberDigit) - 1];
			numberString += " " + otros[1];
		}
		// Centena
		else if (numberLength % 3 == 0)
		{
			if (numberDigit != "1")
			{
				unidades[stoi(numberDigit) - 1];
			}

			// Número de alante
			numberString += (numberDigit != "1") ? unidades[stoi(numberDigit) - 1] : "";

			// Número 101 - 199
			if (((numberDigit == "1") && (number[digitPosition + 1] != '0')) || ((numberDigit == "1") && (number[digitPosition + 2] != '0')))
			{
				numberString += otros[1] + " ";
			}
			// 100
			else if (numberDigit == "1")
			{
				numberString += otros[0];
			}
			// 200 - 900
			else
			{
				numberString += otros[2] + " ";
			}
		}
		// Decena
		else if (numberLength % 2 == 0)
		{
			// Diez
			if ((numberDigit == "1") && (number[digitPosition + 1] == '0'))
			{
				numberString += dieces[stoi(numberDigit) - 1];
			}
			// 11 - 19
			else if ((numberDigit == "1") && (number[digitPosition + 1] != '0'))
			{
				// 11 - 15
				if ((number[digitPosition + 1] == '1') || (number[digitPosition + 1] == '2') || (number[digitPosition + 1] == '3') || (number[digitPosition + 1] == '4') || (number[digitPosition + 1] == '5'))
				{
					numberDigit = number[digitPosition + 1];
					numberString += dieces[stoi(numberDigit)];
					numberLength--;
				}
				// 16 - 19
				else
				{
					numberString += aux[1];
				}
			}
			// +20
			else if (number[digitPosition + 1] == '0')
			{
				numberString += decenas[stoi(numberDigit) - 2];
			}
			else if (numberDigit != "2")
			{
				numberString += decenas[stoi(numberDigit) - 2] + " Y ";
			}
			else
			{
				numberString += aux[2];
			}
		}
		// Unidad
		else if (numberLength == 1)
		{
			numberString += unidades[stoi(numberDigit) - 1];
		}

		digitPosition++;
	}
	return (numberString == "") ? "CERO PESOS DOMINICANOS CON 00/100\n" : (numberString == "UN") ? numberString + " PESO DOMINICANO CON 00/100\n" : numberString + " PESOS DOMINICANOS CON 00/100\n";
}
