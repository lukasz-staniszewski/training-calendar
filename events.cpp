#include "events.h"
#include "event.h"
#include <QFile>
#include <QTextStream>
#include <string>
#include <QDebug>

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
{
    QFile file(filename);
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        qDebug()<<"OPENING FILE ERROR!";
        return;
    }
    QString buffor;
    QString data[5];
    QTextStream in (&file);
    in.setCodec("UTF-8");
    int i = 0;
    bool dot = false;
    while(!in.atEnd())
    {
        buffor = in.readLine();
        for (auto x : buffor)
        {
            if (x == ';')
            {
                    ++i;
                    dot = true;

            }
            else
            {
                if (dot != true)
                    data[i] += x;
                dot = false;
            }
        }
        i = 0;
        this->addEvent(Event(data[0].toStdString(), data[1].toStdString(), data[2].toStdString(), data[3].toStdString(), data[4].toStdString()));
        for (int j=0; j<5; ++j)
        {
            data[j].clear();
        }
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
