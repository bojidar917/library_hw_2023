#include "Comics.h"

#include <iostream>

Comics::Comics(const MString& title, const MString& summary, const int libraryID, const int year, const MString& author, const MString& publisher, const int genre, const MString& period, const int number)
    : Copy(title, summary, libraryID, year),
    Book(title, summary, libraryID, year, publisher, author, genre),
    PerPub(title, summary, libraryID, year, period, number)
{
}

Copy *Comics::clone() const
{
    return new Comics(*this);
}
