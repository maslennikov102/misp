#include <iostream>
#include "stack.h"

int main()
{
    Stack<int> a;
    std::cout << "empty: " << a.empty() << std::endl;

    a.push(1);
    a.push(2);
    a.push(3);
    std::cout << "after push 1,2,3: " << a << std::endl;
    std::cout << "top: " << a.top() << std::endl;
    std::cout << "size: " << a.size() << std::endl;

    a.pop();
    std::cout << "after pop: " << a << std::endl;
    Stack<int> b(a);
    std::cout << "copy of a: " << b << std::endl;
    Stack<int> c;
    c = a;
    std::cout << "c = a: " << c << std::endl;
    Stack<int> from;
    from.push(10);
    from.push(20);
    from.push(30);
    from.push(40);

    Stack<int> to;
    to.push(99);

    std::cout << "from before transfer: " << from << std::endl;
    std::cout << "to before transfer:   " << to << std::endl;

    transfer(from, to, 3);

    std::cout << "from after transfer:  " << from << std::endl;
    std::cout << "to after transfer:    " << to << std::endl;

    // ловля исключений
    Stack<int> empty;
    try
    {
        empty.pop();
    }
    catch (std::underflow_error& e)
    {
        std::cout << "pop exception: " << e.what() << std::endl;
    }

    try
    {
        empty.top();
    }
    catch (std::underflow_error& e)
    {
        std::cout << "top exception: " << e.what() << std::endl;
    }

    // стек строк
    Stack<std::string> words;
    words.push("jeffrey");
    words.push("epstein");
    words.push("six seven!");
    std::cout << "string stack: " << words << std::endl;

    return 0;
}
