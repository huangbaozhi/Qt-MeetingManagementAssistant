#include "mainwindow.h"
#include "MrzMeetingAssistantWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    MrzMeetingAssistantWindow w;
    w.show();
    return a.exec();
}
