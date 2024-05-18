#pragma once

#include "Copies.h"

class PerPub : virtual public Copy
{
public:
    PerPub(const MString title, const MString summary, const int libraryID, const int year, const MString period, const int number);
    
    virtual Copy* clone() const override;

private:
    MString period_of_publishing;
    int number;
};