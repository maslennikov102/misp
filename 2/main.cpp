#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "functions.h"

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
        std::cout << "error file" << std::endl;
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

        std::cout << "array " << lineNum << ": ";
        for (int i = 0; i < arr.size(); i++) 
	{
            std::cout << arr[i];
            if (i < arr.size() - 1) std::cout << " ";
        }
        std::cout << std::endl;
        if (arr.size() >= 2) 
	{
            std::cout << "min(" << arr[0] << ", " << arr[1] << ") = " << min(arr[0], arr[1]) << std::endl;
        }
        try 
	{
            std::cout << "sum = " << sum(arr) << std::endl;
        } 
	catch (std::invalid_argument& e) 
	{
            std::cout << "sum error: " << e.what() << std::endl;
        }
        std::cout << "serialize(" << arr[0] << ") = " << serialize(arr[0]) << std::endl;
        std::cout << "serialize(true) = " << serialize(true) << std::endl;
        std::cout << "serialize(false) = " << serialize(false) << std::endl;

        std::cout << std::endl;
        lineNum++;
    }

    file.close();
    return 0;
}
