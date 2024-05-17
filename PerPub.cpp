#include "PerPub.h"

#include <stdexcept>
#include <iostream>

PerPub::PerPub(const MString title, const MString summary, const int libraryID, const int year, const MString period, const int number)
    :Copies(title, summary, libraryID, year)
{
    if(number > 0)
        this->number = number;
    else throw std::invalid_argument("number must be positive");
    this->period_of_publishing = period;
}

Copies *PerPub::clone() const
{
    return new PerPub(*this);
}
