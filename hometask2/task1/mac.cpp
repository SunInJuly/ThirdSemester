#include "mac.h"

Mac::Mac(int number)
{
    security = number;
}

string Mac::sistemType()
{
    return "Mac OS";
}
