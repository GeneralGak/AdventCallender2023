#include "Day1Task1.h"
#include "iostream"
#include "GeneralUse.h"


namespace adventCoding 
{
    /// <summary>
    /// Find the first and last digit in a number of strings 
    /// to form a two digit number.
    /// </summary>
    /// <returns></returns> Vector containing two digit numbers from all strings
    std::vector<int> Day1Task1::FindNumbersInString()
    {
        std::vector<int> result;
        std::vector<std::string> taskText = GeneralUse::getInstance().GetTextFromFile("Day1.txt");

        for (int i = 0; i < taskText.size(); i++)
        {
            char numberChar[2] {'-1', '-1'};
            char numberCharacter = ' ';
            bool isFirst = false;
            std::string currentString = taskText[i];
            for (int j = 0; j < currentString.length(); j++)
            {
                if (isdigit(currentString[j])) 
                {
                    if (isFirst == false) 
                    {
                        numberChar[0] = currentString[j];
                        isFirst = true;
                    }
                    else if (isFirst == true) 
                    {
                        numberCharacter = currentString[j];
                    }
                }
            }

            if (numberCharacter == ' ') numberChar[1] = numberChar[0];
            else numberChar[1] = numberCharacter;

            if (numberChar[0] == '-1' || numberChar[1] == '-1') std::cout << "No numbers found";

            int value = stoi(numberChar);

            //std::cout << static_cast<unsigned>(value) << std::endl;

            result.push_back(value);
        }

        return result;
    }
}


