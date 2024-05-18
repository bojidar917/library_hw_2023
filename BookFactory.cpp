#include "BookFactory.h"
#include "Book.h"
#include "PerPub.h"
#include "Comics.h"
#include "String.h"

#include <iostream>

Copy *CopyFactory::createCopy(int shapeType)
{
    switch (shapeType)
    {
        case 0:
        {
            MString title;
            std::cin >> title;
            
            MString summary;
            std::cin >> summary;

            int number;
            std::cin >> number;

            int year;
            std::cin >> year;

            MString author;
            std::cin >> author;

            MString publisher;
            std::cin >> publisher;

            int genre;
            std::cin >> genre;

            Book cBook(title, summary,number, year, author, publisher, genre);
            
            break;
        }    
        case 1:

            break;

        case 2:
        
            break;
        default:
            break;
    }
        return nullptr;
}