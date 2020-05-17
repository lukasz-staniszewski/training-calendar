#include "calendarwindow.h"
#include "ui_calendarwindow.h"
#include "QString"
#include "QFont"

CalendarWindow::CalendarWindow(QWidget *parent, Person *person) :
    QDialog(parent),
    ui(new Ui::CalendarWindow),
    person(person)
{
    ui->setupUi(this);
    std::string temp = "Welcome, " + person->get_name();
    QString qstr = QString::fromStdString(temp.c_str());
    QFont new_font("Arial", 55);
    ui->welcomemsg->setText(qstr);
    ui->welcomemsg->setFont(new_font);
    ui->welcomemsg->setAlignment(Qt::AlignCenter);
    QFont new_font_date("Arial", 14);
    ui->actualdate->setFont(new_font_date);
    ui->actualdate->setAlignment(Qt::AlignCenter);
    QDate date = ui->calendar->selectedDate();
    qstr = date.toString();
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
    QString qstr = date.toString();
    ui->actualdate->setText(qstr);
}
