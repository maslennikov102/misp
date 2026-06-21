#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Stack
{
private:
    struct Node
    {
        T value;
        Node* next;

        Node(T val, Node* n) : value(val), next(n) {}
    };

    Node* head;
    int count;

public:
    Stack()
    {
        head = nullptr;
        count = 0;
    }

    Stack(const Stack<T>& other)
    {
        head = nullptr;
        count = 0;
        Node* cur = other.head;
        T* tmp = new T[other.count];
        int i = other.count - 1;
        while (cur != nullptr)
        {
            tmp[i] = cur->value;
            i--;
            cur = cur->next;
        }
        for (int j = 0; j < other.count; j++)
        {
            push(tmp[j]);
        }
        delete[] tmp;
    }

    Stack<T>& operator=(const Stack<T>& other)
    {
        if (this == &other)
        {
            return *this;
        }
        while (!empty())
        {
            pop();
        }

        Node* cur = other.head;
        T* tmp = new T[other.count];
        int i = other.count - 1;
        while (cur != nullptr)
        {
            tmp[i] = cur->value;
            i--;
            cur = cur->next;
        }
        for (int j = 0; j < other.count; j++)
        {
            push(tmp[j]);
        }
        delete[] tmp;

        return *this;
    }

    ~Stack()
    {
        while (!empty())
        {
            pop();
        }
    }

    void push(T value)
    {
        head = new Node(value, head);
        count++;
    }

    void pop()
    {
        if (empty())
        {
            throw std::underflow_error("Stack is empty");
        }
        Node* tmp = head;
        head = head->next;
        delete tmp;
        count--;
    }

    T& top()
    {
        if (empty())
        {
            throw std::underflow_error("Stack is empty");
        }
        return head->value;
    }

    bool empty()
    {
        return count == 0;
    }

    int size()
    {
        return count;
    }

    friend std::ostream& operator<<(std::ostream& out, Stack<T>& s)
    {
        if (s.empty())
        {
            out << "empty";
            return out;
        }
        Node* cur = s.head;
        out << "top -> [";
        while (cur != nullptr)
        {
            out << cur->value;
            if (cur->next != nullptr)
            {
                out << ", ";
            }
            cur = cur->next;
        }
        out << "]";
        return out;
    }
};

template <typename T>
void transfer(Stack<T>& from, Stack<T>& to, int n)
{
    for (int i = 0; i < n; i++)
    {
        to.push(from.top());
        from.pop();
    }
}
