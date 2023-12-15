#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>

const std::string DAY = "11";

struct Monkey
{
    int id;
    std::vector<long long> items;
    std::pair<char, int> operation;
    long long divisibleBy;
    std::pair<int, int> returns;
    long long inspectedItems = 0;

    Monkey(int id, std::vector<long long> startingItems, std::pair<char, int> operation, long long divisibleBy, std::pair<int, int> returns)
    {
        this->id = id;
        this->items = startingItems;
        this->operation = operation;
        this->divisibleBy = divisibleBy;
        this->returns = returns;
    }

    long long Operation(long long a)
    {
        if (operation.second != 'o' - '0')
        {
            if (operation.first == '+')
                return a + operation.second;
            else if (operation.first == '-')
                return a - operation.second;
            else if (operation.first == '*')
                return a * operation.second;
            else if (operation.first == '/')
                return a / operation.second;
            else
                return a;
        }
        else
        {
            if (operation.first == '+')
                return a + a;
            else if (operation.first == '-')
                return a - a;
            else if (operation.first == '*')
                return a * a;
            else if (operation.first == '/')
                return a / a;
            else
                return a;
        }
    }

    int Test(long long a)
    {
        if (a % divisibleBy == 0) // divisible
            return returns.first;
        else // not divisible
            return returns.second;
    }
    void Print()
    {
        std::cout << "Monkey " << id << std::endl;
        std::cout << "Items: ";
        for (int i = 0; i < items.size(); i++)
            std::cout << items[i] << " ";
        std::cout << std::endl;
        std::cout << "Operation: " << operation.first << " " << operation.second << std::endl;
        std::cout << "Divisible by: " << divisibleBy << std::endl;
        std::cout << "Returns: " << returns.first << " " << returns.second << std::endl;
    }
    long long getBored(double a)
    {
        return std::floor(a / 3.0);
    }
};

std::vector<long long> splitString(std::string str, std::string delimiter)
{
    std::vector<long long> result;
    int pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos)
    {
        token = str.substr(0, pos);
        result.push_back(std::stoi(token));
        str.erase(0, pos + delimiter.length());
    }
    result.push_back(std::stoi(str));
    return result;
}

std::vector<Monkey> getMonkeys(std::vector<std::string> rows)
{
    std::vector<Monkey> monkeys;

    for (int i = 0; i < rows.size(); i++)
    {
        int id = rows[i][7] - '0';
        std::string startingItems = rows[++i].substr(18, rows[i].size() - 18);
        char operationFirst = rows[++i][23];
        int operationSecond;
        std::string operationSecondTmp = rows[i].substr(25, rows[i].size() - 25);
        if (operationSecondTmp[0] == 'o')
            operationSecond = 'o' - '0';
        else
            operationSecond = std::stoi(operationSecondTmp);
        int divisibleBy = std::stoi(rows[++i].substr(21, rows[i].size() - 21));
        int returnsFirst = rows[++i][29] - '0';
        int returnsSecond = rows[++i][30] - '0';
        monkeys.push_back(Monkey(id, splitString(startingItems, ", "), {operationFirst, operationSecond}, divisibleBy, {returnsFirst, returnsSecond}));
        // monkeys[i / 7].Print();
        i++;
    }

    return monkeys;
}

void handleRound(std::vector<Monkey> &monkeys, long long mod)
{
    for (Monkey &monkey : monkeys)
    {
        while (monkey.items.size() > 0)
        {
            long long item = monkey.items[0];
            monkey.items.erase(monkey.items.begin());
            monkey.inspectedItems++;
            long long result = monkey.Operation(item) % mod; //! that's all changes i make for part 2
            monkeys[monkey.Test(result)].items.push_back(result);
        }
    }
    // system("pause");
}

long long multiplyBiggestInspections(std::vector<Monkey> monkeys)
{
    long long result = 1;
    int max = 0;
    int maxIndex = 0;
    for (int i = 0; i < monkeys.size(); i++)
    {
        if (monkeys[i].inspectedItems > max)
        {
            max = monkeys[i].inspectedItems;
            maxIndex = i;
        }
        // std::cout << monkeys[i].inspectedItems << std::endl;
    }
    result *= monkeys[maxIndex].inspectedItems;
    monkeys.erase(monkeys.begin() + maxIndex);
    max = 0;
    maxIndex = 0;
    for (int i = 0; i < monkeys.size(); i++)
    {
        if (monkeys[i].inspectedItems > max)
        {
            max = monkeys[i].inspectedItems;
            maxIndex = i;
        }
    }
    result *= monkeys[maxIndex].inspectedItems;
    return result;
}

int main()
{
    std::fstream input;
    int result = 0;
    std::vector<std::string> rows;

    input.open(DAY + ".txt", std::ios::in);
    if (input.good())
    {
        std::string row = "";
        while (std::getline(input, row))
        {
            rows.push_back(row);
        }
    }
    input.close();

    std::vector<Monkey> monkeys = getMonkeys(rows);
    // for(Monkey monkeys: monkeys)
    //     monkeys.Print();
    long long mod = 1;
    for (Monkey &monkey : monkeys)
            mod *= monkey.divisibleBy;

    for (int i = 0; i < 10000; i++)
    {
        // std::cout << "Round " << i + 1 << std::endl;
        // for (Monkey &monkey : monkeys)
        // {
        //     for (int j = 0; j < monkey.items.size(); j++)
        //     {
        //         std::cout << monkey.items[j] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << std::endl;
        // std::cout << std::endl;
        handleRound(monkeys, mod);
    }

    std::cout << "Monkey business: " << multiplyBiggestInspections(monkeys) << std::endl;

    // system("pause");
    return 0;
}