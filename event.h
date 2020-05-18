#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <QDate>

class Event
{
private:
    std::string activity;
    QDate date;
    std::string person;
public:
    Event(std::string p, std::string a, std::string d);
    QString get_person_name() const;
    QString get_activity() const;
    QString get_date() const;
};

#endif // EVENT_H
