#pragma once

#include <iostream>

class MString
{
public:
    MString();
    MString(const char* str);
    // MString(const MString& str);
    MString(const MString& other);
    MString& operator=(const MString& other);
    ~MString();

    void print() const;

    bool operator==(const MString& other) const;

    friend std::ostream& operator<<(std::ostream& os, const MString& str);
    friend std::istream& operator>>(std::istream& is, MString& str); 

private:
    char* str;

    void clear();
    void copy(const MString& other);
};

