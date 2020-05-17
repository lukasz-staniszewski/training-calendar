#include "calendarwindow.h"
#include "ui_calendarwindow.h"
#include <QString>
#include <QFont>
#include <QPainter>
#include <QTextCharFormat>

CalendarWindow::CalendarWindow(QWidget *parent, Person *person) :
    QDialog(parent),
    ui(new Ui::CalendarWindow),
    person(person)
{
    ui->setupUi(this);
    showWelcomeMessage();
    printActualDate();
    highlightToday();
    ui->calendar->setGridVisible(true);
    ui->backtodaybutton->setText(QString::fromStdString("DZISIAJ"));
}

void  CalendarWindow::highlightToday()
{
    QPainter painter;
    painter.setPen(Qt::blue);
    QTextCharFormat qtcf;
    qtcf.setFontWeight(80);
    qtcf.setForeground(QBrush(Qt::green));
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
    QString qstr = date.toString("'Wybrany dzień: 'dddd, dd.MM.yyyy");
    ui->actualdate->setText(qstr);
}

void CalendarWindow::on_backtodaybutton_clicked()
{
    ui->calendar->setSelectedDate(QDate::currentDate());
}
