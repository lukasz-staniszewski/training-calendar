#ifndef ADDEVENTSCREEN_H
#define ADDEVENTSCREEN_H
#include <QDate>
#include <QDialog>
#include <QString>
#include "events.h"

namespace Ui {
class AddEventScreen;
}

class AddEventScreen : public QDialog
{
    Q_OBJECT

public:
    explicit AddEventScreen(QWidget *parent = nullptr, Events* familyevents = nullptr, QString person_name = "none", QDate date = QDate::currentDate());
    ~AddEventScreen();
    void setPersonName(QString name);
    void setDate(QDate date);
    void showOnScreen();

private slots:
    void on_cancelbutton_clicked();

    void on_addbutton_clicked();

private:
    Ui::AddEventScreen *ui;
    Events* familyevents;
    QString person_name;
    QDate date;
};

#endif // ADDEVENTSCREEN_H
