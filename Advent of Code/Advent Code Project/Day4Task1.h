#ifndef DAY4TASK1_H
#define DAY4TASK1_H

#pragma once
#include <Vector>
#include <string>
#include <fstream>
#include <sstream>
#include <array>

using namespace std;

namespace adventCoding
{
	class Day4Task1
	{
	public:
		std::vector<int> FindWinningNumberPoints();

		static Day4Task1& getInstance()
		{
			static Day4Task1 instance;
			return instance;
		}
	};
}
#endif // !DAY4TASK1_H