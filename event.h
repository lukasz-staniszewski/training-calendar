#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <QDate>

class Event
{
private:
    std::string activity;
    QDate date;
    QTime start_hour;
    QTime end_hour;
    std::string person;
public:
    Event(std::string p, std::string a, std::string d, std::string s_h, std::string e_h);
    QString getPersonName() const;
    QString getActivity() const;
    QString getDate() const;
    QString getStartHour() const;
    QString getEndHour() const;

    friend
        std::ostream& operator<<(std::ostream &os, Event &event);
};

#endif // EVENT_H
