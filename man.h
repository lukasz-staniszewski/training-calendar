#ifndef MAN_H
#define MAN_H
#include"person.h"

class Man: public Person
{
public:
    Man(std::string name);
    ~Man() {};
};

#endif // MAN_H
