/********************************************************************************
** Form generated from reading UI file 'deleteeventwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEEVENTWINDOW_H
#define UI_DELETEEVENTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_DeleteEventWindow
{
public:
    QPushButton *cancelbutton;
    QLineEdit *lineEdit;
    QPushButton *delbutton;
    QLabel *typeTreningtxt;
    QLabel *infotxt;
    QTimeEdit *inptimestart;
    QLabel *hellotxt;
    QLabel *starthourtxt;

    void setupUi(QDialog *DeleteEventWindow)
    {
        if (DeleteEventWindow->objectName().isEmpty())
            DeleteEventWindow->setObjectName(QString::fromUtf8("DeleteEventWindow"));
        DeleteEventWindow->resize(998, 406);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        DeleteEventWindow->setPalette(palette);
        cancelbutton = new QPushButton(DeleteEventWindow);
        cancelbutton->setObjectName(QString::fromUtf8("cancelbutton"));
        cancelbutton->setGeometry(QRect(540, 280, 121, 51));
        cancelbutton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/cancbutt.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        cancelbutton->setIcon(icon);
        cancelbutton->setIconSize(QSize(300, 200));
        lineEdit = new QLineEdit(DeleteEventWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(670, 200, 211, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font.setPointSize(9);
        lineEdit->setFont(font);
        lineEdit->setAlignment(Qt::AlignCenter);
        delbutton = new QPushButton(DeleteEventWindow);
        delbutton->setObjectName(QString::fromUtf8("delbutton"));
        delbutton->setEnabled(true);
        delbutton->setGeometry(QRect(360, 280, 121, 51));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(delbutton->sizePolicy().hasHeightForWidth());
        delbutton->setSizePolicy(sizePolicy);
        delbutton->setCursor(QCursor(Qt::PointingHandCursor));
        delbutton->setLayoutDirection(Qt::LeftToRight);
        delbutton->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/okbutt.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        delbutton->setIcon(icon1);
        delbutton->setIconSize(QSize(200, 208));
        delbutton->setAutoRepeat(false);
        typeTreningtxt = new QLabel(DeleteEventWindow);
        typeTreningtxt->setObjectName(QString::fromUtf8("typeTreningtxt"));
        typeTreningtxt->setGeometry(QRect(50, 200, 601, 51));
        typeTreningtxt->setPixmap(QPixmap(QString::fromUtf8(":/img/type_of_trainging.jpg")));
        infotxt = new QLabel(DeleteEventWindow);
        infotxt->setObjectName(QString::fromUtf8("infotxt"));
        infotxt->setGeometry(QRect(260, 340, 511, 41));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        infotxt->setFont(font1);
        inptimestart = new QTimeEdit(DeleteEventWindow);
        inptimestart->setObjectName(QString::fromUtf8("inptimestart"));
        inptimestart->setGeometry(QRect(670, 110, 211, 51));
        inptimestart->setFont(font);
        hellotxt = new QLabel(DeleteEventWindow);
        hellotxt->setObjectName(QString::fromUtf8("hellotxt"));
        hellotxt->setGeometry(QRect(0, 10, 991, 61));
        hellotxt->setPixmap(QPixmap(QString::fromUtf8(":/img/del_traininng text.jpg")));
        starthourtxt = new QLabel(DeleteEventWindow);
        starthourtxt->setObjectName(QString::fromUtf8("starthourtxt"));
        starthourtxt->setGeometry(QRect(50, 110, 611, 51));
        starthourtxt->setPixmap(QPixmap(QString::fromUtf8(":/img/start_hour.jpg")));

        retranslateUi(DeleteEventWindow);

        QMetaObject::connectSlotsByName(DeleteEventWindow);
    } // setupUi

    void retranslateUi(QDialog *DeleteEventWindow)
    {
        DeleteEventWindow->setWindowTitle(QCoreApplication::translate("DeleteEventWindow", "Dialog", nullptr));
        cancelbutton->setText(QString());
#if QT_CONFIG(shortcut)
        cancelbutton->setShortcut(QCoreApplication::translate("DeleteEventWindow", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        delbutton->setText(QString());
#if QT_CONFIG(shortcut)
        delbutton->setShortcut(QCoreApplication::translate("DeleteEventWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        typeTreningtxt->setText(QString());
        infotxt->setText(QString());
        hellotxt->setText(QString());
        starthourtxt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DeleteEventWindow: public Ui_DeleteEventWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEEVENTWINDOW_H
