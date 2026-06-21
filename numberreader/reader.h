#pragma once

#include <string>

class NumberReader
{
    private:
        int number;
	std::string filename;
    public:
	explicit NumberReader(const std::string &filename);
	int getNumber() const;
	void setNumber(int value);
};

