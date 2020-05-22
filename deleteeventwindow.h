#ifndef DELETEEVENTWINDOW_H
#define DELETEEVENTWINDOW_H
#include <QDate>
#include <QDialog>
#include <QString>
#include "events.h"

namespace Ui {
class DeleteEventWindow;
}

class DeleteEventWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteEventWindow(QWidget *parent = nullptr, Events* familyevents = nullptr, QString person_name = "none", QDate date = QDate::currentDate());
    ~DeleteEventWindow();
    void setPersonName(QString name);
    void setDate(QDate date);
    void showOnScreen();
    bool isSuchEvent(QString pers_name, QString act_name, QString date, QString start_hour);

private slots:
    void on_cancelbutton_clicked();

    void on_delbutton_clicked();

private:
    Ui::DeleteEventWindow *ui;
    Events *familyevents;
    QString person_name;
    QDate date;
};

#endif // DELETEEVENTWINDOW_H
