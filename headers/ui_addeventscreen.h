/********************************************************************************
** Form generated from reading UI file 'addeventscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEVENTSCREEN_H
#define UI_ADDEVENTSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_AddEventScreen
{
public:
    QTimeEdit *inptimestart;
    QTimeEdit *inptimefinish;
    QLineEdit *lineEdit;
    QPushButton *addbutton;
    QPushButton *cancelbutton;
    QLabel *starthourtxt;
    QLabel *finhourtxt;
    QLabel *typeTreningtxt;
    QLabel *infotxt;
    QLabel *hellotxt;

    void setupUi(QDialog *AddEventScreen)
    {
        if (AddEventScreen->objectName().isEmpty())
            AddEventScreen->setObjectName(QString::fromUtf8("AddEventScreen"));
        AddEventScreen->resize(1011, 500);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush2(QColor(0, 0, 0, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        AddEventScreen->setPalette(palette);
        AddEventScreen->setCursor(QCursor(Qt::ArrowCursor));
        inptimestart = new QTimeEdit(AddEventScreen);
        inptimestart->setObjectName(QString::fromUtf8("inptimestart"));
        inptimestart->setGeometry(QRect(660, 110, 211, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font.setPointSize(9);
        inptimestart->setFont(font);
        inptimefinish = new QTimeEdit(AddEventScreen);
        inptimefinish->setObjectName(QString::fromUtf8("inptimefinish"));
        inptimefinish->setGeometry(QRect(660, 200, 211, 51));
        inptimefinish->setFont(font);
        lineEdit = new QLineEdit(AddEventScreen);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(660, 290, 211, 51));
        lineEdit->setFont(font);
        lineEdit->setAlignment(Qt::AlignCenter);
        addbutton = new QPushButton(AddEventScreen);
        addbutton->setObjectName(QString::fromUtf8("addbutton"));
        addbutton->setEnabled(true);
        addbutton->setGeometry(QRect(350, 370, 121, 51));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addbutton->sizePolicy().hasHeightForWidth());
        addbutton->setSizePolicy(sizePolicy);
        addbutton->setCursor(QCursor(Qt::PointingHandCursor));
        addbutton->setLayoutDirection(Qt::LeftToRight);
        addbutton->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/okbutt.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        addbutton->setIcon(icon);
        addbutton->setIconSize(QSize(200, 208));
        addbutton->setAutoRepeat(false);
        cancelbutton = new QPushButton(AddEventScreen);
        cancelbutton->setObjectName(QString::fromUtf8("cancelbutton"));
        cancelbutton->setGeometry(QRect(540, 370, 121, 51));
        cancelbutton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/cancbutt.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        cancelbutton->setIcon(icon1);
        cancelbutton->setIconSize(QSize(300, 200));
        starthourtxt = new QLabel(AddEventScreen);
        starthourtxt->setObjectName(QString::fromUtf8("starthourtxt"));
        starthourtxt->setGeometry(QRect(40, 115, 611, 41));
        starthourtxt->setPixmap(QPixmap(QString::fromUtf8(":/img/start_hour.jpg")));
        finhourtxt = new QLabel(AddEventScreen);
        finhourtxt->setObjectName(QString::fromUtf8("finhourtxt"));
        finhourtxt->setGeometry(QRect(40, 200, 611, 51));
        finhourtxt->setPixmap(QPixmap(QString::fromUtf8(":/img/finish_hour.jpg")));
        typeTreningtxt = new QLabel(AddEventScreen);
        typeTreningtxt->setObjectName(QString::fromUtf8("typeTreningtxt"));
        typeTreningtxt->setGeometry(QRect(40, 290, 601, 51));
        typeTreningtxt->setPixmap(QPixmap(QString::fromUtf8(":/img/type_of_trainging.jpg")));
        infotxt = new QLabel(AddEventScreen);
        infotxt->setObjectName(QString::fromUtf8("infotxt"));
        infotxt->setGeometry(QRect(250, 440, 511, 41));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        infotxt->setFont(font1);
        hellotxt = new QLabel(AddEventScreen);
        hellotxt->setObjectName(QString::fromUtf8("hellotxt"));
        hellotxt->setGeometry(QRect(-10, 10, 991, 61));
        hellotxt->setPixmap(QPixmap(QString::fromUtf8(":/img/add_training_text.jpg")));

        retranslateUi(AddEventScreen);

        QMetaObject::connectSlotsByName(AddEventScreen);
    } // setupUi

    void retranslateUi(QDialog *AddEventScreen)
    {
        AddEventScreen->setWindowTitle(QCoreApplication::translate("AddEventScreen", "Dialog", nullptr));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        addbutton->setText(QString());
#if QT_CONFIG(shortcut)
        addbutton->setShortcut(QCoreApplication::translate("AddEventScreen", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        cancelbutton->setText(QString());
#if QT_CONFIG(shortcut)
        cancelbutton->setShortcut(QCoreApplication::translate("AddEventScreen", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        starthourtxt->setText(QString());
        finhourtxt->setText(QString());
        typeTreningtxt->setText(QString());
        infotxt->setText(QString());
        hellotxt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddEventScreen: public Ui_AddEventScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEVENTSCREEN_H
