#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("C:/Users/Auditor3/Documents/Estructura de datos/Solitario/SolitarioSolitaireMCE.png"));
    MainWindow w;
    w.setWindowIcon(QIcon("C:/Users/Auditor3/Documents/Estructura de datos/Solitario/SolitarioSolitaireMCE.png"));
    w.show();

    return a.exec();
}
