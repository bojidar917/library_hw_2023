#include <iostream>

#include "Book.h"

Book::Book(const MString title, const MString summary, const int libraryID, const int year, const MString author, const MString publisher, const int genre)
: Copy(title, summary, libraryID, year)
{
    this->author = author;
    this->publisher = publisher;
    this->genre = genre;
}

Copy *Book::clone() const
{
    return new Book(*this);
}
