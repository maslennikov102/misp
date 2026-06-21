#include <iostream>
#include "pair.h"

int main() {
    using namespace std;

    Pair<int, double> p1;
    cout << "p1: first=" << p1.first << ", second=" << p1.second << endl;

    Pair<int, double> p2(10, 3.14);
    Pair<int, double> p3(5, 2.71);

    Pair<int, double> p4(p2);
    cout << "p4 (copy of p2): first=" << p4.first << ", second=" << p4.second << endl;

    p1 = p3;
    cout << "p1 after assignment from p3: first=" << p1.first << ", second=" << p1.second << endl;

    cout << "p2 == p4? " << (p2 == p4 ? "true" : "false") << endl;
    cout << "p2 != p3? " << (p2 != p3 ? "true" : "false") << endl;
    cout << "p2 < p3?  " << (p2 < p3  ? "true" : "false") << endl;
    cout << "p2 > p3?  " << (p2 > p3  ? "true" : "false") << endl;

    Pair<string, int> ps1("apple", 5);
    Pair<string, int> ps2("banana", 3);
    cout << "ps1 < ps2? " << (ps1 < ps2 ? "true" : "false") << endl;

    return 0;
}
