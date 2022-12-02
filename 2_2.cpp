#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <map>

//! A - Rock 1
//! B - Paper 2
//! C - Scissors 3
//! X - lose
//! Y - draw
//! Z - win

int main()
{
    std::map<std::string, int> score = {{"AX", 3}, {"AY", 1}, {"AZ", 2}, {"BX", 1}, {"BY", 2}, {"BZ", 3}, {"CX", 2}, {"CY", 3}, {"CZ", 1}};
    std::fstream input;
    std::string row = "", rowScore = "";
    char rowCh[2] = {'A', 'X'};
    int result = 0;

    input.open("2.txt", std::ios::in);
    if (input.good())
        while (!input.eof())
        {
            std::getline(input, row);
            rowCh[0] = row[0];
            rowCh[1] = row[2];
            rowScore = "";
            rowScore.push_back(rowCh[0]);
            rowScore.push_back(rowCh[1]);
            result += score[rowScore];
            if (rowCh[1] == 'Y')
                result += 3;
            else if (rowCh[1] == 'Z')
                result += 6;
        }
    input.close();

    std::cout << result;

    return 0;
}