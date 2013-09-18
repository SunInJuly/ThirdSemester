#ifndef OS_H
#define OS_H
#include <iostream>
#include <string>

using namespace std;

/**
  Implements OS on computers. Simple abstract class.
  **/
class OS
{
public:
    OS();
    virtual string sistemType() = 0;
    int securityLevel();
protected:

    int security;
};

#endif // OS_H
