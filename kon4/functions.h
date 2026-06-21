#pragma once
#include <string>
#include <vector>
#include <stdexcept>
 
template <typename T>
T min(T a, T b) 
{
    return a < b ? a : b;
}
 
template <typename T>
T sum(const std::vector<T>& arr) 
{
    if (arr.size() <= 0) 
    {
        throw std::invalid_argument("Array size must be > 0");
    }
    T result = 0;
    for (int i = 0; i < arr.size(); i++) 
    {
        result += arr[i];
    }
    return result;
}
 
template <typename T>
std::string serialize(T value) 
{
    return std::to_string(value);
}
 
template <>
std::string serialize<bool>(bool value) 
{
    return value ? "true" : "false";
}
