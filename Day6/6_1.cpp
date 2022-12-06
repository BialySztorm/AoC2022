#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

int main()
{
    std::fstream input;
    std::string row = "";
    char tab[4];
    int result = 0, index = 0;

    input.open("6.txt", std::ios::in);
    if (input.good())
    {
        std::getline(input, row);
        for (int i = 0; i < row.length(); i++)
        {
            result++;
            tab[index++] = row[i];
            if (i >= 3)
            {
                if (index > 3)
                {
                    index = 0;
                    // std::cout << i;
                }
                if (tab[0] != tab[1] && tab[0] != tab[2] && tab[0] != tab[3] && tab[1] != tab[2] && tab[1] != tab[3] && tab[2] != tab[3])
                    break;
            }
        }
    }
    input.close();
    for(int i = 0; i<4; i++)
    {
        std::cout<<tab[i]<<", ";
    }

    std::cout << std::endl
              << result;

    return 0;
}