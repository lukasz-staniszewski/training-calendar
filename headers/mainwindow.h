#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "man.h"
#include "woman.h"
#include "calendarwindow.h"
#include "events.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/// Class main window represents starting window of program
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;         /*!< Pointer to window ui */

    CalendarWindow *calwin;     /*!< Pointer to calendar window */

    Person* person_using;       /*!< Pointer to person using */

    Events* familyevents;       /*!< Pointer to family trainings */

public:
    /// Constructor of MainWindow
    /// @param parent -> widget parent [QWidget*]
    MainWindow(QWidget *parent = nullptr);

    /// Destructor of MainWindow
    ~MainWindow();

private slots:
    /// Slot of clicking on "LOGIN" button
    void on_login_clicked();

    /// Slot of clicking on "GITLAB" button
    void on_gitbut_clicked();
};
#endif // MAINWINDOW_H
