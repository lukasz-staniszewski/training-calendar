#ifndef ADDEVENTSCREEN_H
#define ADDEVENTSCREEN_H
#include <QDate>
#include <QDialog>
#include <QString>
#include "events.h"

namespace Ui {
class AddEventScreen;
}
/// Class AddEventScreen represents a screen allowing to add Training
class AddEventScreen : public QDialog
{
    Q_OBJECT

private:
    Ui::AddEventScreen *ui;                       /*!<Class ui pointer*/

    Events* familyevents;                         /*!<Family events pointer*/

    QString person_name;                          /*!<Name of person using program*/

    QDate date;                                   /*!<Choosen on calendar date to add training*/

public:
    /// Explicit constructor of AddEventScreen
    /// @param parent -> parent of widget [QWidget*]
    /// @param familyevents -> family trainings [Events*]
    /// @param person_name -> name of person [QString]
    /// @param date -> choosen date [QDate]
    /// @returns nothing
    explicit AddEventScreen(QWidget *parent = nullptr, Events* familyevents = nullptr, QString person_name = "none", QDate date = QDate::currentDate());

    /// Destructor of AddEventScreen
    ~AddEventScreen();

    /// Assingment operator setting name of person using
    /// @param name -> name of person using [const QString]
    /// @returns nothing
    void operator=(const QString name);

    /// Assingment operator setting date of new training
    /// @param date -> date of adding training [const QDate]
    /// @returns nothing
    void operator=(const QDate date);

    /// Void method showing Adding Event Screen
    void showOnScreen();

    /// Method checking whether there is in datebase training of such person on such date on such starting hour and with such training type
    /// @param pers_name -> name of person to search [QString]
    /// @param act_name -> name of activity to search [QString]
    /// @param date -> date of training [QString]
    /// @param start_hour -> starting hour of training [QString]
    /// @returns true if there is such event in trainings
    bool isSuchEvent(QString pers_name, QString act_name, QString date, QString start_hour);

private:
    /// Setter of name of person using
    /// @param name -> name of person [QString]
    /// @returns nothing
    void setPersonName(QString name);

    /// Setter of date of creating training
    /// @param date -> date of training [QDate]
    /// @returns nothing
    void setDate(QDate date);

private slots:
    /// Slot of clicking on "CANCEL" button
    void on_cancelbutton_clicked();

    /// Slot of clicking on "OK" button
    void on_addbutton_clicked();
};

#endif // ADDEVENTSCREEN_H
