#include <iostream>
#include "Array.h"

int main()
{
    Array<int, 5> a;
    std::cout << "a: " << a << std::endl;

    // int массив, заполненный значением
    Array<int, 5> b(42);
    std::cout << "b: " << b << std::endl;

    // оператор []
    b[0] = 10;
    b[4] = 99;
    std::cout << "after b[0]=10, b[4]=99: " << b << std::endl;
    std::cout << "b[2] = " << b[2] << std::endl;
    std::cout << "size b: " << b.size() << std::endl;

    // double массив
    Array<double, 3> c(3.14);
    std::cout << "c: " << c << std::endl;

    // string массив
    Array<std::string, 4> d("hello");
    d[1] = "world";
    std::cout << "d: " << d << std::endl;

    return 0;
}
