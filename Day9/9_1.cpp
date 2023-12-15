#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>

const std::string DAY = "9";

void printMap(std::vector<std::vector<char>> map)
{
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
}

void drawMapForCommands(std::vector<std::pair<char, int>> commands, std::vector<std::vector<char>> &map)
{
    std::pair<int, int> head = {0, 0}, tail = {0, 0}, previousHead = {0, 0};

    for (std::pair<char, int> command : commands)
    {
        switch (command.first)
        {
        case 'U':
            for (int i = 0; i < command.second; i++)
            {
                previousHead = head;
                head.first++;
                if (head.first >= map.size())
                {
                    map.push_back(std::vector<char>(map[0].size(), '.'));
                }
                if (std::abs(head.first - tail.first) > 1 || std::abs(head.second - tail.second) > 1)
                {
                    tail = previousHead;
                    map[tail.first][tail.second] = '#';
                }
            }
            break;
        case 'D':
            for (int i = 0; i < command.second; i++)
            {
                previousHead = head;
                head.first--;
                if (head.first < 0)
                {
                    map.insert(map.begin(), std::vector<char>(map[0].size(), '.'));
                    head.first = 0;
                    previousHead.first++;
                    tail.first++;
                }
                if (std::abs(head.first - tail.first) > 1 || std::abs(head.second - tail.second) > 1)
                {
                    tail = previousHead;
                    map[tail.first][tail.second] = '#';
                }
            }
            break;
        case 'R':
            for (int i = 0; i < command.second; i++)
            {
                previousHead = head;
                head.second++;
                if (head.second >= map[0].size())
                {
                    for (int j = 0; j < map.size(); j++)
                    {
                        map[j].push_back('.');
                    }
                }
                if (std::abs(head.first - tail.first) > 1 || std::abs(head.second - tail.second) > 1)
                {
                    tail = previousHead;
                    map[tail.first][tail.second] = '#';
                }
            }
            break;
        case 'L':
            for (int i = 0; i < command.second; i++)
            {
                previousHead = head;
                head.second--;
                if (head.second < 0)
                {
                    for (int j = 0; j < map.size(); j++)
                    {
                        map[j].insert(map[j].begin(), '.');
                    }
                    head.second = 0;
                    previousHead.second++;
                    tail.second++;
                }
                if (std::abs(head.first - tail.first) > 1 || std::abs(head.second - tail.second) > 1)
                {
                    tail = previousHead;
                    map[tail.first][tail.second] = '#';
                }
            }
            break;
        default:
            break;
        }
    }
}

long long countHashes(std::vector<std::vector<char>> map)
{
    long long result = 0;
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            if (map[i][j] == '#' || map[i][j] == 'S')
            {
                result++;
            }
        }
    }
    return result;
}

int main()
{
    std::fstream input;
    int result = 0;
    std::vector<std::pair<char, int>> commands;
    std::vector<std::vector<char>> map = {{'S'}};

    input.open(DAY + ".txt", std::ios::in);
    if (input.good())
    {
        std::string row = "";
        while (std::getline(input, row))
        {
            char command = row[0];
            int value = std::stoi(row.substr(1));
            commands.push_back(std::make_pair(command, value));
        }
    }
    input.close();
    drawMapForCommands(commands, map);
    std::cout << map.size() << " " << map[0].size() << std::endl;
    printMap(map);

    std::cout << countHashes(map) << std::endl;

    // system("pause");
    return 0;
}