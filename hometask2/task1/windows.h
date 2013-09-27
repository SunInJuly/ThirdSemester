#ifndef WINDOWS_H
#define WINDOWS_H
#include "OS.h"

class Windows : public OS
{
public:
    Windows(int number);
    string sistemType();
};

#endif // WINDOWS_H
