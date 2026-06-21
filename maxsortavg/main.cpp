#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "functions.h"

void printArr(std::vector<int>& arr)
{
    std::cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << ", ";
    }
    std::cout << "]";
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cout << "error file: " << argv[1] << std::endl;
        return 1;
    }

    std::string line;
    int lineNum = 1;

    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        std::vector<int> arr;
        std::istringstream ss(line);
        int num;
        while (ss >> num)
        {
            arr.push_back(num);
        }

        if (arr.empty()) continue;

        std::cout << "array " << lineNum << ": ";
        printArr(arr);
        std::cout << std::endl;

        std::cout << "max:     " << findMax(arr) << std::endl;
        std::cout << "avg: " << findAverage(arr) << std::endl;

        sortArr(arr);
        std::cout << "sorted:  ";
        printArr(arr);
        std::cout << std::endl << std::endl;

        lineNum++;
    }

    file.close();
    return 0;
}
