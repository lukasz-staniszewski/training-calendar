#include "headers/calendarwindow.h"
#include "headers/ui_calendarwindow.h"
#include <QString>
#include <QFont>
#include <QPainter>
#include <QDebug>
#include <QTextCharFormat>
#include "headers/event.h"
#include "headers/events.h"

CalendarWindow::CalendarWindow(QWidget *parent, Person *person, Events *events) :
    QDialog(parent),
    ui(new Ui::CalendarWindow),
    person(person),
    familyevents(events)
{
    ui->setupUi(this);
    addevwin = new AddEventScreen(this, familyevents);
    delevwin = new DeleteEventWindow(this, familyevents);
    clearNFE();
    clearNPE();
    showWelcomeMessage();
    printActualDate();
    highlightToday();
    refreshEvents(QDate::currentDate());
    setupCalendar();
    paintTakenDays();
    deleteButton();
}

CalendarWindow::~CalendarWindow()
{
    delete ui;
    delete addevwin;
    delete delevwin;
}
void CalendarWindow::setupNPE()
{
    this->npe_bar.clear();
    this->npe_activity.clear();
    this->npe_hour.clear();
    this->npe_date.clear();
    QLabel *bar;
    QLabel *act;
    QLabel *date;
    QLabel *hour;
    int paritycounter = 0;
    for(unsigned int i=0; i<this->familyevents->events.size(); i++)
    {
        QDate tempDate;
        if(tempDate.fromString(this->familyevents->events[i].getDate(),"dd-MM-yyyy") >= QDate::currentDate() &&
           this->familyevents->events[i].getPersonName().toStdString() == this->person->getName())
        {
            bar = new QLabel(this);
            act = new QLabel(this);
            date = new QLabel(this);
            hour = new QLabel(this);
            QPixmap qmp;
            if(paritycounter++%2 == 0){
                qmp = QPixmap(":/img/green-bar.jpg");
            }
            else{
                qmp = QPixmap(":/img/yellow-bar.jpg");
            }
            bar->setPixmap(qmp);
            bar->setGeometry(this->npe_bar_pos[0],
                             this->npe_bar_pos[1] + this->npe_bar.size() * this->standard_move,
                             this->bar_size[0],
                             this->bar_size[1]);
            bar->setText(QString().fromStdString(""));
            bar->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
            bar->setAlignment(Qt::AlignLeft | Qt::AlignHCenter);
            act->setText(this->familyevents->events[i].getActivity());
            QFont font;
            font.setBold(true);
            font.setKerning(true);
            font.setFamily("MS Shell Dlg 2");
            font.setWeight(9);
            act->setFont(font);
            date->setFont(font);
            font.setWeight(8);
            hour->setFont(font);
            date->setText(this->familyevents->events[i].getDate());
            hour->setText(this->familyevents->events[i].getStartHour() + " - " + this->familyevents->events[i].getEndHour());
            act->setGeometry(this->npe_act_pos[0],
                             this->npe_act_pos[1] + this->npe_bar.size() * this->standard_move,
                             this->npe_act_size[0],
                             this->npe_act_size[1]);
            date->setGeometry(this->npe_date_pos[0],
                              this->npe_date_pos[1] + this->npe_bar.size() * this->standard_move,
                              this->npe_date_size[0],
                              this->npe_date_size[1]);
            hour->setGeometry(this->npe_hour_pos[0],
                              this->npe_hour_pos[1] + this->npe_bar.size() * this->standard_move,
                              this->npe_hour_size[0],
                              this->npe_hour_size[1]);
            act->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
            act->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
            date->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
            date->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
            hour->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
            hour->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
            this->npe_bar.push_back(bar);
            this->npe_date.push_back(date);
            this->npe_hour.push_back(hour);
            this->npe_activity.push_back(act);
        }
    }
}

void CalendarWindow::setupNFE(QDate date)
{
    this->nfe_bar.clear();
    this->nfe_activity.clear();
    this->nfe_hour.clear();
    this->nfe_name.clear();
    QLabel *bar;
    QLabel *act;
    QLabel *name;
    QLabel *hour;
    int paritycounter = 0;
    QString qstr(date.toString("dd-MM-yyyy"));
    for(unsigned int i = 0; i<this->familyevents->events.size(); i++)
    {
        if(this->familyevents->events[i].getDate() == qstr)
        {
            bar = new QLabel(this);
            act = new QLabel(this);
            name = new QLabel(this);
            hour = new QLabel(this);
            QPixmap qmp;
            if(paritycounter++%2 == 0){
                qmp = QPixmap(":/img/green-bar.jpg");
            }
            else{
                qmp = QPixmap(":/img/yellow-bar.jpg");
            }
            bar->setPixmap(qmp);
            bar->setGeometry(this->nfe_bar_pos[0],
                             this->nfe_bar_pos[1] + this->nfe_bar.size() * this->standard_move,
                             this->bar_size[0],
                             this->bar_size[1]);
            bar->setText(QString().fromStdString(""));
            bar->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
            bar->setAlignment(Qt::AlignLeft | Qt::AlignHCenter);
            act->setText(this->familyevents->events[i].getActivity());
            QFont font;
            font.setBold(true);
            font.setKerning(true);
            font.setFamily("MS Shell Dlg 2");
            font.setWeight(9);
            act->setFont(font);
            name->setFont(font);
            font.setWeight(8);
            hour->setFont(font);
            name->setText(this->familyevents->events[i].getPersonName());
            hour->setText(this->familyevents->events[i].getStartHour() + " - " + this->familyevents->events[i].getEndHour());
            act->setGeometry(this->nfe_act_pos[0],
                             this->nfe_act_pos[1] + this->nfe_bar.size() * this->standard_move,
                             this->nfe_act_size[0],
                             this->nfe_act_size[1]);
            name->setGeometry(this->nfe_name_pos[0],
                              this->nfe_name_pos[1] + this->nfe_bar.size() * this->standard_move,
                              this->nfe_name_size[0],
                              this->nfe_name_size[1]);
            hour->setGeometry(this->nfe_hour_pos[0],
                              this->nfe_hour_pos[1] + this->nfe_bar.size() * this->standard_move,
                              this->nfe_hour_size[0],
                              this->nfe_hour_size[1]);
            act->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
            act->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
            name->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
            name->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
            hour->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
            hour->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
            this->nfe_bar.push_back(bar);
            this->nfe_name.push_back(name);
            this->nfe_hour.push_back(hour);
            this->nfe_activity.push_back(act);
        }
    }
}

