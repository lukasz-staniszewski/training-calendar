#include "calendarwindow.h"
#include "ui_calendarwindow.h"
#include <QString>
#include <QFont>
#include <QPainter>
#include <QDebug>
#include <QTextCharFormat>
#include "event.h"
#include "events.h"

CalendarWindow::CalendarWindow(QWidget *parent, Person *person, Events *events) :
    QDialog(parent),
    ui(new Ui::CalendarWindow),
    person(person),
    familyevents(events)
{
    ui->setupUi(this);
    showWelcomeMessage();
    printActualDate();
    highlightToday();
    display_nearest_person_events();
    display_this_day_events(QDate::currentDate());
    ui->calendar->setNavigationBarVisible(false);
    ui->calendar->setGridVisible(true);
}
void CalendarWindow::display_nearest_person_events()
{
    int how_many = 0;
    for(unsigned int iter = 0; iter<familyevents->events.size(); ++iter)
    {
        if(this->familyevents->events[iter].get_person_name().toStdString() == this->person->get_name())
        {
            how_many++;
        }
    }
    if (how_many >= 1)
    {
        unsigned int iter = 0;
        while(this->familyevents->events[iter].get_person_name().toStdString() != this->person->get_name())
        {
            iter += 1;
        }
        ui->FirstYourId->setText("1.");
        ui->FirstYourActivity->setText(this->familyevents->events[iter].get_activity());
        ui->FirstYourDate->setText(this->familyevents->events[iter].get_date());
        if(how_many >= 2)
        {
            iter += 1;
            while(this->familyevents->events[iter].get_person_name().toStdString() != this->person->get_name())
            {
                iter += 1;
            }
            ui->SecondYourId->setText("2.");
            ui->SecondYourActivity->setText(this->familyevents->events[iter].get_activity());
            ui->SecondYourDate->setText(this->familyevents->events[iter].get_date());
            if(how_many >= 3)
            {
                iter += 1;
                while(this->familyevents->events[iter].get_person_name().toStdString() != this->person->get_name())
                {
                    iter += 1;
                }
                ui->ThirdYourId->setText("3.");
                ui->ThirdYourActivity->setText(this->familyevents->events[iter].get_activity());
                ui->ThirdYourDate->setText(this->familyevents->events[iter].get_date());
                if(how_many >= 4)
                {
                    iter += 1;
                    while(this->familyevents->events[iter].get_person_name().toStdString() != this->person->get_name())
                    {
                        iter += 1;
                    }
                    ui->FourthYourId->setText("4.");
                    ui->FourthYourActivity->setText(this->familyevents->events[iter].get_activity());
                    ui->FourthYourDate->setText(this->familyevents->events[iter].get_date());
                }
            }
        }
    }
}
void CalendarWindow::clear_this_day_events()
{
    ui->FirstFamilyId->setText("");
    ui->SecondFamilyId->setText("");
    ui->ThirdFamilyId->setText("");
    ui->FourthFamilyId->setText("");
    ui->FirstFamilyActivity->setText("");
    ui->SecondFamilyActivity->setText("");
    ui->ThirdFamilyActivity->setText("");
    ui->FourthFamilyActivity->setText("");
    ui->FirstFamilyName->setText("");
    ui->SecondFamilyName->setText("");
    ui->ThirdFamilyName->setText("");
    ui->FourthFamilyName->setText("");
}
void CalendarWindow::display_this_day_events(QDate date)
{
    int how_many = 0;
    QString qstr(date.toString("dd-MM-yyyy"));
    for(unsigned int iter = 0; iter<this->familyevents->events.size(); ++iter)
    {
        if(this->familyevents->events[iter].get_date() == qstr)
        {
            how_many++;
        }
    }
    if (how_many >= 1)
    {
        unsigned int iter = 0;
        while(this->familyevents->events[iter].get_date() != date.toString("dd-MM-yyyy"))
        {
            iter += 1;
        }
        ui->FirstFamilyId->setText("1.");
        ui->FirstFamilyActivity->setText(this->familyevents->events[iter].get_activity());
        ui->FirstFamilyName->setText(this->familyevents->events[iter].get_person_name());
        if(how_many >= 2)
        {
            iter += 1;
            while(this->familyevents->events[iter].get_date() != date.toString("dd-MM-yyyy"))
            {
                iter += 1;
            }
            ui->SecondFamilyId->setText("2.");
            ui->SecondFamilyActivity->setText(this->familyevents->events[iter].get_activity());
            ui->SecondFamilyName->setText(this->familyevents->events[iter].get_person_name());
            if(how_many >= 3)
            {
                iter += 1;
                while(this->familyevents->events[iter].get_date() != date.toString("dd-MM-yyyy"))
                {
                    iter += 1;
                }
                ui->ThirdFamilyId->setText("3.");
                ui->ThirdFamilyActivity->setText(this->familyevents->events[iter].get_activity());
                ui->ThirdFamilyName->setText(this->familyevents->events[iter].get_person_name());
                if(how_many >= 4)
                {
                    iter += 1;
                    while(this->familyevents->events[iter].get_date() != date.toString("dd-MM-yyyy"))
                    {
                        iter += 1;
                    }
                    ui->FourthFamilyId->setText("4.");
                    ui->FourthFamilyActivity->setText(this->familyevents->events[iter].get_activity());
                    ui->FourthFamilyName->setText(this->familyevents->events[iter].get_person_name());
                }
            }
        }
    }
}
void  CalendarWindow::highlightToday()
{

    QTextCharFormat qtcf;
    qtcf.setFontWeight(80);
    QColor todaycolor;
    todaycolor.setRgb(0, 82, 204);
    qtcf.setForeground(QBrush(todaycolor));
    qtcf.setFontItalic(true);
    qtcf.setFontKerning(true);
    ui->calendar->setDateTextFormat(QDate::currentDate(), qtcf);
}
void  CalendarWindow::showWelcomeMessage()
{
    std::string temp = "Cześć, " + person->get_name() + "!";
    QString qstr = QString::fromStdString(temp.c_str());
    QFont new_font("Arial", 55);
    ui->welcomemsg->setText(qstr);
    ui->welcomemsg->setFont(new_font);
    ui->welcomemsg->setAlignment(Qt::AlignCenter);
}

void CalendarWindow::printActualDate()
{
    QFont new_font_date("Arial", 14);
    ui->actualdate->setFont(new_font_date);
    ui->actualdate->setAlignment(Qt::AlignCenter);
    QDate date = ui->calendar->selectedDate();
    QString qstr = date.toString("'Wybrany dzień: 'dddd, dd.MM.yyyy");
    ui->actualdate->setText(qstr);
}
CalendarWindow::~CalendarWindow()
{
    delete ui;
    delete person;
}

void CalendarWindow::on_calendar_selectionChanged()
{
    QDate date = ui->calendar->selectedDate();
    clear_this_day_events();
    display_this_day_events(date);
    QString qstr = date.toString("'Wybrany dzień: 'dddd, dd.MM.yyyy");
    ui->actualdate->setText(qstr);
}

void CalendarWindow::on_backtodaybutton_clicked()
{
    ui->calendar->setSelectedDate(QDate::currentDate());
}

void CalendarWindow::on_pushButton_clicked()
{
    ui->calendar->showNextMonth();
}

void CalendarWindow::on_pushButton_2_clicked()
{
    ui->calendar->showPreviousMonth();
}
