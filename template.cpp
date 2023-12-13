#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

const std::string DAY = "0";

int main()
{
    std::fstream input;
    std::string row = "";
    int result = 0;

    input.open(DAY + ".txt", std::ios::in);
    if (input.good())
        while (std::getline(input, row))
        {
        }
    input.close();

    std::cout << result << std::endl;

    // system("pause");
    return 0;
}