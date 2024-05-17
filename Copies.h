#pragma once

#include "String.h"

class Copies
{
public:
    // Copies();
    Copies(const MString title, const MString summary, const int libraryID, const int year);
    // Copies(const Copies& other);
    // Copies& operator=(const Copies& other);
    virtual ~Copies() = default;

    //I think we don't need the B4 because we "hosted" the dynamic memory outside our class

    int GetLibraryNumber() const {return this->libraryID;}

    virtual void print() const;

    virtual Copies* clone() const = 0;

private:
    MString title;
    MString summary;
    int libraryID;
    int year_of_publishing;
};