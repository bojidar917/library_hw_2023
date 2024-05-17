#pragma once

#include "Copies.h"

class Book : public virtual Copies
{
public:
    // Book();
    Book(const MString title, const MString summary, const int libraryID, const int year, const MString author, const MString publisher, const int genre);
    // Book(const Book& other);
    // Book& operator=(const Book& other);
    // ~Book();

    //TODO: should we use the big four when we have the string class

    virtual Copies* clone() const override;

private:
    MString author;
    MString publisher;
    int genre;

};