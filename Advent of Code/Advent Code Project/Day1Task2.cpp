#include "Day1Task2.h"
#include "GeneralUse.h"
#include "iostream"

namespace adventCoding 
{
	/// <summary>
	/// Find the first and last digit in a number of strings 
	/// to form a two digit number, including words spelling numbers.
	/// </summary>
	/// <returns></returns> Vector containing two digit numbers from all strings
	std::vector<int> Day1Task2::FindNumberInWordsAndDigits()
	{
		std::vector<int> result;
		std::map<int, char> numbersFound;
		std::vector<std::string> taskText = GeneralUse::getInstance().GetTextFromFile("Day1.txt");

		for (int i = 0; i < taskText.size(); i++)
		{
			numbersFound.clear();
			std::string currentString = taskText[i];
			char numberChar[2];

			for (auto number : spelledNumToNum)
			{
				size_t found = currentString.find(number.first);

				while (found != std::string::npos) 
				{
					numbersFound.insert({ found, number.second });

					found = currentString.find(number.first, found + number.first.size());
				}
			}

			for (int j = 0; j < currentString.length(); j++)
			{
				if (isdigit(currentString[j]))
				{
					numbersFound.insert({ j, currentString[j] });
				}
			}

			int currentLowestIndex = -1;
			int currentHighestIndex = -1;
			char currentLowestNumber = '-1';
			char currentHighestNumber = '-1';
			for (auto foundNumber : numbersFound)
			{
				if (currentLowestIndex == -1 || foundNumber.first < currentLowestIndex) 
				{
					currentLowestIndex = foundNumber.first;
					currentLowestNumber = foundNumber.second;
				}

				if (currentHighestIndex == -1 || foundNumber.first > currentHighestIndex)
				{
					currentHighestIndex = foundNumber.first;
					currentHighestNumber = foundNumber.second;
				}
			}

			numberChar[0] = currentLowestNumber;
			numberChar[1] = currentHighestNumber;

			int value = stoi(numberChar);

			//std::cout << static_cast<unsigned>(value) << std::endl;

			result.push_back(value);
		}
		
		return result;
	}
}