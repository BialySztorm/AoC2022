#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

std::string pair[2];
int tab[4];

void split(std::string str, char seperator);
void splitNum(std::string str[], char seperator);

int main()
{
    std::fstream input;
    std::string row = "";
    int result = 0;

    input.open("4.txt", std::ios::in);
    if (input.good())
        while (!input.eof())
        {
            std::getline(input, row);
            split(row, ',');
            splitNum(pair, '-');

            if (tab[0] <= tab[2] && tab[1] >= tab[2] || tab[0]<=tab[3]&& tab[1]>=tab[3]||tab[0]>=tab[2]&&tab[1]<=tab[3])
            {
                result++;
                // std::cout << tab[0] << "-" << tab[1] << "," << tab[2] << "-" << tab[3] << std::endl;
            }
        }
    input.close();

    std::cout << result;

    return 0;
}

void split(std::string str, char seperator)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    int separators = 0;
    while (i <= str.length())
    {
        if (str[i] == seperator || i == str.length())
        {
            endIndex = i;
            std::string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            pair[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}
void splitNum(std::string str[], char seperator)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    int separators = 0;
    while (i <= str[0].length())
    {
        if (str[0][i] == seperator || i == str[0].length())
        {
            endIndex = i;
            std::string subStr = "";
            subStr.append(str[0], startIndex, endIndex - startIndex);
            tab[currIndex] = stoi(subStr);
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
    i = 0;
    startIndex = 0;
    endIndex = 0;
    while (i <= str[1].length())
    {
        if (str[1][i] == seperator || i == str[1].length())
        {
            endIndex = i;
            std::string subStr = "";
            subStr.append(str[1], startIndex, endIndex - startIndex);
            tab[currIndex] = stoi(subStr);
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}