#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <map>

//! A & X - Rock
//! B & Y - Paper
//! C & Z - Scissors

int main()
{
    std::map<char, int> score = {{'X', 1}, {'Y', 2}, {'Z', 3}};
    std::fstream input;
    std::string row = "";
    char rowCh[2] = {'A', 'X'};
    int result = 0;

    input.open("2.txt", std::ios::in);
    if (input.good())
        while (!input.eof())
        {
            std::getline(input, row);
            rowCh[0] = row[0];
            rowCh[1] = row[2];
            result += score[rowCh[1]];
            if (rowCh[0] == 'A')
            {
                if (rowCh[1] == 'X')
                    result += 3;
                else if (rowCh[1] == 'Y')
                    result += 6;
            }
            else if (rowCh[0] == 'B')
            {
                if (rowCh[1] == 'Y')
                    result += 3;
                else if (rowCh[1] == 'Z')
                    result += 6;
            }
            else if (rowCh[0] == 'C')
            {
                if (rowCh[1] == 'Z')
                    result += 3;
                else if (rowCh[1] == 'X')
                    result += 6;
            }
        }
    input.close();

    std::cout << result;

    return 0;
}