#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
    std::string name;
public:
    Person(std::string n="blank");
    void set_name(std::string new_name);
    std::string get_name() const;
};

#endif // PERSON_H
