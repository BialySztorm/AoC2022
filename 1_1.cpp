#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main()
{
    std::vector<int> tab = {0};
    std::fstream input;
    std::string row = "";
    int i = 0, max = 0;

    input.open("1.txt", std::ios::in);
    if (input.good())
        while (!input.eof())
        {
            std::getline(input, row);
            // std::cout<<row<<" ";
            if(row==""){
                i++;
                tab.push_back(0);
            }
            else{
                tab[i]+=std::stoi(row);
            }
        }
    input.close();
    for(int j = 0; j<=i; j++){
        if(max<tab[j])
            max = tab[j];
    }
    std::cout<<max;

    return 0;
}