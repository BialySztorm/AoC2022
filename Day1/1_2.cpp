#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main()
{
    std::vector<int> tab = {0};
    std::fstream input;
    std::string row = "";
    int i = 0, maxTab[] = {0, 0, 0}, max = 0;

    input.open("1.txt", std::ios::in);
    if (input.good())
        while (!input.eof())
        {
            std::getline(input, row);
            if (row == "")
            {
                i++;
                tab.push_back(0);
            }
            else
            {
                tab[i] += std::stoi(row);
            }
        }
    input.close();
    for (int k = 0; k < 3; k++)
        for (int j = 0; j <= i; j++)
        {
            if (k == 0)
            {
                if (maxTab[k] < tab[j])
                    maxTab[k] = tab[j];
            }
            else if (k == 1)
            {
                if (maxTab[k] < tab[j] && tab[j] != maxTab[0])
                    maxTab[k] = tab[j];
            }
            else if (k == 2)
            {
                if (maxTab[k] < tab[j] && tab[j] != maxTab[0] && tab[j] != maxTab[1])
                    maxTab[k] = tab[j];
            }
        }
    max = maxTab[0] + maxTab[1] + maxTab[2];
    std::cout << max;

    return 0;
}