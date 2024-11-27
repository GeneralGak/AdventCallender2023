#ifndef DAY2TASK2_H
#define DAY2TASK2_H
#pragma once

#include <Vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>


using namespace std;

namespace adventCoding
{
	class Day2Task2
	{
	private:
		std::vector<std::string> colors{ "red", "green", "blue" };

	public:
		std::vector<int> FindPowerOfFewestCubes();

		static Day2Task2& getInstance()
		{
			static Day2Task2 instance;
			return instance;
		}
	};
}
#endif

