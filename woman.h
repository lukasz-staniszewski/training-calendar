#ifndef WOMAN_H
#define WOMAN_H
#include "person.h"

class Woman: public Person
{
public:
    Woman(std::string name);
    ~Woman() {};
};

#endif // WOMAN_H
