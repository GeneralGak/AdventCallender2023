#ifndef DAY3TASK1_H
#define DAY3TASK1_H

#pragma once
#include <Vector>
#include <string>
#include <fstream>
#include <sstream>
#include <array>

using namespace std;

namespace adventCoding
{
	class Day3Task1
	{
	private:
		int CheckNumberPositions(std::vector<int> _numberPositions, char* _array[], int _arrayHeight, int _arrayLengh, int _currentRow);


	public:
		std::vector<int> FindAllPartNumbers();

		static Day3Task1& getInstance()
		{
			static Day3Task1 instance;
			return instance;
		}
	};
}
#endif // !DAY3TASK1_H