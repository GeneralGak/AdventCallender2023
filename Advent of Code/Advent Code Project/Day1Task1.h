#ifndef DAY1TASK1_H
#define DAY1TASK1_H

#pragma once
#include <Vector>
#include <string>
#include <fstream>
#include <sstream>
#include <array>

using namespace std;

namespace adventCoding
{
	class Day1Task1
	{
	public:
		std::vector<int> FindNumbersInString();

		static Day1Task1& getInstance()
		{
			static Day1Task1 instance;
			return instance;
		}

	};

}
#endif // !DAY1TASK1_H
