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
    void add_event(Event ev);
    void get_from_file(QString filename);
    static bool comparePtrs(Event ev1, Event ev2) { return (ev1.get_date() < ev2.get_date()); }
};

#endif // EVENTS_H
