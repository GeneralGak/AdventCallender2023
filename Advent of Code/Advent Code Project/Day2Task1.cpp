#include "Day2Task1.h"
#include "iostream"
#include "GeneralUse.h"

namespace adventCoding
{
	/// <summary>
	/// Find strings containing 'games' that are possible, 
	/// based on a given number of colors
	/// </summary>
	/// <returns></returns> vector of ID numbers from the possible games
	std::vector<int> adventCoding::Day2Task1::FindPosibleGames()
	{
		std::vector<int> result;
		std::vector<std::string> taskText = GeneralUse::getInstance().GetTextFromFile("Day2.txt");

		for (size_t i = 0; i < taskText.size(); i++)
		{
			std::string currentString = taskText[i];
			std::vector<std::string> subsets;
			bool isPossible = true;

			std::stringstream stringIterator(currentString);

			for (std::string line; std::getline(stringIterator, line, ';');)
			{
				subsets.push_back(line);
			}

			for (size_t j = 0; j < subsets.size(); j++)
			{
				std::map<std::string, int> colorsInBagChecker = colorsInBag;

				for (auto color : colors)
				{
					size_t found = subsets[j].find(color);

					if (found == std::string::npos) continue;

					std::map<std::string, int>::iterator cubes = colorsInBagChecker.find(color);

					std::string cubeNumberString = "";
					for (size_t k = found - 2; k > 0; k--)
					{
						if (isdigit(subsets[j][k])) cubeNumberString.insert(0, 1, subsets[j][k]);
						else break;
					}

					int cubeNumber = stoi(cubeNumberString);

					cubes->second -= cubeNumber;

					if (cubes->second < 0)
					{
						isPossible = false;
						break;
					}
				}

				if (isPossible == false) break;
			}

			if (isPossible == false) continue;

			size_t foundGameNumber = currentString.find_first_of("123456789");
			std::string numberString = "";
			for (size_t j = foundGameNumber; j < currentString.size(); j++)
			{
				if (isdigit(currentString[j])) numberString += currentString[j];
				else break;
			}

			int gameNumber = stoi(numberString);

			//std::cout << static_cast<unsigned>(gameNumber) << std::endl;

			result.push_back(gameNumber);
		}

		return result;
	}
}
