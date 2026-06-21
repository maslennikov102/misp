#pragma once
#include <iostream>

template <typename T, int N>
class Array
{
public:
    T data[N];

    Array()
    {
        for (int i = 0; i < N; i++)
        {
            data[i] = T();
        }
    }

    Array(T value)
    {
        for (int i = 0; i < N; i++)
        {
            data[i] = value;
        }
    }

    int size()
    {
        return N;
    }

    T& operator[](int index)
    {
        return data[index];
    }

    friend std::ostream& operator<<(std::ostream& out, Array<T, N>& arr)
    {
        out << "[";
        for (int i = 0; i < N; i++)
        {
            out << arr.data[i];
            if (i < N - 1)
            {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }
};
