#ifndef CALENDARWINDOW_H
#define CALENDARWINDOW_H

#include <QDialog>
#include <person.h>
#include <events.h>
namespace Ui {
class CalendarWindow;
}

class CalendarWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CalendarWindow(QWidget *parent = nullptr, Person *person = nullptr, Events *events = nullptr);
    ~CalendarWindow();

private slots:
    void on_calendar_selectionChanged();

    void on_backtodaybutton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CalendarWindow *ui;
    Person* person;
    Events* familyevents;
    void showWelcomeMessage();
    void display_nearest_person_events();
    void display_this_day_events(QDate date);
    void displayNearDates();
    void clear_this_day_events();
    void printActualDate();
    void highlightToday();
};

#endif // CALENDARWINDOW_H
