#include "GeneralUse.h"

namespace adventCoding
{
    std::vector<std::string> adventCoding::GeneralUse::GetTextFromFile(std::string _textName)
    {
        std::vector<std::string> result;

        std::ifstream textFile(_textName);

        std::string content;
        content.assign((std::istreambuf_iterator<char>(textFile)),
            (std::istreambuf_iterator<char>()));


        std::stringstream stringIterator(content);

        for (std::string line; std::getline(stringIterator, line, '\n');)
        {
            result.push_back(line);
        }

        return result;
    }

    int GeneralUse::CalculateSum(std::vector<int> _numbersToCalculate)
    {
        int result = 0;

        for (int i = 0; i < _numbersToCalculate.size(); i++)
        {
            result += _numbersToCalculate[i];
        }

        return result;
    }
}