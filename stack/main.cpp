#include <iostream>
#include "stack.h"

int main() {
    using namespace std;

    Stack<int> st;

    cout << "=== Демонстрация работы стека ===" << endl;
    cout << "Изначальный размер: " << st.size() << endl;
    cout << "Стек пуст? " << (st.isEmpty() ? "Да" : "Нет") << endl;

    st.push(10);
    st.push(20);
    st.push(30);
    cout << "После push(10), push(20), push(30) размер = " << st.size() << endl;

    cout << "Верхний элемент (peek) = " << st.peek() << endl;

    st.pop();
    cout << "После pop() размер = " << st.size() << endl;
    cout << "Новый верхний элемент = " << st.peek() << endl;

    st.pop(); // удаляем 20
    st.pop(); // удаляем 10
    cout << "После ещё двух pop() размер = " << st.size() << endl;
    cout << "Стек пуст? " << (st.isEmpty() ? "Да" : "Нет") << endl;

    cout << "\n=== Обработка исключений ===" << endl;
    try {
        st.pop();   // стек пуст – должно выбросить исключение
    } catch (const std::runtime_error& e) {
        cout << "Исключение при pop(): " << e.what() << endl;
    }

    try {
        st.peek();  // стек пуст – должно выбросить исключение
    } catch (const std::runtime_error& e) {
        cout << "Исключение при peek(): " << e.what() << endl;
    }

    Stack<double> stDouble;
    stDouble.push(3.14);
    stDouble.push(2.71);
    cout << "\nРабота со стеком double: верхний = " << stDouble.peek() << endl;

    return 0;
}
