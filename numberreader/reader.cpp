#include "reader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
NumberReader::NumberReader(const std::string &f) : filename(f)
{
    std::ifstream file(filename);
    if (!(file.is_open()))
    {
        throw std::invalid_argument("Cannot open file!");
    }
    std::string content;
    if (!(file >> content))
    {
        throw std::invalid_argument("file is empty or cannot read");
    }
    std::istringstream iss(content);
    int val;
    if (!(iss >> val))
    {
        throw std::invalid_argument("content is not number");
    }
    char remaining;
    if (iss >> remaining)
    {
        throw std::invalid_argument("Extra characters after number");
    }
    number = val;
}

int NumberReader::getNumber() const
{
    return number;
}

void NumberReader::setNumber(int value)
{
    number = value;
    std::ofstream out(filename, std::ios::trunc);
    if(!out.is_open())
    {
        throw std::runtime_error("Cannot open file for writing");
    }
    out << number;
    if (!out.good())
    {
        throw std::runtime_error("Failed to write to file");
    }

}
