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

            return new Book(title, summary,number, year, author, publisher, genre);

            break;
        }    
        case 1:
        {
            MString title;
            std::cin >> title;
            
            MString summary;
            std::cin >> summary;

            int number;
            std::cin >> number;

            int year;
            std::cin >> year;

            MString period;
            std::cin >> period;

            int number;
            std::cin >> number;

            return new PerPub(title, summary, number, year, period, number);
            break;
        }
        case 2:
        {
            MString title;
            std::cin >> title;

            MString summary;
            std::cin >> summary;

            int libraryID;
            std::cin >> libraryID;

            int year;
            std::cin >> year;

            MString author;
            std::cin >> author;

            MString publisher;
            std::cin >> publisher;

            int genre;
            std::cin >> genre;

            MString period; 
            std::cin >> period;

            int number;
            std::cin >> number;

            return new Comics(title, summary, libraryID, year, author, publisher, genre, period, number);
            break;
        }
        default:
            break;
    }
    return nullptr;
}