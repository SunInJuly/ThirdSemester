#include "linux.h"

Linux::Linux(int number)
{
   security = number;
}

string Linux::sistemType()
{
    return "Linux";
}
