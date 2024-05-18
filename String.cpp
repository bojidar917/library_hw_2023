#include "String.h"

#include <cstring>
#include <stdexcept>
#include <iostream>

MString::MString() : str(nullptr) {}

MString::MString(const char *str)
{
    if(str)
    {
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
    }
    else throw std::invalid_argument("Inputed string is not valid");
}

MString::MString(const MString &other)
{
    copy(other);
}

MString &MString::operator=(const MString &other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }

    return *this;
}

MString::~MString()
{
    if (str != nullptr) 
    {
        delete[] str;
        str = nullptr;
    }
}

void MString::print() const
{
    std::cout << this->str << std::endl;
}

bool MString::operator==(const MString &other) const
{
    if(strcmp(this->str, other.str) == 0)
        return true;
    return false;
}

void MString::clear()
{
    delete[] this->str;
}

void MString::copy(const MString &other)
{
    if(other.str)
    {
        this->str = new char[strlen(other.str) + 1];
        strcpy(this->str, other.str);   
    }
}
