#pragma once

#include "String.h"

class Copy
{
public:
    // Copy();
    Copy(const MString title, const MString summary, const int libraryID, const int year);
    // Copy(const Copy& other);
    // Copy& operator=(const Copy& other);
    virtual ~Copy() = default;

    //I think we don't need the B4 because we "hosted" the dynamic memory outside our class

    int GetLibraryNumber() const {return this->libraryID;}

    virtual void print() const;

    virtual Copy* clone() const = 0;

private:
    MString title;
    MString summary;
    int libraryID;
    int year_of_publishing;
};