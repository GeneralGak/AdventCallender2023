#pragma once
#include <Vector>
#include <string>
#include <fstream>
#include <sstream>

namespace adventCoding 
{
	class GeneralUse
	{
	public:
		std::vector<std::string> GetTextFromFile(std::string _textName);
		int CalculateSum(std::vector<int> _numbersToCalculate);

		static GeneralUse& getInstance()
		{
			static GeneralUse instance;
			return instance;
		}
	};
}


