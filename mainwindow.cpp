#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFile>
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
    this->familyevents->get_from_file(":/data/events/Sportevents.txt");
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
