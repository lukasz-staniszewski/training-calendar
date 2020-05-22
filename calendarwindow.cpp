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
    addevwin = new AddEventScreen(this, familyevents);
    delevwin = new DeleteEventWindow(this, familyevents);
    showWelcomeMessage();
    printActualDate();
    highlightToday();
    refreshEvents(QDate::currentDate());
    // displayNearestPersonEvents();
    // displayThisDayEvents(QDate::currentDate());
    setupCalendar();
}

void CalendarWindow::setupCalendar()
{
    ui->calendar->setNavigationBarVisible(false);
    ui->calendar->setGridVisible(true);
}
void CalendarWindow::displayNearestPersonEvents()
{
    unsigned int iter_t=0;
    QDate tempDate;
    while(tempDate.fromString(this->familyevents->events[iter_t].getDate(), "dd-MM-yyyy") < QDate::currentDate())
    {
        iter_t += 1;
    }
    int how_many = 0;
    for(unsigned int iter = iter_t; iter<familyevents->events.size(); ++iter)
    {
        if(this->familyevents->events[iter].getPersonName().toStdString() == this->person->getName())
        {
            how_many++;
        }
    }
    if (how_many >= 1)
    {
        unsigned int iter = iter_t;
        while(this->familyevents->events[iter].getPersonName().toStdString() != this->person->getName())
        {
            iter += 1;
        }
        ui->FirstYourId->setText("1.");
        ui->FirstYourActivity->setText(this->familyevents->events[iter].getActivity());
        ui->FirstYourDate->setText(this->familyevents->events[iter].getDate());
        ui->FirstYourHour->setText(this->familyevents->events[iter].getStartHour() + " - " + this->familyevents->events[iter].getEndHour());
        if(how_many >= 2)
        {
            iter += 1;
            while(this->familyevents->events[iter].getPersonName().toStdString() != this->person->getName())
            {
                iter += 1;
            }
            ui->SecondYourId->setText("2.");
            ui->SecondYourActivity->setText(this->familyevents->events[iter].getActivity());
            ui->SecondYourDate->setText(this->familyevents->events[iter].getDate());
            ui->SecondYourHour->setText(this->familyevents->events[iter].getStartHour() + " - " + this->familyevents->events[iter].getEndHour());
            if(how_many >= 3)
            {
                iter += 1;
                while(this->familyevents->events[iter].getPersonName().toStdString() != this->person->getName())
                {
                    iter += 1;
                }
                ui->ThirdYourId->setText("3.");
                ui->ThirdYourActivity->setText(this->familyevents->events[iter].getActivity());
                ui->ThirdYourDate->setText(this->familyevents->events[iter].getDate());
                ui->ThirdYourHour->setText(this->familyevents->events[iter].getStartHour() + " - " + this->familyevents->events[iter].getEndHour());
                if(how_many >= 4)
                {
                    iter += 1;
                    while(this->familyevents->events[iter].getPersonName().toStdString() != this->person->getName())
                    {
                        iter += 1;
                    }
                    ui->FourthYourId->setText("4.");
                    ui->FourthYourActivity->setText(this->familyevents->events[iter].getActivity());
                    ui->FourthYourDate->setText(this->familyevents->events[iter].getDate());
                    ui->FourthYourHour->setText(this->familyevents->events[iter].getStartHour() + " - " + this->familyevents->events[iter].getEndHour());
                }
            }
        }
    }
}
void CalendarWindow::clearThisDayEvents()
{
    ui->FirstYourId->setText("");
    ui->SecondYourId->setText("");
    ui->ThirdYourId->setText("");
    ui->FourthYourId->setText("");

    ui->FirstYourActivity->setText("");
    ui->SecondYourActivity->setText("");
    ui->ThirdYourActivity->setText("");
    ui->FourthYourActivity->setText("");

    ui->FirstYourDate->setText("");
    ui->SecondYourDate->setText("");
    ui->ThirdYourDate->setText("");
    ui->FourthYourDate->setText("");

    ui->FirstYourHour->setText("");
    ui->SecondYourHour->setText("");
    ui->ThirdYourHour->setText("");
    ui->FourthYourHour->setText("");

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

    ui->FirstFamilyHour->setText("");
    ui->SecondFamilyHour->setText("");
    ui->ThirdFamilyHour->setText("");
    ui->FourthFamilyHour->setText("");
}
void CalendarWindow::displayThisDayEvents(QDate date)
{
    int how_many = 0;
    QString qstr(date.toString("dd-MM-yyyy"));
    for(unsigned int iter = 0; iter<this->familyevents->events.size(); ++iter)
    {
        if(this->familyevents->events[iter].getDate() == qstr)
        {
            how_many++;
        }
    }
    if (how_many >= 1)
    {
        unsigned int iter = 0;
        while(this->familyevents->events[iter].getDate() != date.toString("dd-MM-yyyy"))
        {
            iter += 1;
        }
        ui->FirstFamilyId->setText("1.");
        ui->FirstFamilyActivity->setText(this->familyevents->events[iter].getActivity());
        ui->FirstFamilyName->setText(this->familyevents->events[iter].getPersonName());
        ui->FirstFamilyHour->setText(this->familyevents->events[iter].getStartHour() + " - " + this->familyevents->events[iter].getEndHour());
        if(how_many >= 2)
        {
            iter += 1;
            while(this->familyevents->events[iter].getDate() != date.toString("dd-MM-yyyy"))
            {
                iter += 1;
            }
            ui->SecondFamilyId->setText("2.");
            ui->SecondFamilyActivity->setText(this->familyevents->events[iter].getActivity());
            ui->SecondFamilyName->setText(this->familyevents->events[iter].getPersonName());
            ui->SecondFamilyHour->setText(this->familyevents->events[iter].getStartHour() + " - " + this->familyevents->events[iter].getEndHour());
            if(how_many >= 3)
            {
                iter += 1;
                while(this->familyevents->events[iter].getDate() != date.toString("dd-MM-yyyy"))
                {
                    iter += 1;
                }
                ui->ThirdFamilyId->setText("3.");
                ui->ThirdFamilyActivity->setText(this->familyevents->events[iter].getActivity());
                ui->ThirdFamilyName->setText(this->familyevents->events[iter].getPersonName());
                ui->ThirdFamilyHour->setText(this->familyevents->events[iter].getStartHour() + " - " + this->familyevents->events[iter].getEndHour());
                if(how_many >= 4)
                {
                    iter += 1;
                    while(this->familyevents->events[iter].getDate() != date.toString("dd-MM-yyyy"))
                    {
                        iter += 1;
                    }
                    ui->FourthFamilyId->setText("4.");
                    ui->FourthFamilyActivity->setText(this->familyevents->events[iter].getActivity());
                    ui->FourthFamilyName->setText(this->familyevents->events[iter].getPersonName());
                    ui->FourthFamilyHour->setText(this->familyevents->events[iter].getStartHour() + " - " + this->familyevents->events[iter].getEndHour());
                }
            }
        }
    }
}
void  CalendarWindow::refreshEvents(QDate date)
{
    clearThisDayEvents();
    displayNearestPersonEvents();
    displayThisDayEvents(date);
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
    std::string temp = "Cześć, " + person->getName() + "!";
    QString qstr = QString::fromStdString(temp.c_str());
    QFont new_font("Arial", 35);
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
    delete addevwin;
}

void CalendarWindow::on_calendar_selectionChanged()
{
    QDate date = ui->calendar->selectedDate();
    refreshEvents(date);
    // clearThisDayEvents();
    // displayThisDayEvents(date);
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

void CalendarWindow::on_addEventButton_clicked()
{
    QString date = ui->calendar->selectedDate().toString("dd-MM-yyyy");
    this->addevwin->setDate(ui->calendar->selectedDate());
    this->addevwin->setPersonName(QString::fromStdString(this->person->getName()));
    addevwin->showOnScreen();
}

void CalendarWindow::on_delTraining_clicked()
{
    QString date = ui->calendar->selectedDate().toString("dd-MM-yyyy");
    this->delevwin->setDate(ui->calendar->selectedDate());
    this->delevwin->setPersonName(QString::fromStdString(this->person->getName()));
    delevwin->showOnScreen();
}

QDate CalendarWindow::getChoosenDate() const
{
    return ui->calendar->selectedDate();
}
