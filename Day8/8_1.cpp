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

int countVisibleTrees(const std::vector<std::vector<int>> &treeMap)
{
    int visibleTrees = 0;

    // Sprawdzanie drzew wewnątrz mapy
    for (int i = 0; i < treeMap.size(); i++)
    {
        for (int j = 0; j < treeMap[i].size(); j++)
        {
            bool isVisible = true;
            // Sprawdzanie każdej strony
            for (int k = 0; k < 4; k++)
            {
                isVisible = true;
                int x = i, y = j;
                int maxHeight = treeMap[i][j];
                if (k == 0)
                    x--;
                else if (k == 1)
                    x++;
                else if (k == 2)
                    y--;
                else
                    y++;
                // Przechodzenie do krawędzi
                while (x >= 0 && x < treeMap.size() && y >= 0 && y < treeMap[i].size())
                {
                    if (treeMap[x][y] >= treeMap[i][j])
                    {
                        isVisible = false;
                        break;
                    }
                    if (k == 0)
                        x--;
                    else if (k == 1)
                        x++;
                    else if (k == 2)
                        y--;
                    else
                        y++;
                }
                if (isVisible)
                    break;
            }
            if (isVisible)
                visibleTrees++;
        }
    }

    return visibleTrees;
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
    std::cout << "Visible trees: " << countVisibleTrees(treeMap) << std::endl;

    return 0;
}