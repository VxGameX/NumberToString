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

string unidades[9] { "UNO", "DOS", "TRES", "CUATRO", "CINCO", "SEIS", "SIETE", "OCHO", "NUEVE" };
string dieces[10] { "DIEZ", "ONCE", "DOCE", "TRECE", "CATORCE", "QUINCE", "DIECISEIS", "DIECISIETE", "DIECIOCHO", "DIECINUEVE" };
string centenas[8] { "VEINTE", "TREINTA", "CUARENTA", "CINCUENTA", "SESENTA", "SETENTA", "OCHENTA", "NOVENTA" };
string otros[6] { "CIEN", "CIENTO", "CIENTOS", "MIL", "MILLON", "MILLONES"};
string aux[5]{ "UN", "VEINTI", "QUINIENTOS", "SETE", "NOVE"};

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
    cout << "Numero: ";
	cin >> number;

	cout << ConvertNumber(number);
}

string ConvertNumber(string number)
{
	int digitPosition = 0, numberLength = number.length();

	string numberDigit, numberString = "";

	if (number == "0")
		return "CERO PESOS DOMINICANOS\n";

	for (numberLength; numberLength > 0; numberLength--)
	{
		numberDigit = number[digitPosition];

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
			numberString += (numberDigit != "1") ? unidades[stoi(numberDigit) - 1] : "";

			// Número 101 - 199
			if (((numberDigit == "1") && (number[digitPosition + 1] != '0')) || ((numberDigit == "1") && (number[digitPosition + 2] != '0')))
			{
				numberString += otros[1];
			}
			// 100
			else if (numberDigit == "1")
			{
				numberString += otros[0];
			}
			// 200 - 900
			else
			{
				numberString += otros[2];
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
				numberDigit = number[digitPosition + 1];
				numberString += dieces[stoi(numberDigit)];
				numberLength--;
			}
			// +20
			else
			{
				numberString += centenas[stoi(numberDigit) - 2];
			}
		}
		// Unidad
		else if (numberLength == 1)
		{
			numberString += (numberString == "") ? unidades[stoi(numberDigit) - 1] : " " + unidades[stoi(numberDigit) - 1];
		}

		digitPosition++;
	}
	return numberString += " PESOS DOMINICANOS CON 00/100\n";
}