void CalendarWindow::deleteButton(QDate date)
{
    if(familyevents->isPersonEvent(QString::fromStdString(person->getName()), date.toString("dd-MM-yyyy")))
    {
        ui->delTraining->show();
    }
    else
    {
        ui->delTraining->hide();
    }
}
void CalendarWindow::paintTakenDays()
{
    QTextCharFormat qtcfTakenDays;
    qtcfTakenDays.setFontWeight(1000);
    qtcfTakenDays.setFontPointSize(12);
    qtcfTakenDays.setFontItalic(true);
    QColor takendayscolor;
    takendayscolor.setRgb(255, 238, 179);
    qtcfTakenDays.setBackground(QBrush(takendayscolor));
    QTextCharFormat qtcfWeekend = qtcfTakenDays;
    qtcfWeekend.setForeground((QBrush(Qt::red)));
    QTextCharFormat qtcfToday = qtcfTakenDays;
    qtcfToday.setForeground(QBrush(Qt::blue));
    QDate date;
    if (this->familyevents->events.size()<1)
    {
        return;
    }
    for(auto training:familyevents->events)
    {
        if(training.getPersonName().toStdString()==person->getName())
        {
            date = QDate::fromString(training.getDate(), "dd-MM-yyyy");
            if(date==QDate::currentDate())
            {
                ui->calendar->setDateTextFormat(date, qtcfToday);
            }
            else if(date.dayOfWeek()==6||date.dayOfWeek()==7)
            {
                ui->calendar->setDateTextFormat(date, qtcfWeekend);
            }
            else
            {
                ui->calendar->setDateTextFormat(date, qtcfTakenDays);
            }
         }
    }
}

void CalendarWindow::clearTakenDays()
{
    QDate all_dates;
    QTextCharFormat qtcfAllDates;
    QColor allcellscolor;
    allcellscolor.setRgb(255, 255, 220);
    qtcfAllDates.setBackground(QBrush(allcellscolor));
    ui->calendar->setDateTextFormat(all_dates, qtcfAllDates);
    this->highlightToday();

}
void CalendarWindow::setupCalendar()
{
    ui->calendar->setNavigationBarVisible(false);
    ui->calendar->setGridVisible(true);
}

void CalendarWindow::clearNPE()
{
    for(unsigned int i=0;i < this->npe_bar.size();i++)
    {
        npe_bar[i]->hide();
        npe_date[i]->hide();
        npe_hour[i]->hide();
        npe_activity[i]->hide();
    }
}
void CalendarWindow::clearNFE()
{
    for(unsigned int i=0;i < this->nfe_bar.size();i++)
    {
        nfe_bar[i]->hide();
        nfe_name[i]->hide();
        nfe_hour[i]->hide();
        nfe_activity[i]->hide();
    }
}

void CalendarWindow::showNPE()
{
    for(unsigned int i=0;i < this->npe_bar.size();i++)
    {
        npe_bar[i]->show();
        npe_date[i]->show();
        npe_activity[i]->show();
        npe_hour[i]->show();
    }
}
void CalendarWindow::showNFE()
{
    for(unsigned int i=0;i < this->nfe_bar.size();i++)
    {
        nfe_bar[i]->show();
        nfe_name[i]->show();
        nfe_activity[i]->show();
        nfe_hour[i]->show();
    }
}


void  CalendarWindow::refreshEvents(QDate date)
{
    clearNPE();
    setupNPE();
    showNPE();
    clearNFE();
    setupNFE(date);
    showNFE();
}
void  CalendarWindow::highlightToday()
{

    QTextCharFormat qtcf;
    qtcf.setFontWeight(80);
    QColor todaycolor;
    todaycolor.setRgb(0, 82, 204);
    qtcf.setForeground(QBrush(todaycolor));
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

void CalendarWindow::on_calendar_selectionChanged()
{
    QDate date = ui->calendar->selectedDate();
    refreshEvents(date);
    QString qstr = date.toString("'Wybrany dzień: 'dddd, dd.MM.yyyy");
    ui->actualdate->setText(qstr);
    deleteButton(date);
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
    this->addevwin->operator=(ui->calendar->selectedDate());
    this->addevwin->operator=(QString::fromStdString(this->person->getName()));
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

void CalendarWindow::on_refreshButton_clicked()
{
    refreshEvents(ui->calendar->selectedDate());
    clearTakenDays();
    paintTakenDays();
    deleteButton();
}
