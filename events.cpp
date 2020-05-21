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

void Events::add_event(Event ev)
{
    this->events.push_back(ev);
    std::sort(events.begin(), events.end(), comparePtrs);
}

void Events::get_from_file(QString filename)
{
    QFile file(filename);
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        qDebug()<<"OPENING FILE ERROR!";
        return;
    }
    QString buffor;
    QString data[3];
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
        this->add_event(Event(data[0].toStdString(), data[1].toStdString(), data[2].toStdString()));
        for (int j=0; j<3; ++j)
        {
            data[j].clear();
        }
    }
}

