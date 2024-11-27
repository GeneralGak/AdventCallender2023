#include "Day3Task2.h"
#include "GeneralUse.h"
#include "iostream"
#include "windows.h"


namespace adventCoding
{
	/// <summary>
	/// In a diagram, find two numbers next to a '*' symbol and multiply them to use the sum.
	/// Do that for all '*' symbols
	/// </summary>
	/// <returns></returns> Vector of the sums of all numbers next to '*' symbols
	std::vector<int> adventCoding::Day3Task2::FindAllGearRatios()
	{
		std::vector<int> result;
		std::vector<std::string> taskText = GeneralUse::getInstance().GetTextFromFile("Day3.txt");

		int diagramX = taskText[0].size();
		int diagramY = taskText.size();

		char** engineSchematic = new char* [diagramY];
		for (int i = 0; i < diagramY; i++)
		{
			engineSchematic[i] = new char[diagramX];

			for (int j = 0; j < diagramX; j++)
			{
				engineSchematic[i][j] = taskText[i][j];
				//std::cout << engineSchematic[i][j];
			}

			//std::cout << std::endl;
		}

		std::vector<int> numberPositions;
		for (int i = 0; i < diagramY; i++)
		{
			for (int j = 0; j < diagramX; j++)
			{
				if (engineSchematic[i][j] == '*')
				{
					int partNumber = CheckGearPositions(j, engineSchematic, diagramY, diagramX, i);

					if (partNumber != -1) result.push_back(partNumber);
				}
				//else std::cout << engineSchematic[i][j];
			}
			//std::cout << std::endl;
		}

		for (int i = 0; i < diagramY; i++)
		{
			delete[] engineSchematic[i];
		}
		delete[] engineSchematic;

		return result;
	}

	int Day3Task2::CheckGearPositions(int _gearPosition, char* _array[], int _arrayHeight, int _arrayLengh, int _currentRow)
	{
		bool gearIsValid = false;
		int numberRowPositions[2];
		int numberCollinPositions[2];
		int index = 0;
		//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		for (int r = 0; r < 3; r++)
		{
			int checkRow = _currentRow + (-1 + r);
			if (checkRow < 0 || checkRow > _arrayHeight - 1) continue;

			bool foundDigit = false;
			int numOfCollinsToCheck;
			if (checkRow == _currentRow) numOfCollinsToCheck = 2;
			else numOfCollinsToCheck = 3;

			for (int c = 0; c < numOfCollinsToCheck; c++)
			{
				int checkCollinNumber;
				if (checkRow == _currentRow) checkCollinNumber = _gearPosition - 1 + (2 * c);
				else checkCollinNumber = _gearPosition + (-1 + c);

				if (checkCollinNumber < 0 || checkCollinNumber > _arrayLengh - 1) continue;

				if (isdigit(_array[checkRow][checkCollinNumber]))
				{
					if (foundDigit && checkRow != _currentRow) continue;

					foundDigit = true;
					numberRowPositions[index] = checkRow;
					numberCollinPositions[index] = checkCollinNumber;
					index++;

					if (index == 2)
					{
						gearIsValid = true;
						break;
					}
				}
				else 
				{
					foundDigit = false;
				}
			}

			if (gearIsValid) break;
		}

		int number;
		if (gearIsValid == true)
		{
			int foundNumbers[2];
			
			std::string stringNumber = "";
			for (int j = 0; j < 2; j++)
			{
				stringNumber += _array[numberRowPositions[j]][numberCollinPositions[j]];

				for (int i = numberCollinPositions[j] + 1; i < _arrayLengh; i++)
				{
					if (isdigit(_array[numberRowPositions[j]][i])) stringNumber += _array[numberRowPositions[j]][i];
					else break;
				}

				for (int i = numberCollinPositions[j] - 1; i > 0; i--)
				{
					if (isdigit(_array[numberRowPositions[j]][i])) stringNumber.insert(0, 1, _array[numberRowPositions[j]][i]);
					else break;
				}

				foundNumbers[j] = stoi(stringNumber);
				stringNumber = "";
			}

			/*SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			std::cout << _array[_currentRow][_gearPosition];*/

			number = foundNumbers[0] * foundNumbers[1];
		}
		else
		{
			/*SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << _array[_currentRow][_gearPosition];*/

			number = -1;
		}

		//SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		return number;
	}
}
