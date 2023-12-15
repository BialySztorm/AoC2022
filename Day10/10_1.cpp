#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>

const std::string DAY = "10";

int main()
{
    std::fstream input;
    long long result = 0;
    std::vector<std::string> instructions;

    input.open(DAY + ".txt", std::ios::in);
    if (input.good())
    {
        std::string row = "";
        while (std::getline(input, row))
        {
            instructions.push_back(row);
        }
    }
    input.close();

    int cycle = 0;
    long long current = 1;
    for (std::string instruction : instructions)
    {
        if (instruction == "noop")
        {
            cycle++;
            if ((cycle - 20) % 40 == 0)
            {
                result += current * cycle;
            }
        }
        else
        {
            for (int i = 0; i < 2; i++)
            {
                cycle++;
                if ((cycle - 20) % 40 == 0)
                {
                    result += current * cycle;
                }
            }
            current+=std::stoi(instruction.substr(5, instruction.length() - 5));
        }
    }

    std::cout << result << std::endl;

    // system("pause");
    return 0;
}