#ifndef CALENDARWINDOW_H
#define CALENDARWINDOW_H

#include <QDialog>
#include <person.h>
namespace Ui {
class CalendarWindow;
}

class CalendarWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CalendarWindow(QWidget *parent = nullptr, Person *person = nullptr);
    ~CalendarWindow();

private slots:
    void on_calendar_selectionChanged();

    void on_backtodaybutton_clicked();

private:
    Ui::CalendarWindow *ui;
    Person* person;
    void showWelcomeMessage();
    void printActualDate();
    void highlightToday();
};

#endif // CALENDARWINDOW_H
