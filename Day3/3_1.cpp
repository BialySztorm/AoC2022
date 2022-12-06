#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

int main()
{
    std::fstream input;
    std::string row = "", firstCom = "", secondCom = "";
    int result = 0, comLen = 0;
    bool isCheck = 0;

    input.open("3.txt", std::ios::in);
    if (input.good())
        while (!input.eof())
        {
            std::getline(input, row);
            comLen = row.length() / 2;

            firstCom = row.substr(0, comLen);
            secondCom = row.substr(comLen, comLen);
            // std::cout<<firstCom<<", "<<secondCom<<std::endl;
            for (int i = 0; i < comLen; i++)
            {
                for (int j = 0; j < comLen; j++)
                {
                    if (firstCom[i] == secondCom[j])
                    {
                        if (int(firstCom[i]) > 95)
                        {
                            result += firstCom[i] - 96;
                        }
                        else
                        {
                            result += firstCom[i] - 38;
                        }
                        // std::cout<< firstCom[i]<<", ";
                        // std::cout<<result<<", ";
                        isCheck = 1;
                        break;
                    }
                }
                if(isCheck) break;
            }
            isCheck = 0;
            // break;
        }
    input.close();

    std::cout << std::endl<<result;

    return 0;
}