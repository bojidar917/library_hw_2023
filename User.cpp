#include "User.h"

#include <iostream>
#include <stdexcept>

User::User(const char *name)
{
    this->name = name;
    this->currCapacity = 0;
    this->currSize = 0;
    this->size = 0;
    this->capacity = 0;
    currCopies = nullptr;
    allCopies = nullptr;
}

User::User(const User &other)
{
    try
    {
        copy(other);
    }
    catch(...)
    {
        clear();
        throw;
    }
}

User &User::operator=(const User &other)
{
    if(this != &other)
    {
        clear();
        try
        {
            copy(other);
        }
        catch(...)
        {
            clear();
            throw;
        }
    }

    return *this;
}

User::~User()
{
    clear();
}

void User::addNewBook(const Copy &copy)
{
    if(this->size == this->capacity)
        resize(this->capacity, this->size, this->capacity*2+1, this->allCopies);

    if(this->currSize == this->currCapacity)
        resize(this->currCapacity, this->currSize, this->currCapacity*2+1, this->currCopies);
    
    this->allCopies[this->size++] = copy.clone();

    this->currCopies[this->currSize++] = copy.clone();
}

void User::returnBook(const int libraryID)
{
    // Notes that this one is working, but opeartor[] is not 📛
    int foundIndex = findBook(libraryID, this->currSize, this->currCopies); 
    if (foundIndex != -1)
    {
        std::cout << "Found book at index: " << foundIndex << "\n";
        Copy* toDelete = this->currCopies[foundIndex];

        if (toDelete == nullptr)
        {
            std::cerr << "Error: toDelete is nullptr\n";
            return;
        }

        std::cout << "Deleting book with libraryID: " << libraryID << "\n";
        
        delete toDelete;

        for (int i = foundIndex; i < this->currSize - 1; i++)
        {
            this->currCopies[i] = this->currCopies[i + 1];
        }

        this->currCopies[this->currSize - 1] = nullptr;
        this->currSize--;

        std::cout << "Book deleted successfully.\n";
    }
    else
    {
        std::cerr << "Book with the specified libraryID not found.\n";
    }
}

int User::findBook(const int libraryID, int size, Copy **&copyToSearch) const
{
    for (int i = 0; i < size; i++)
    {
        if(copyToSearch[i]->GetLibraryNumber() == libraryID)
            return i;
    }
    
    return -1;
}

void User::printInfo() const
{
    std::cout<< "********************************" << std::endl;
    std::cout << "This is the stats of: ";
    name.print();
    
    std::cout << std::endl;

    std::cout<< "All books read: " << std::endl;
    for (int i = 0; i < this->size; i++)
    {
        this->allCopies[i]->print();
    }

    std::cout << std::endl;

    std::cout<< "Currently in possession: " << std::endl;
    for (int i = 0; i < this->currSize; i++)
    {
        this->currCopies[i]->print();
    }

    std::cout << std::endl;
    
    std::cout<< "Some hot stats: " << std::endl;
    std::cout<< "Total books read: " << this->size << std::endl;
    std::cout<< "Currently is possession: " << this->currSize << std::endl;

    std::cout<< "********************************" << std::endl;
}

bool User::operator==(const User &other) const
{
    if(this->name == other.name)
        return true;
    return false;
}

bool User::operator!=(const User &other) const
{
    return !(*this == other);
}

bool User::operator<=(const User &other) const
{
    return *this < other || this->size == other.size;
}

bool User::operator<(const User &other) const
{
    return this->size < other.size;
}

bool User::operator>=(const User &other) const
{
    return !(other < *this);
}

bool User::operator>(const User &other) const
{
    return other < *this;
}

void User::operator[](const int libraryID) const 
{
    //TODO: not working 😞
    // int indexCurr = findBook(libraryID, this->currSize, this->currCopies);
    // int indexAll = findBook(libraryID, this->size, this->allCopies);

    // if (indexCurr != -1)
    //     std::cout << "Currently reading " << libraryID << std::endl;
    // else if (indexAll != -1)
    //     std::cout << "Have read " << libraryID << std::endl;
    // else
    //     std::cout << "Have not read " << libraryID << std::endl;
}

User& User::operator+=(const Copy &copy)
{
    addNewBook(copy);
    return *this;
}

User User::operator+(const Copy &copy)
{
    User result(*this);
    result += copy;
    return result;
}

User& User::operator-=(const int libraryID)
{
    returnBook(libraryID);
    return *this;
}

User User::operator-(const int libraryID)
{
    User result(*this);
    result -= libraryID;
    return result;
}

void User::clear()
{
    clear(this->allCopies, this->size);
    clear(this->currCopies, this->currSize);
}

void User::copy(const User &other)
{
    this->name = other.name;

    Copy** newArr = new Copy*[other.capacity];
    for (int i = 0; i < other.size; i++)
        newArr[i] = this->allCopies[i] ? this->allCopies[i] : nullptr;

    delete [] this->allCopies;
    this->allCopies = newArr;   

    this->capacity = other.capacity;
    this->size = other.size;

    Copy** newArr = new Copy*[capacity];
    for (int i = 0; i < other.currSize; i++)
        newArr[i] = this->currCopies[i] ? this->currCopies[i] : nullptr;

    delete [] this->currCopies;
    this->currCopies = newArr; 

    this->currCapacity = other.currCapacity;
    this->currSize = other.currSize;
}

void User::clear(Copy **&copy, int size)
{
    for (int i = 0; i < this->size; i++)
        delete copy[i];

    delete [] copy;
}

void User::resize(int& capacity, int size, int resizeNumber, Copy **&copy)
{
    // if(copy == nullptr) capacity = 1;
    capacity = resizeNumber;
    int i = 0;
    Copy** newCopy = new Copy*[capacity];
    try
    {
         for ( i = 0; i < size; i++)
            newCopy[i] = copy[i] ? copy[i] : nullptr;

        delete [] copy;
        copy = newCopy;   
    }
    catch(const std::bad_alloc&)
    {
        clear();
        std::cout << "Memory problem! All resources are cleared! User resize\n";
    }
}

