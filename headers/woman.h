#ifndef WOMAN_H
#define WOMAN_H
#include "person.h"
/// Class Woman inherited from Person, represents woman using program
/// @see Person
class Woman: public Person
{
public:
    /// Constructor of Woman
    /// @param name -> name of woman [std::string]
    Woman(std::string name);

    /// Destructor of Woman
    ~Woman() {};
};

#endif // WOMAN_H
