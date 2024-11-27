#include "Day3Task1.h"
#include "GeneralUse.h"
#include "iostream"
#include "windows.h"


namespace adventCoding
{
	/// <summary>
	/// In a diagram find all numbers adjacent to a symbol
	/// </summary>
	/// <returns></returns> Vector of all numbers adjacent to a symbol
	std::vector<int> Day3Task1::FindAllPartNumbers()
	{
		std::vector<int> result;
		std::vector<std::string> taskText = GeneralUse::getInstance().GetTextFromFile("Day3.txt");

		int diagramX = taskText[0].size();
		int diagramY = taskText.size();

		char** engineSchematic = new char*[diagramY];
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
				if (isdigit(engineSchematic[i][j])) 
				{
					numberPositions.push_back(j);
				}
				else if (!numberPositions.empty())
				{
					int partNumber = CheckNumberPositions(numberPositions, engineSchematic, diagramY, diagramX, i);

					if (partNumber != -1) result.push_back(partNumber);

					numberPositions.clear();
					
					//std::cout << engineSchematic[i][j];
				}
				//else std::cout << engineSchematic[i][j];
			}

			if (!numberPositions.empty()) 
			{
				int partNumber = CheckNumberPositions(numberPositions, engineSchematic, diagramY, diagramX, i);

				if (partNumber != -1) result.push_back(partNumber);

				numberPositions.clear();
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

	int Day3Task1::CheckNumberPositions(std::vector<int> _numberPositions, char* _array[], int _arrayHeight, int _arrayLengh, int _currentRow)
	{
		bool numberIsValid = false;
		int firstNumberPosition = _numberPositions[0];
		//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		for (int r = 0; r < 3; r++)
		{
			int checkRow = _currentRow + (-1 + r);
			if (checkRow < 0 || checkRow > _arrayHeight - 1) continue;

			int numOfCollinsToCheck;
			if (checkRow == _currentRow) numOfCollinsToCheck = 2;
			else numOfCollinsToCheck = _numberPositions.size() + 2;

			for (int c = 0; c < numOfCollinsToCheck; c++)
			{
				int checkCollinNumber;
				if (checkRow == _currentRow) checkCollinNumber = firstNumberPosition - 1 + ((_numberPositions.size() + 1) * c);
				else checkCollinNumber = firstNumberPosition + (-1 + c);

				if (checkCollinNumber < 0 || checkCollinNumber > _arrayLengh - 1) continue;

				if (!isdigit(_array[checkRow][checkCollinNumber]) &&
					_array[checkRow][checkCollinNumber] != '.')
				{
					numberIsValid = true;
					break;
				}
			}

			if (numberIsValid) break;
		}

		std::string stringNumber = "";
		for (int np = 0; np < _numberPositions.size(); np++)
		{
			stringNumber += _array[_currentRow][_numberPositions[np]];
		}

		int number;
		if (numberIsValid == true)
		{
			//SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			//std::cout << stringNumber;

			number = stoi(stringNumber);
		}
		else
		{
			//SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			//std::cout << stringNumber;

			number = -1;
		}

		//SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		return number;
	}
}