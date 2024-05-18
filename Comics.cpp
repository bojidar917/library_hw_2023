#include "Comics.h"

#include <iostream>

Comics::Comics(const char *title, const char *summary, const int libraryID, const int year, const char *author, const char *publisher, const int genre, const char *period, const int number)
    : Copy(title, summary, libraryID, year),
    Book(title, summary, libraryID, year, publisher, author, genre),
    PerPub(title, summary, libraryID, year, period, number)
{
}

Copy *Comics::clone() const
{
    return new Comics(*this);
}
