#include <iostream>

#include "String.h"
#include "Book.h"
#include "PerPub.h"
#include "Comics.h"
#include "User.h"

int main()
{
    //testing the string 

    // MString str = "Hellow";
    // str.print();

    // MString str2 = str;
    // str2.print();

    // str = "Shut up";
    // str.print();
    // str2.print();

    // const MString title, const MString summary, const int libraryID, const int year, const MString author, const MString publisher, const int genre

    Book iBook("Cars1", "Short story about some cars", 44556677, 2003, "Jerry", "DigiPro", 455902);
    PerPub iPerPub("Fitnez for pros", "Short story about some fitness", 4155687, 2012, "weekly", 560);
    Comics iComics("Batman", "Short story about some Batmans", 44556699, 2000, "Larry", "DigiPromaster", 455902, "weekly", 560);

    //testing the book 
    iBook.print();
    iPerPub.print();
    iComics.print();

    //testing the users
    User smartBoy("Pesho");
    Book cBook("C++ for the top 1percent of the world", "You are not the best coder if you haven't read this", 66666666, 2022, "Bjarne Stroustrup", "C++ for the win", 666);
    smartBoy.addNewBook(iBook);
    smartBoy.addNewBook(iComics);
    smartBoy.addNewBook(cBook);
    smartBoy.returnBook(66666666);
    smartBoy.printInfo();

    User lazyBoy("Ivan");

    if(smartBoy != lazyBoy)
        std::cout << "OOOF different names, the second must be lazy" << std::endl;

    return 0;
}