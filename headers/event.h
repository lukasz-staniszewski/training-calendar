#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <QDate>
/// Class Event represents a single training
class Event
{
private:
    std::string activity;           /*!< Type of training */

    QTime start_hour;               /*!< Starting time of training */

    QTime end_hour;                 /*!< Ending time of training */

    std::string person;             /*!< Person who will be training */
public:
    QDate date;                     /*!< Date of training */
    /// Constructor of Event
    /// @param p -> person training [std::string]
    /// @param a -> type of training [std::string]
    /// @param d -> date of training [std::string]
    /// @param s_h -> starting hour [std::string]
    /// @param e_h -> ending hour [std::string]
    Event(std::string p="", std::string a="", std::string d="", std::string s_h="", std::string e_h="");

    /// Method getting name of person
    /// @returns name of person [QString]
    QString getPersonName() const;

    /// Method getting type of training
    /// @returns type of training [QString]
    QString getActivity() const;

    /// Method getting date of training
    /// @returns date of training [QString]
    QString getDate() const;

    /// Method getting starting hour of training
    /// @returns starting hour of training [QString]
    QString getStartHour() const;

    /// Method getting ending hour of training
    /// @returns ending hour of training [QString]
    QString getEndHour() const;

    /// Overloaded ostream >> operator
    /// @param &event -> reference to training [Event]
    /// @returns reference to ostream >> [std::ostream&]
    friend
        std::ostream& operator<<(std::ostream &os, Event &event);

    /// Overloaded istream << operator
    /// @param &event -> reference to training [Event]
    /// @returns reference to istream << [std::istream&]
    friend
        std::istream& operator>>(std::istream &in, Event &event);
};

#endif // EVENT_H
