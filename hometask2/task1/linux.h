#ifndef LINUX_H
#define LINUX_H
#include "OS.h"


class Linux : public OS
{
public:
    Linux(int number);
    string sistemType();
};

#endif // LINUX_H
