#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

int main()
{
    std::fstream input;
    std::string row = "";
    char tab[14];
    int result = 0, index = 0;
    bool isBad = 0;

    input.open("6.txt", std::ios::in);
    if (input.good())
    {
        std::getline(input, row);
        for (int i = 0; i < row.length(); i++)
        {
            result++;
            tab[index++] = row[i];
            if (i >= 13)
            {
                if (index > 13)
                {
                    index = 0;
                    // std::cout << i;
                }
                for (int j = 0; j < 14; j++)
                {
                    for(int k = j+1; k<14; k++)
                    {
                        if(tab[j] == tab[k])
                            isBad = 1;
                    }
                }
                if(isBad){
                    isBad = 0;
                }
                else
                {
                    break;
                }
            }
        }
    }
    input.close();
    for (int i = 0; i < 14; i++)
    {
        std::cout << tab[i] << ", ";
    }

    std::cout << std::endl
              << result;

    return 0;
}