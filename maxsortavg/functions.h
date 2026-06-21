#pragma once
#include <string>
#include <vector>
#include <cctype>

template <typename T>
T findMax(std::vector<T>& arr)
{
    T max = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

template <>
std::string findMax<std::string>(std::vector<std::string>& arr)
{
    std::string max = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        std::string a = arr[i];
        std::string b = max;
        for (char& c : a) c = tolower(c);
        for (char& c : b) c = tolower(c);
        if (a > b)
        {
            max = arr[i];
        }
    }
    return max;
}

template <typename T>
void sortArr(std::vector<T>& arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                T tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

template <>
void sortArr<std::string>(std::vector<std::string>& arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            std::string a = arr[j];
            std::string b = arr[j + 1];
            for (char& c : a) c = tolower(c);
            for (char& c : b) c = tolower(c);
            if (a > b)
            {
                std::string tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

template <typename T>
double findAverage(std::vector<T>& arr)
{
    double sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return sum / arr.size();
}

template <>
double findAverage<std::string>(std::vector<std::string>& arr)
{
    double sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i].size();
    }
    return sum / arr.size();
}
