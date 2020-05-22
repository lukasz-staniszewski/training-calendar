#include "person.h"

Person::Person(std::string n): name(n){}

void Person::setName(std::string new_name)
{
    if (new_name.length() >= 3 && new_name.length() <= 15)
    {
        this->name = new_name;
    }
}

std::string Person::getName() const
{
    return this->name;
}
