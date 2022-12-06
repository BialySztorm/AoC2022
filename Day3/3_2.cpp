#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

int main()
{
    std::fstream input;
    std::string row[] = {"", "", ""};
    int result = 0, rowLen[] = {0, 0, 0}, index = 0;
    bool isCheck = 0;

    input.open("3.txt", std::ios::in);
    if (input.good())
        while (!input.eof())
        {
            std::getline(input, row[index]);
            rowLen[index] = row[index].length();
            if (++index == 3)
            {

                for (int i = 0; i < rowLen[0]; i++)
                {
                    for (int j = 0; j < rowLen[1]; j++)
                    {
                        for (int k = 0; k < rowLen[2]; k++)
                        {
                            if (row[0][i] == row[1][j] && row[1][j] == row[2][k])
                            {
                                if (int(row[0][i]) > 95)
                                {
                                    result += row[0][i] - 96;
                                }
                                else
                                {
                                    result += row[0][i] - 38;
                                }
                                isCheck = 1;
                                break;
                            }
                        }
                        if (isCheck)
                            break;
                    }
                    if (isCheck)
                        break;
                }
                isCheck = 0;
                index = 0;
            }
        }
    input.close();

    std::cout << std::endl
              << result;

    return 0;
}