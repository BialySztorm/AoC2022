#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
#include <set>

const std::string DAY = "9";

int sign(int x) {
    return (x < 0) ? -1 : 1;
}

int main()
{
    std::fstream input;
    int result = 0;
    std::vector<std::pair<char, int>> instructions;
    std::vector<std::vector<char>> map = {{'S'}};

    input.open(DAY + ".txt", std::ios::in);
    if (input.good())
    {
        std::string row = "";
        while (std::getline(input, row))
        {
            char command = row[0];
            int value = std::stoi(row.substr(1));
            instructions.push_back(std::make_pair(command, value));
        }
    }
    input.close();
    int n_knots = 10;  // Part 2
    std::pair<int,int> pos_h = {0, 0};
    std::vector<std::pair<int,int> > pos_ts(n_knots - 1, {0, 0});
    std::vector<std::set<std::pair<int,int> >> history_ts(n_knots - 1);

    for (auto instruction : instructions) {
        std::pair<int,int>  d;
        switch (instruction.first) {
            case 'R': d = {1, 0}; break;
            case 'L': d = {-1, 0}; break;
            case 'U': d = {0, 1}; break;
            case 'D': d = {0, -1}; break;
        }

        for (int i = 0; i < instruction.second; i++) {
            pos_h = {pos_h.first + d.first, pos_h.second + d.second};
            std::pair<int,int>  pos_pred = pos_h;

            for (int i = 0; i < history_ts.size(); i++) {
                int x = pos_ts[i].first, y = pos_ts[i].second;
                int dx = x - pos_pred.first, dy = y - pos_pred.second;

                if ((std::abs(dx) > 0 && std::abs(dy) > 1) || (std::abs(dx) > 1 && std::abs(dy) > 0)) {
                    pos_ts[i] = {x - sign(dx), y - sign(dy)};
                } else if (std::abs(dx) > 1) {
                    pos_ts[i] = {x - sign(dx), y};
                } else if (std::abs(dy) > 1) {
                    pos_ts[i] = {x, y - sign(dy)};
                }

                pos_pred = pos_ts[i];
                history_ts[i].insert(pos_ts[i]);
            }
        }
    }

    std::cout << history_ts.back().size() << std::endl;

    // system("pause");
    return 0;
}