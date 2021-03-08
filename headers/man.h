#ifndef MAN_H
#define MAN_H
#include"person.h"
/// Class Man, inherited from Person, represents a Man using program
/// @see Person
class Man: public Person
{
public:
    /// Constructor of Man
    /// @param name -> name of person [std::string]
    Man(std::string name);

    /// Destructor of Man
    ~Man() {};
};

#endif // MAN_H
