#include "event.h"
#include <string>
#include <QDate>
#include <QString>
Event::Event(std::string person_n, std::string activity, std::string date)
{
    QString qstr(QString::fromStdString(date));
    QDate cov_date(QDate::fromString(qstr, "dd-MM-yyyy"));
    this->date = cov_date;
    this->person = person_n;
    this->activity = activity;
}
QString Event::get_person_name() const
{
    return QString(QString::fromStdString(person));
}
QString Event::get_date() const
{
    return QString(date.toString("dd-MM-yyyy"));
}
QString Event::get_activity() const
{
    return QString(QString::fromStdString(activity));
}
