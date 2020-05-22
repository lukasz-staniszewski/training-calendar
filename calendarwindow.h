#ifndef CALENDARWINDOW_H
#define CALENDARWINDOW_H

#include <QDialog>
#include <person.h>
#include <events.h>
#include "addeventscreen.h"
#include "deleteeventwindow.h"
namespace Ui {
class CalendarWindow;
}

class CalendarWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CalendarWindow(QWidget *parent = nullptr, Person *person = nullptr, Events *events = nullptr);
    ~CalendarWindow();
    void refreshEvents(QDate date);
    QDate getChoosenDate() const;

private slots:
    void on_calendar_selectionChanged();

    void on_backtodaybutton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_addEventButton_clicked();

    void on_delTraining_clicked();

private:
    Ui::CalendarWindow *ui;
    Person* person;
    Events* familyevents;
    AddEventScreen* addevwin;
    DeleteEventWindow* delevwin;
    void showWelcomeMessage();
    void displayNearestPersonEvents();
    void displayThisDayEvents(QDate date);
    void displayNearDates();
    void clearThisDayEvents();
    void printActualDate();
    void highlightToday();
    void setupCalendar();
};

#endif // CALENDARWINDOW_H
