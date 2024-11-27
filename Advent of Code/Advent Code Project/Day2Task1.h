#ifndef DAY2TASK1_H
#define DAY2TASK1_H
#pragma once

#include <Vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>


using namespace std;

namespace adventCoding 
{
	class Day2Task1
	{
	private:
		std::vector<std::string> colors{"red", "green", "blue"};
		std::map<std::string, int> colorsInBag
		{
			{"red", 12},
			{"green", 13},
			{"blue", 14}
		};

	public:
		std::vector<int> FindPosibleGames();

		static Day2Task1& getInstance()
		{
			static Day2Task1 instance;
			return instance;
		}
	};
}
#endif