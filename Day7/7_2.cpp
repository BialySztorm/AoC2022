#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct File
{
    std::string name;
    int weight;
};

struct Dir
{
    std::string name;
    std::vector<Dir> subdirs;
    std::vector<File> files;
    int weight;
};

void addDir(Dir &dir, std::vector<std::string> localization, std::string name)
{
    if (localization.size() == 0)
    {
        Dir newDir = {name, {}, {}};
        dir.subdirs.push_back(newDir);
    }
    else
    {
        for (Dir &subdir : dir.subdirs)
        {
            if (subdir.name == localization[0])
            {
                localization.erase(localization.begin());
                addDir(subdir, localization, name);
            }
        }
    }
}

void addFile(Dir &dir, std::vector<std::string> localization, std::string name, int weight)
{
    if (localization.size() == 0)
    {
        File newFile = {name, weight};
        dir.files.push_back(newFile);
    }
    else
    {
        for (Dir &subdir : dir.subdirs)
        {
            if (subdir.name == localization[0])
            {
                localization.erase(localization.begin());
                addFile(subdir, localization, name, weight);
            }
        }
    }
    dir.weight += weight;
}

void printTree(Dir dir, int depth)
{
    for (int i = 0; i < depth; i++)
        std::cout << "   ";
    std::cout << "dir " << dir.name << " " << dir.weight << std::endl;
    for (Dir subdir : dir.subdirs)
    {
        printTree(subdir, depth + 1);
    }
    for (File file : dir.files)
    {
        for (int i = 0; i < depth + 1; i++)
            std::cout << "   ";
        std::cout << file.name << " " << file.weight << std::endl;
    }
}

int findSizeOfSmallestDir(Dir dir, int minSize)
{
    int min = 1000000000;
    if (dir.weight >= minSize)
    {
        if (dir.weight < min)
            min = dir.weight;
    }
    for (Dir subdir : dir.subdirs)
    {
        int size = findSizeOfSmallestDir(subdir, minSize);
        if (size < min)
            min = size;
    }
    return min;
}

int main()
{
    std::fstream input;
    std::vector<std::string> rows;

    input.open("7.txt", std::ios::in);
    if (input.good())
    {
        std::string row;
        while (getline(input, row))
        {
            rows.push_back(row);
        }
    }
    input.close();
    Dir root = {"root", {}, {}};
    std::vector<std::string> localization;
    for (std::string row : rows)
    {
        if (row[0] == '$')
        {
            if (row[2] == 'c') // for cd
            {
                if (row[5] == '/')
                    localization.clear();
                else if (row[5] == '.')
                    localization.pop_back();
                else
                {
                    std::string dirName = row.substr(5, row.size() - 5);
                    localization.push_back(dirName);
                }
            }
            // skipping ls, cause it's not needed
        }
        else
        {
            if (row[0] == 'd') // for dir
            {
                std::string dirName = row.substr(4, row.size() - 4);
                addDir(root, localization, dirName);
            }
            else
            {
                int weight = std::stoi(row.substr(0, row.find(' ')));
                std::string fileName = row.substr(row.find(' ') + 1, row.size() - row.find(' ') - 1);
                addFile(root, localization, fileName, weight);
            }
        }
    }

    // printTree(root, 0);

    std::cout << "Drive C: " << root.weight << "/70000000" << std::endl;
    int requiredSpace = root.weight-(70000000-30000000);
    std::cout << "Required space for update: "<< requiredSpace << std::endl;
    std::cout << "Smallest file: " << findSizeOfSmallestDir(root, requiredSpace) << std::endl;

    return 0;
}