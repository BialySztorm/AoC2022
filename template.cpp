#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>

const std::string DAY = "0";

int main()
{
    std::fstream input;
    int result = 0;

    input.open(DAY + ".txt", std::ios::in);
    if (input.good())
    {
        std::string row = "";
        while (std::getline(input, row))
        {
        }
    }
    input.close();

    std::cout << result << std::endl;

    // system("pause");
    return 0;
}