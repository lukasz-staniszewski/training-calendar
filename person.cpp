#include "person.h"

Person::Person(std::string n): name(n){}

void Person::set_name(std::string new_name)
{
    if (new_name.length() >= 3 && new_name.length() <= 15)
    {
        this->name = new_name;
    }
}

std::string Person::get_name() const
{
    return this->name;
}
