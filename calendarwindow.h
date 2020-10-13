#ifndef CALENDARWINDOW_H
#define CALENDARWINDOW_H

#include <QDialog>
#include <person.h>
#include <events.h>
#include <QLabel>
#include "addeventscreen.h"
#include "deleteeventwindow.h"
namespace Ui {
class CalendarWindow;
}
/// Class CalendarWindow represents window with calendar, trainings etc.
class CalendarWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::CalendarWindow *ui;                 /*!< Pointer to ui */

    Person* person;                         /*!< Pointer to person using */

    Events* familyevents;                   /*!< Pointer to family trainings */

    AddEventScreen* addevwin;               /*!< Pointer to adding training screen */

    DeleteEventWindow* delevwin;            /*!< Pointer to deleting training screen */

    std::vector<QLabel *>npe_bar;           /*!< Vector of bars for nearest person events */

    std::vector<QLabel *>npe_date;          /*!< Vector of dates for nearest person events */

    std::vector<QLabel *>npe_hour;          /*!< Vector of hours for nearest person events */

    std::vector<QLabel *>npe_activity;      /*!< Vector of activities for nearest person events */

    std::vector<QLabel *>nfe_bar;           /*!< Vector of bars for nearest family events */

    std::vector<QLabel *>nfe_name;          /*!< Vector of names for nearest family events */

    std::vector<QLabel *>nfe_hour;          /*!< Vector of hours for nearest family events */

    std::vector<QLabel *>nfe_activity;      /*!< Vector of activities for nearest family events */

    int npe_bar_pos[2] = {1290, 90};        // HARDCODED STAFF FOR GUI!

    int bar_size[2] = {331, 51};

    int npe_act_pos[2] = {1510, 100};

    int npe_act_size[2] = {101, 31};

    int npe_date_pos[2] = {1300, 100};

    int npe_date_size[2] = {108, 31};

    int npe_hour_pos[2] = {1410, 100};

    int npe_hour_size[2] = {99, 31};

    int nfe_bar_pos[2] = {930, 90};

    int nfe_act_pos[2] = {1020, 100};

    int nfe_act_size[2] = {131, 31};

    int nfe_name_pos[2] = {940, 100};

    int nfe_name_size[2] = {91, 31};

    int nfe_hour_pos[2] = {1130, 100};

    int nfe_hour_size[2] = {121, 31};

    int standard_move = 60;

public:
    /// Explicit constructor of CalendarWindow
    /// @param parent -> parent widget [QWidget*]
    /// @param person -> person using [Person*]
    /// @param events -> family trainings [Events*]
    /// @returns nothing
    explicit CalendarWindow(QWidget *parent = nullptr, Person *person = nullptr, Events *events = nullptr);

    /// Destructor of CalendarWindow
    ~CalendarWindow();

    /// Method refreshing trainings on screen
    /// @param date -> date choosen on calendar [QDate]
    void refreshEvents(QDate date);

    /// Method getting choosen from calendar date
    /// @returns choosen date [QDate]
    QDate getChoosenDate() const;

private slots:
    /// Slot of changing selection on calendar
    void on_calendar_selectionChanged();

    /// Slot of clicking on "Back Today" button
    void on_backtodaybutton_clicked();

    /// Slot of button going to next month
    void on_pushButton_clicked();

    /// Slot of button going to previous month
    void on_pushButton_2_clicked();

    /// Slot of clicking on button adding event
    void on_addEventButton_clicked();

    ///  Slot of clicking on button deleteing event
    void on_delTraining_clicked();

    /// Slot of clicking on button refreshing events
    void on_refreshButton_clicked();

private:
    /// Method showing "Hi, {name}"
    void showWelcomeMessage();

    /// Method setuping Nearest Person Events blocks
    void setupNPE();

    /// Method setuping Nearest Family Events blocks
    /// @param date -> date choosen on calendar [QDate]
    void setupNFE(QDate date);

    /// Method clearing all Nearest Person Events blocks
    void clearNPE();

    /// Method showing Nearest Person events blocks
    void showNPE();

    /// Method clearing all Nearest Family Events blocks
    void clearNFE();

    /// Method showing Nearest Family Events
    void showNFE();

    /// Method prinintg actual date
    void printActualDate();

    /// Method highlighting actual date
    void highlightToday();

    /// Method making simple setup for calendar
    void setupCalendar();

    /// Method paints cells with taken days of training
    void paintTakenDays();

    /// Method clears calendar's cells
    void clearTakenDays();

    /// Method showing 'Delete Training' button depending
    void deleteButton(QDate date = QDate::currentDate());
};

#endif // CALENDARWINDOW_H
