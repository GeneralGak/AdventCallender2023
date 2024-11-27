#ifndef DAY3TASK2_H
#define DAY3TASK2_H

#pragma once
#include <Vector>
#include <string>
#include <fstream>
#include <sstream>
#include <array>
#include <map>

using namespace std;

namespace adventCoding
{
	class Day3Task2
	{
	private:
		int CheckGearPositions(int _gearPosition, char* _array[], int _arrayHeight, int _arrayLengh, int _currentRow);

	public:
		std::vector<int> FindAllGearRatios();

		static Day3Task2& getInstance()
		{
			static Day3Task2 instance;
			return instance;
		}
	};
}
#endif // !DAY3TASK2_H