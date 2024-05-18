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

    clear();

}

void MString::print() const
{
    if(this->str)
        std::cout << this->str << std::endl;
    else
        std::cout << "" << std::endl;
}

bool MString::operator==(const MString &other) const
{
    if(strcmp(this->str, other.str) == 0)
        return true;
    return false;
}

void MString::clear()
{
    if (str != nullptr) 
    {
        delete[] str;
        str = nullptr;
    }
    // delete[] this->str;
}

void MString::copy(const MString &other)
{
    if(other.str)
    {
        this->str = new char[strlen(other.str) + 1];
        strcpy(this->str, other.str);   
    }
}

std::ostream &operator<<(std::ostream &os, const MString &str)
{
    if(str.str)
        os << str.str;
    else
        os << "(null)";
    return os;
}

std::istream &operator>>(std::istream &is, MString &str)
{
    char buffer[1024];
    is >> buffer;
    str.clear();
    str.str = new char[strlen(buffer) + 1];
    strcpy(str.str, buffer);
    return is;
}
