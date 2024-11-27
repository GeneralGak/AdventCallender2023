#include "Day2Task2.h"
#include "iostream"
#include "GeneralUse.h"


namespace adventCoding
{
	/// <summary>
	/// Goes through strings to find the fewest cubes needed to play each 'game'.
	/// Then find the power of all the cube colors by multiplying them.
	/// </summary>
	/// <returns></returns> Vector of the sum of the power of each 'games' cubes
	std::vector<int> adventCoding::Day2Task2::FindPowerOfFewestCubes()
	{
		std::vector<int> result;
		std::vector<std::string> taskText = GeneralUse::getInstance().GetTextFromFile("Day2.txt");

		for (size_t i = 0; i < taskText.size(); i++)
		{
			std::string currentString = taskText[i];
			int highesColorValues[3];

			for (size_t j = 0; j < colors.size(); j++)
			{
				size_t found = currentString.find(colors[j]);
				int highestColorValue = -1;

				while (found != std::string::npos)
				{
					int newValue;

					std::string cubeNumberString = "";
					for (size_t k = found - 2; k > 0; k--)
					{
						if (isdigit(currentString[k])) cubeNumberString.insert(0, 1, currentString[k]);
						else break;
					}

					newValue = stoi(cubeNumberString);

					if (highestColorValue == -1 || highestColorValue < newValue) highestColorValue = newValue;

					found = currentString.find(colors[j], found + colors[j].size());
				}

				highesColorValues[j] = highestColorValue;
			}

			int cubepower = highesColorValues[0] * highesColorValues[1] * highesColorValues[2];

			//std::cout << static_cast<unsigned>(gameNumber) << std::endl;

			result.push_back(cubepower);
		}

		return result;
	}
}
