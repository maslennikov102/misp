#pragma once

template <typename T>

class Stack
{
    private:
        T *data;
        size_t capacity;
	size_t count;
        void resize()
	{
	    size_t new_capacity = capacity;
	    if (capacity == 0)
	    {
	        new_capacity = 1;
	    }
	    else
	    {
	        new_capacity = capacity * 2;
	    }
	    T* new_data = new T[new_capacity];
	    for (size_t i = 0; i < count; i++)
	    {
	        new_data[i] = data[i];
	    }
	    delete [] data;
	    data = new_data;
	    capacity = new_capacity;
	}
    public:
        Stack() : data(nullptr), count(0), capacity(0) {}
	~Stack()
	{
	    delete [] data;
	}

	void push(const T &value)
	{
	    if (count == capacity)
	    {
	        resize();
	    }
	    count++;
	    data[count-1] = value;
	}
	void pop()
	{
	    if (isEmpty())
	    {
	        throw std::runtime_error("Stack is empty!");
	    }
	    count--;
	}
	const T &peek()
	{
	    if (isEmpty())
	    {
	        throw std::runtime_error("Stack is empty!");
	    }
	    else
	    {
	        return data[count - 1];
	    }
	}
        size_t size()
	{
	   return count;
	}
	bool isEmpty()
	{
	   return count == 0;
	}
};

	    
