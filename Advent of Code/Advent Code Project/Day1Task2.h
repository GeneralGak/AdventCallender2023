#ifndef DAY1TASK2_H
#define DAY1TASK2_H

#pragma once
#include <Vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

namespace adventCoding 
{
	class Day1Task2
	{
	private:
		std::map<std::string, char> spelledNumToNum
		{
			{"one", '1'},
			{"two", '2'},
			{"three", '3'},
			{"four", '4'},
			{"five", '5'},
			{"six", '6'},
			{"seven", '7'},
			{"eight", '8'},
			{"nine", '9'}
		};

	public:
		std::vector<int> FindNumberInWordsAndDigits();

		static Day1Task2& getInstance()
		{
			static Day1Task2 instance;
			return instance;
		}
	};
}
#endif // !DAY1TASK2_H

