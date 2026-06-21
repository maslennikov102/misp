#pragma once

template <typename T1, typename T2> 

class Pair
{
    private:
        T1 first;
	T2 second;
    public:
	Pair() : first(), second() {}
	Pair(const T1 &f,const T2 &s) : first(f), second(s) {}
	Pair(const Pair &other) : first(other.first), second(other.second) {}
	Pair& operator=(const Pair &other)
	{
	    if (this == &other)
	    {
	        return *this;
	    }
	    first = other.first;
	    second = other.second;
	    return *this;
	}
	bool operator==(const Pair &other)
	{
	    return ((first = other.first) && (second == other.second));
	}
	bool operator>(const Pair &other)
	{
	    if (first != other.first)
	    {
	        return first > other.first;
	    }
	    return second > other.second;
	}
	bool operator !=(const Pair &other)
	{
	    return !(*this == other);
	}
	bool operator <(const Pair &other)
	{
	    if (first != other.first)
	    {
	        return first < other.first;
	    }
	    return second < other.second;
	}
};




