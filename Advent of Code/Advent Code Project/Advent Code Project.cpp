// Advent Code Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Vector>
#include <string>
#include <Day1Task1.h>
#include <Day1Task2.h>
#include <Day2Task1.h>
#include <Day2Task2.h>
#include <Day3Task1.h>
#include <Day3Task2.h>
#include <GeneralUse.h>

using namespace adventCoding;
using namespace std;

int main()
{
    int calculatedNumber = GeneralUse::getInstance().CalculateSum(Day1Task1::getInstance().FindNumbersInString());
    std::cout << "Day 1 Task 1 result: " << static_cast<unsigned>(calculatedNumber) << std::endl;

    calculatedNumber = GeneralUse::getInstance().CalculateSum(Day1Task2::getInstance().FindNumberInWordsAndDigits());
    std::cout << "Day 1 Task 2 result: " << static_cast<unsigned>(calculatedNumber) << std::endl;

    calculatedNumber = GeneralUse::getInstance().CalculateSum(Day2Task1::getInstance().FindPosibleGames());
    std::cout << "Day 2 Task 1 result: " << static_cast<unsigned>(calculatedNumber) << std::endl;

    calculatedNumber = GeneralUse::getInstance().CalculateSum(Day2Task2::getInstance().FindPowerOfFewestCubes());
    std::cout << "Day 2 Task 2 result: " << static_cast<unsigned>(calculatedNumber) << std::endl;

    calculatedNumber = GeneralUse::getInstance().CalculateSum(Day3Task1::getInstance().FindAllPartNumbers());
    std::cout << "Day 3 Task 1 result: " << static_cast<unsigned>(calculatedNumber) << std::endl;

    calculatedNumber = GeneralUse::getInstance().CalculateSum(Day3Task2::getInstance().FindAllGearRatios());
    std::cout << "Day 3 Task 2 result: " << static_cast<unsigned>(calculatedNumber) << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
