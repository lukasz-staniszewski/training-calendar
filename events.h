#ifndef EVENTS_H
#define EVENTS_H
#include <vector>
#include<iostream>
#include<fstream>
#include "event.h"

class Events
{
public:
    Events();
    ~Events();
    std::vector<Event> events;
    void addEvent(Event ev);
    void delEvent(QString p_name, QString act_name, QString g_date, QString g_stime);
    void getFromFile(QString filename);
    void saveToFile(std::string filename);
    static bool comparePtrs(Event ev1, Event ev2) { return (ev1.getDate() < ev2.getDate()); }
};

#endif // EVENTS_H
