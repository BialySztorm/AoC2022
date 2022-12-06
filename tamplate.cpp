#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

int main()
{
    std::fstream input;
    std::string row = "";
    int result = 0;


    input.open("3.txt", std::ios::in);
    if (input.good())
        while (!input.eof())
        {
            std::getline(input, row);
            
        }
    input.close();

    std::cout << std::endl<<result;

    return 0;
}