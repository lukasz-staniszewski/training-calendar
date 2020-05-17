#include "mainwindow.h"
#include <QIcon>
#include <QString>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QGuiApplication::setWindowIcon(QIcon("C:/Users/01149762/Documents/C++/QT/Calendar/icon.jpg"));
    QGuiApplication::setApplicationDisplayName(QString("Family Calendar"));
    w.show();
    return a.exec();
}
