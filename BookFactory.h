#include "Copies.h"

enum class CopyType
{
    Book,
    PerPub,
    Comics
};


class CopyFactory
{
public:
    static Copy* createCopy(int shapeType);
};