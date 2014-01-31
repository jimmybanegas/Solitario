#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/SolitaireMCE.png"));
    MainWindow w;
    w.setWindowIcon(QIcon(":/images/SolitaireMCE.png"));
    w.show();

    return a.exec();
}
