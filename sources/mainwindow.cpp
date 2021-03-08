#include "headers/mainwindow.h"
#include "headers/ui_mainwindow.h"
#include <QPixmap>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QStandardPaths>


bool checkNameCorectness(std::string str)
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
    familyevents = new Events;
    this->familyevents->getFromFile(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + QString("/Sportevents.txt"));

}

MainWindow::~MainWindow()
{
    this->familyevents->saveToFile(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation).toStdString() + "/Sportevents.txt");
    delete ui;
    delete calwin;
    delete familyevents;
}

void MainWindow::on_login_clicked()
{
    QString name = ui->lineEdit->text();
    if(checkNameCorectness(name.toStdString())){
        if(name[name.length()-1] == 'a')
            person_using = new Woman(name.toStdString());
        else
            person_using = new Man(name.toStdString());
        hide();
        calwin = new CalendarWindow(this, person_using, familyevents);
        calwin->show();
    }
    else
    {
        QMessageBox::warning(this, "BŁĄD", "WPISANE ZOSTAŁO ZŁE IMIE!");
    }
}

void MainWindow::on_gitbut_clicked()
{
    QDesktopServices::openUrl(QUrl("https://gitlab-stud.elka.pw.edu.pl/lstanisz/Calendar"));
}
