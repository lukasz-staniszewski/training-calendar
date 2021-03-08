#include "headers/deleteeventwindow.h"
#include "headers/ui_deleteeventwindow.h"
#include <QMessageBox>

DeleteEventWindow::DeleteEventWindow(QWidget *parent, Events* famev, QString person_name, QDate date) :
    QDialog(parent),
    ui(new Ui::DeleteEventWindow),
    familyevents(famev),
    person_name(person_name),
    date(date)
{
    ui->setupUi(this);
    ui->infotxt->setAlignment(Qt::AlignCenter);
}

DeleteEventWindow::~DeleteEventWindow()
{
    delete ui;
}

void DeleteEventWindow::setPersonName(QString name)
{
    this->person_name = name;
}

void DeleteEventWindow::setDate(QDate g_date)
{
    this->date = g_date;
}

void DeleteEventWindow::showOnScreen()
{
    QString qstr = "USUWASZ JAKO " + this->person_name + ", W DNIU " + date.toString("dd-MM-yyyy")+"!";
    ui->infotxt->setText(qstr);
    this->show();
}

void DeleteEventWindow::on_cancelbutton_clicked()
{
    this->hide();
}

void DeleteEventWindow::on_delbutton_clicked()
{
    QString act_name = ui->lineEdit->text();
    QTime timestart = ui->inptimestart->time();
    QString stime_qstr = timestart.toString("hh:mm");
    QString date_qstr = date.toString("dd-MM-yyyy");
    if(!isSuchEvent(person_name, act_name, date_qstr, stime_qstr))
    {
        QMessageBox::warning(this, "BŁĄD", "PRÓBA USUNIĘCIA NIEISTNIEJĄCEGO TRENINGU!");
    }
    else
    {
        familyevents->delEvent(person_name, act_name, date_qstr, stime_qstr);
        this->hide();
    }
}

bool DeleteEventWindow::isSuchEvent(QString pers_name, QString act_name, QString date_str, QString stime_str)
{
    for(auto ev:familyevents->events)
    {
        if(ev.getDate()==date_str && ev.getPersonName() == pers_name && ev.getStartHour() == stime_str && ev.getActivity()==act_name)
        {
            return true;
        }
    }
    return false;
}
