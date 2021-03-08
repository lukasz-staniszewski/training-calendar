#ifndef PERSON_H
#define PERSON_H
#include <string>
/// Class person represents a person using program
class Person
{
protected:
    std::string name;           /*!< Name of person */

    /// Method setting name of person
    /// @param new_name -> new name of person [std::string]
    void setName(std::string new_name);
public:
    /// Constructor of person
    /// @param n -> name of person [std::string]
    Person(std::string n="blank");

    /// Assingment operator setting new name to person
    /// @param new_name -> new name of person [const std::string]
    void operator=(const std::string new_name);

    /// Name of person getter
    /// @returns name of person [std::string]
    std::string getName() const;
};

#endif // PERSON_H
