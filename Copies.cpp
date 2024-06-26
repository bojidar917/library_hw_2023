#include "Copies.h"

#include <stdexcept>
#include <iostream>

Copy::Copy(const MString& title, const MString& summary, int libraryID, int year)
{
    if(year <= 2024)
        this->year_of_publishing = year;
    else throw std::invalid_argument("Year must be less than 2024");

    this->libraryID = libraryID;

    this->title = title;
    this->summary = summary;
}

void Copy::print() const
{
    this->title.print();
    this->summary.print();
}
