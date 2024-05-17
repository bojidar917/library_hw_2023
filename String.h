#pragma once

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

private:
    char* str;

    void clear();
    void copy(const MString& other);
};