#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>


bool check_name_corectness(std::string str)
{
    if(str.length()<3||str.length()>15||(str[0]<'A' || str[0]>'Z'))
    {
        return false;
    }
    for(unsigned int i=0; i < str.length(); i++)
    {

        if(str[i]<'a' && str[i]>'z')
        {
            return false;
        }
    }
    return true;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/logo.jpg");
    ui->pict->setPixmap(pix.scaled(800, 500, Qt::KeepAspectRatio));
    person_using = new Person;
    familyevents = new Events;
    Event ev1("Mateusz", "Piłka nożna", "19-05-2020");
    Event ev2("Lukasz", "Piłka nożna", "19-05-2020");
    Event ev3("Albert", "Piłka nożna", "24-05-2020");
    Event ev4("Ania", "Piłka nożna", "24-05-2020");
    Event ev5("Lukasz", "Piłka nożna", "21-05-2020");
    Event ev6("Lukasz", "Piłka nożna", "24-05-2020");
    Event ev7("Ania", "Piłka nożna", "19-05-2020");
    Event ev8("Albert", "Piłka nożna", "19-05-2020");
    Event ev9("Albert", "Piłka nożna", "19-05-2020");
    Event ev10("Mateusz", "Piłka nożna", "24-05-2020");
    Event ev11("Mateusz", "Piłka nożna", "19-05-2020");
    Event ev12("Lukasz", "Silownia", "22-05-2020");
    this->familyevents->add_event(ev1);
    this->familyevents->add_event(ev2);
    this->familyevents->add_event(ev3);
    this->familyevents->add_event(ev4);
    this->familyevents->add_event(ev5);
    this->familyevents->add_event(ev6);
    this->familyevents->add_event(ev7);
    this->familyevents->add_event(ev8);
    this->familyevents->add_event(ev9);
    this->familyevents->add_event(ev10);
    this->familyevents->add_event(ev11);
    this->familyevents->add_event(ev12);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete calwin;
    delete person_using;
}


void MainWindow::on_login_clicked()
{
    QString name = ui->lineEdit->text();
    if(check_name_corectness(name.toStdString())){
        person_using->set_name(name.toStdString());
        hide();
        calwin = new CalendarWindow(this, person_using, familyevents);
        calwin->show();
    }
    else
    {
        QMessageBox::warning(this, "FAILURE", "YOU TYPED WRONG NAME!");
    }
}

void MainWindow::on_gitbut_clicked()
{
    QDesktopServices::openUrl(QUrl("https://gitlab-stud.elka.pw.edu.pl/lstanisz/Calendar"));
}
