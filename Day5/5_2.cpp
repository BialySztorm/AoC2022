#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

int tab[3] = {0, 0, 0};

void splitNum(std::string str, char seperator);

int main()
{
    std::fstream input;
    std::string row = "", stacks[] = {"", "", "", "", "", "", "", "", ""}, result = "";

    input.open("5.txt", std::ios::in);
    if (input.good())
    {
        while (!input.eof())
        {
            std::getline(input, row);

            if (row == "")
            {
                break;
            }
            else
            {
                for (int i = 0; i < 9; i++)
                {
                    if (row[i * 4 + 1] != ' ')
                    {
                        stacks[i] = row[i * 4 + 1] + stacks[i];
                    }
                }
            }
        }
        // for(int i = 0; i<9; i++){
        //     std::cout<<stacks[i]<<std::endl;
        // }
        while (!input.eof())
        {
            std::getline(input, row);
            splitNum(row, ' ');
            // std::cout<<tab[0];
            std::string tmp = stacks[tab[1] - 1].substr(stacks[tab[1]-1].length()-tab[0], tab[0]);
            // std::cout<<tmp<<", ";
            stacks[tab[1] - 1] = stacks[tab[1] - 1].substr(0, stacks[tab[1] - 1].length() -tab[0]);
            stacks[tab[2] - 1] += tmp;
        }
        // for(int i = 0; i<9; i++){
        //     std::cout<<stacks[i]<<std::endl;
        // }
    }
    input.close();

    for (int i = 0; i < 9; i++)
    {
        result += stacks[i][stacks[i].length() - 1];
    }

    std::cout << std::endl
              << result;

    return 0;
}

void splitNum(std::string str, char seperator)
{
    int currIndex = 1, i = 0;
    int startIndex = 0, endIndex = 0;
    int separators = 0;
    while (i <= str.length())
    {
        if (str[i] == seperator || i == str.length())
        {
            endIndex = i;
            std::string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            // std::cout<<subStr;
            if (!(currIndex % 2))
                tab[currIndex / 2 - 1] = stoi(subStr);
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}