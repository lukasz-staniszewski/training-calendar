
#include "event.h"
#include <string>
#include <QDate>
#include <QString>
#include <QTime>
Event::Event(std::string person_n, std::string activity, std::string date, std::string start_hour, std::string end_hour)
{
    QString qstr(QString::fromStdString(date));
    QDate cov_date(QDate::fromString(qstr, "dd-MM-yyyy"));
    QString qstr2(QString::fromStdString(start_hour));
    QTime cov_hour1(QTime::fromString(qstr2, "hh:mm"));
    QString qstr3(QString::fromStdString(end_hour));
    QTime cov_hour2(QTime::fromString(qstr3, "hh:mm"));
    this->date = cov_date;
    this->start_hour = cov_hour1;
    this->end_hour = cov_hour2;
    this->person = person_n;
    this->activity = activity;
}
QString Event::getPersonName() const
{
    return QString(QString::fromStdString(person));
}
QString Event::getDate() const
{
    return QString(date.toString("dd-MM-yyyy"));
}
QString Event::getActivity() const
{
    return QString(QString::fromStdString(activity));
}
QString Event::getStartHour() const
{
    return QString(start_hour.toString("hh:mm"));
}
QString Event::getEndHour() const
{
    return QString(end_hour.toString("hh:mm"));
}

std::ostream& operator<< (std::ostream& os, Event &event)
{
    os << event.getPersonName().toStdString() << "; "
       <<event.getActivity().toStdString() <<"; "
       <<event.getDate().toStdString() << "; "
      <<event.getStartHour().toStdString() <<"; "
     <<event.getEndHour().toStdString();

    return os;
}
