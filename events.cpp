#include "events.h"
#include "event.h"
#include <QFile>
#include <QTextStream>
#include <string>
#include <QDebug>
#include<sstream>

Events::Events()
{

}
Events::~Events()
{
    qDebug()<<"SAVING FILE!";
}

void Events::addEvent(Event ev)
{
    this->events.push_back(ev);
    std::sort(events.begin(), events.end(), comparePtrs);
}

void Events::delEvent(QString p_name, QString act_name, QString g_date, QString g_stime)
{
    for(unsigned int i = 0; i<events.size(); i++)
    {
        if(events[i].getDate()==g_date && events[i].getPersonName()==p_name && events[i].getStartHour() == g_stime && events[i].getActivity() == act_name)
        {
            events.erase(events.begin() + i);
        }
    }
}

void Events::getFromFile(QString filename)
{   std::string line;
    std::ifstream myfile(filename.toStdString());
    while(std::getline(myfile, line))
    {
        std::istringstream iss(line);
        Event tempEvent;
        iss >> tempEvent;
        this->addEvent(tempEvent);
    }
}
void Events::saveToFile(std::string filename)
{
    std::ofstream myfile(filename);
    for(auto event:Events::events)
    {
        myfile << event << "\n";
    }
}
