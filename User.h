#include "Copies.h"
#include "String.h"

class User
{
public:
    User(const char* name);
    User(const User& other);
    User& operator=(const User& other);
    ~User();

public: //functions

    void addNewBook(const Copy& copy);
    void returnBook(const int libraryID);

    int findBook(const int libraryID, int size, Copy**& copyToSearch) const;

    void printInfo() const;

public: //operator overloading
    bool operator==(const User& other) const;
    bool operator!=(const User& other) const;

    bool operator<=(const User& other) const;
    bool operator<(const User& other) const;
    
    bool operator>=(const User& other) const;
    bool operator>(const User& other) const;

    void operator[](const int libraryID) const; // it is not working as I wish to

    User& operator+=(const Copy& copy); // TODO: should we return const
    User operator+(const Copy& copy); // same here

    User& operator-=(const int libraryID);
    User operator-(const int libraryID);

private: //memebers
    MString name;
    Copy** allCopies;
    int size;
    int capacity;

    Copy** currCopies;
    int currSize;
    int currCapacity;

private: //methods
    void clear();
    void copy(const User& other);

    void clear(Copy **&copy, int size);

    void resize(int& capacity, int size, int reiszeNumber, Copy **&copy);
}; 