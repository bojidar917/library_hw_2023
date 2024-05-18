#pragma once

#include "String.h"

class Copy
{
public:
    Copy(const MString& title, const MString& summary, int libraryID, int year);
    //❔ NOTE: You need to add & to parameters that are not basic types
    //Also I've removed the consts on the basic types as they will be copied and it doesn't 
    //matter if they're consts or not. In general we don't put consts on basic types as to 
    //not clutter the function's declaration. (It's not a problem, just a general advice for C++ code)
    
    virtual ~Copy() = default;

    int GetLibraryNumber() const {return this->libraryID;}

    virtual void print() const;

    virtual Copy* clone() const = 0;

private:
    MString title;
    MString summary;
    int libraryID;
    int year_of_publishing;
};