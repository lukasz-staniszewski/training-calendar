#include "addeventscreen.h"
#include "ui_addeventscreen.h"
#include "QtDebug"
#include "QMessageBox"
#include "string"
#include "QDate"

AddEventScreen::AddEventScreen(QWidget *parent,Events* famev, QString person_name, QDate date) :
    QDialog(parent),
    ui(new Ui::AddEventScreen),
    familyevents(famev),
    person_name(person_name),
    date(date)
{
    ui->setupUi(this);
    ui->infotxt->setAlignment(Qt::AlignCenter);
}

AddEventScreen::~AddEventScreen()
{
    delete ui;
}

void AddEventScreen::on_cancelbutton_clicked()
{
    this->hide();
}

void AddEventScreen::setPersonName(QString name)
{
    this->person_name = name;
}

void AddEventScreen::setDate(QDate g_date)
{
    this->date = g_date;
}

void AddEventScreen::showOnScreen()
{
    QString qstr = "DODAJESZ JAKO " + this->person_name + ", W DNIU " + date.toString("dd-MM-yyyy")+"!";
    ui->infotxt->setText(qstr);
    this->show();
}

void AddEventScreen::on_addbutton_clicked()
{
    QString act_name = ui->lineEdit->text();
    QTime timestart = ui->inptimestart->time();
    QTime timefin = ui->inptimefinish->time();
    if(timestart>=timefin)
    {
        QMessageBox::warning(this, "BŁĄD", "ZOSTAŁ PODANY ZŁY CZAS!");
    }
    else if(act_name.length()<3)
    {
        QMessageBox::warning(this, "BŁĄD", "ZOSTAŁA PODANA ZŁA NAZWA TRENINGU!");
    }
    else
    {
        QString date_qstr = date.toString("dd-MM-yyyy");
        QString shour_qstr = timestart.toString("hh:mm");
        QString fhour_qstr = timefin.toString("hh:mm");
        familyevents->addEvent(Event(person_name.toStdString(), act_name.toStdString(), date_qstr.toStdString(), shour_qstr.toStdString(), fhour_qstr.toStdString()));
        this->hide();
    }
}
