#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
    std::string name;
public:
    Person(std::string n="blank");
    void setName(std::string new_name);
    std::string getName() const;
};

#endif // PERSON_H
