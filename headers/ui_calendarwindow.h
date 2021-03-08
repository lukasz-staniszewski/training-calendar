/********************************************************************************
** Form generated from reading UI file 'calendarwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARWINDOW_H
#define UI_CALENDARWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CalendarWindow
{
public:
    QCalendarWidget *calendar;
    QLabel *welcomemsg;
    QLabel *actualdate;
    QPushButton *backtodaybutton;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *YourNearestTrening;
    QLabel *FamilyDayTrening;
    QPushButton *addEventButton;
    QPushButton *delTraining;
    QPushButton *refreshButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *white;

    void setupUi(QDialog *CalendarWindow)
    {
        if (CalendarWindow->objectName().isEmpty())
            CalendarWindow->setObjectName(QString::fromUtf8("CalendarWindow"));
        CalendarWindow->resize(1631, 640);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        CalendarWindow->setPalette(palette);
        calendar = new QCalendarWidget(CalendarWindow);
        calendar->setObjectName(QString::fromUtf8("calendar"));
        calendar->setGeometry(QRect(0, 150, 901, 451));
        QPalette palette1;
        QBrush brush1(QColor(255, 250, 239, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(186, 215, 209, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        QBrush brush3(QColor(102, 236, 196, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        QBrush brush4(QColor(0, 120, 215, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        calendar->setPalette(palette1);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        calendar->setFont(font);
        welcomemsg = new QLabel(CalendarWindow);
        welcomemsg->setObjectName(QString::fromUtf8("welcomemsg"));
        welcomemsg->setGeometry(QRect(410, 0, 491, 151));
        actualdate = new QLabel(CalendarWindow);
        actualdate->setObjectName(QString::fromUtf8("actualdate"));
        actualdate->setGeometry(QRect(0, 600, 891, 41));
        backtodaybutton = new QPushButton(CalendarWindow);
        backtodaybutton->setObjectName(QString::fromUtf8("backtodaybutton"));
        backtodaybutton->setGeometry(QRect(140, 80, 121, 61));
        backtodaybutton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/today.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        backtodaybutton->setIcon(icon);
        backtodaybutton->setIconSize(QSize(120, 100));
        pushButton = new QPushButton(CalendarWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 80, 121, 61));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setLayoutDirection(Qt::LeftToRight);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/next_month.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(120, 100));
        pushButton->setCheckable(false);
        pushButton_2 = new QPushButton(CalendarWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 80, 121, 61));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/prev_month.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(120, 100));
        YourNearestTrening = new QLabel(CalendarWindow);
        YourNearestTrening->setObjectName(QString::fromUtf8("YourNearestTrening"));
        YourNearestTrening->setGeometry(QRect(1340, -20, 261, 131));
        YourNearestTrening->setPixmap(QPixmap(QString::fromUtf8(":/img/nearest.jpg")));
        FamilyDayTrening = new QLabel(CalendarWindow);
        FamilyDayTrening->setObjectName(QString::fromUtf8("FamilyDayTrening"));
        FamilyDayTrening->setGeometry(QRect(970, -10, 271, 111));
        FamilyDayTrening->setPixmap(QPixmap(QString::fromUtf8(":/img/familytday.jpg")));
        addEventButton = new QPushButton(CalendarWindow);
        addEventButton->setObjectName(QString::fromUtf8("addEventButton"));
        addEventButton->setGeometry(QRect(0, 10, 121, 61));
        addEventButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/add_event.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        addEventButton->setIcon(icon3);
        addEventButton->setIconSize(QSize(120, 110));
        delTraining = new QPushButton(CalendarWindow);
        delTraining->setObjectName(QString::fromUtf8("delTraining"));
        delTraining->setGeometry(QRect(140, 10, 121, 61));
        delTraining->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/del_event.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        delTraining->setIcon(icon4);
        delTraining->setIconSize(QSize(120, 100));
        refreshButton = new QPushButton(CalendarWindow);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));
        refreshButton->setGeometry(QRect(280, 10, 121, 61));
        refreshButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/refresh-cal.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        refreshButton->setIcon(icon5);
        refreshButton->setIconSize(QSize(120, 200));
        label = new QLabel(CalendarWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1270, 80, 21, 531));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/rod.jpg")));
        label_2 = new QLabel(CalendarWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(910, 80, 21, 531));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/rod.jpg")));
        white = new QLabel(CalendarWindow);
        white->setObjectName(QString::fromUtf8("white"));
        white->setGeometry(QRect(915, -15, 851, 691));
        white->setPixmap(QPixmap(QString::fromUtf8(":/img/white.jpg")));
        calendar->raise();
        welcomemsg->raise();
        actualdate->raise();
        backtodaybutton->raise();
        pushButton->raise();
        pushButton_2->raise();
        addEventButton->raise();
        delTraining->raise();
        refreshButton->raise();
        white->raise();
        label_2->raise();
        label->raise();
        FamilyDayTrening->raise();
        YourNearestTrening->raise();

        retranslateUi(CalendarWindow);

        QMetaObject::connectSlotsByName(CalendarWindow);
    } // setupUi

    void retranslateUi(QDialog *CalendarWindow)
    {
        CalendarWindow->setWindowTitle(QCoreApplication::translate("CalendarWindow", "Dialog", nullptr));
        welcomemsg->setText(QCoreApplication::translate("CalendarWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">Witaj, user</span></p></body></html>", nullptr));
        actualdate->setText(QString());
        backtodaybutton->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        YourNearestTrening->setText(QString());
        FamilyDayTrening->setText(QString());
        addEventButton->setText(QString());
        delTraining->setText(QString());
        refreshButton->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        white->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CalendarWindow: public Ui_CalendarWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARWINDOW_H
