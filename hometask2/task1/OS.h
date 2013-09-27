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
    //OS(int number);
    virtual string sistemType() = 0;
    int securityLevel();
    void setSecurity(int level);
protected:
    int security;
};

#endif // OS_H
