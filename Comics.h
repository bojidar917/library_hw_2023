#include "Book.h"
#include "PerPub.h"

class Comics : public Book, public PerPub
{
public:
    Comics(const MString& title, const MString& summary, const int libraryID, const int year, const MString& author, const MString& publisher, const int genre, const MString& period, const int number);

    virtual Copy* clone() const override;

private:

}; 