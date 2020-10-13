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

void Events::getFromFile(QString filepath)
{   std::string line;
    std::fstream myfile;
    myfile.open(filepath.toStdString(), std::fstream::in | std::fstream::out | std::fstream::app);
    if(!myfile)
    {
        myfile.open(filepath.toStdString(), std::fstream::in | std::fstream::out | std::fstream::trunc);
        myfile<<"\n";
        myfile.close();
    }
    else
    {
        while(std::getline(myfile, line))
        {
            std::istringstream iss(line);
            Event tempEvent;
            iss >> tempEvent;
            this->addEvent(tempEvent);
        }
        myfile.close();
    }
}
void Events::saveToFile(std::string filepath)
{
    std::ofstream myfile(filepath);
    for(auto event:Events::events)
    {
        myfile << event << "\n";
    }
    myfile.close();
}

bool Events::isPersonEvent(QString p_name, QString g_date)
{
    for(auto ev:events)
    {
        if(ev.getDate()==g_date && ev.getPersonName()==p_name)
        {
            return true;
        }
   }
   return false;
}


bool Events::comparePtrs(Event ev1, Event ev2)
{
    if(ev1.date < ev2.date || (ev1.date==ev2.date && ev1.getStartHour() < ev2.getStartHour()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Events::operator+=(Event ev)
{
    addEvent(ev);
}
