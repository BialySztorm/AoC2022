#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void printMap(std::vector<std::vector<int>> treeMap)
{
    for (std::vector<int> row : treeMap)
    {
        std::cout << "[";
        for (int i : row)
        {
            std::cout << i << ", ";
        }
        std::cout << "]";
        std::cout << std::endl;
    }
}

long long findHighestScenicScore(const std::vector<std::vector<int>> &treeMap)
{
    long long highestScenicScore = 0;

    // Sprawdzanie drzew wewnątrz mapy
    for (int i = 0; i < treeMap.size(); i++)
    {
        for (int j = 0; j < treeMap[i].size(); j++)
        {
            // Sprawdzanie każdej strony
            long long scenicScore = 1;
            for (int k = 0; k < 4; k++)
            {
                int x = i, y = j;
                int maxHeight = treeMap[i][j];
                long long currentScenicScore = 1;
                if (k == 0)
                    x--;
                else if (k == 1)
                    x++;
                else if (k == 2)
                    y--;
                else
                    y++;
                // Przechodzenie do krawędzi
                while (x > 0 && x < treeMap.size() - 1 && y > 0 && y < treeMap[i].size() - 1)
                {
                    if (treeMap[x][y] >= treeMap[i][j])
                    {
                        break;
                    }
                    currentScenicScore++;
                    if (k == 0)
                        x--;
                    else if (k == 1)
                        x++;
                    else if (k == 2)
                        y--;
                    else
                        y++;
                }
                scenicScore *= currentScenicScore;
            }
            if (highestScenicScore < scenicScore)
                highestScenicScore = scenicScore;
        }
    }

    return highestScenicScore;
}

int main()
{
    std::fstream input;
    std::string row = "";
    std::vector<std::vector<int>> treeMap; // map of tree heights

    input.open("8.txt", std::ios::in);
    if (input.good())
    {
        while (std::getline(input, row))
        {
            std::vector<int> rowVector;
            for (int i = 0; i < row.length(); i++)
            {
                rowVector.push_back(row[i] - '0');
            }
            treeMap.push_back(rowVector);
        }
    }
    input.close();

    // printMap(treeMap);
    std::cout << "Highest scenic score: " << findHighestScenicScore(treeMap) << std::endl;

    return 0;
}