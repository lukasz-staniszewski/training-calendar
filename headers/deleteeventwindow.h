#ifndef DELETEEVENTWINDOW_H
#define DELETEEVENTWINDOW_H
#include <QDate>
#include <QDialog>
#include <QString>
#include "events.h"

namespace Ui {
class DeleteEventWindow;
}
/// Class DeleteEventWindow represents Screen while deleting a training
class DeleteEventWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::DeleteEventWindow *ui;          /*!< Pointer to class ui */

    Events *familyevents;               /*!< Pointer to family trainings */

    QString person_name;                /*!< Name of person using */

    QDate date;                         /*!< Choosen on calendar date [QDate] */

public:
    /// Explicit constructor of DeleteEventWindow
    /// @param parent -> widget parent [QWidget*]
    /// @param familyevents -> family trainings [Events*]
    /// @param person_name -> name of person using [QString]
    /// @param date -> date choosen on calendar [QDate]
    explicit DeleteEventWindow(QWidget *parent = nullptr, Events* familyevents = nullptr, QString person_name = "none", QDate date = QDate::currentDate());

    /// Destructor of DeleteEventWindow
    ~DeleteEventWindow();

    /// Setter of name of person using
    /// @param name -> new name [QString]
    void setPersonName(QString name);

    /// Setter of date choosen on calendar
    /// @param date -> choosen date [QDate]
    void setDate(QDate date);

    /// Method showing window on screen
    void showOnScreen();

    /// Method checking whether there is in datebase training of such person on such date on such starting hour and with such training type
    /// @param pers_name -> name of person to search [QString]
    /// @param act_name -> name of activity to search [QString]
    /// @param date -> date of training [QString]
    /// @param start_hour -> starting hour of training [QString]
    /// @returns true if there is such event in trainings
    bool isSuchEvent(QString pers_name, QString act_name, QString date, QString start_hour);

private slots:
    /// Slot of clicking on "CANCEL" button
    void on_cancelbutton_clicked();

    /// Slot of clicking on "OK" button
    void on_delbutton_clicked();
};

#endif // DELETEEVENTWINDOW_H
