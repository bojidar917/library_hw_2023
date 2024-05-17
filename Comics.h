#include "Book.h"
#include "PerPub.h"

class Comics : public Book, public PerPub
{
public:
    Comics(const char* title, const char* summary, const int libraryID, const int year, const char* author, const char* publisher, const int genre, const char* period, const int number);

    virtual Copies* clone() const override;

private:

}; 