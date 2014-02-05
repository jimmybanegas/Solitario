#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QtGui>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);

}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
  event->accept();
}

void MainWindow::dragLeaveEvent(QDragLeaveEvent *event)
{
   event->accept();
}

void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
}

void MainWindow::dropEvent(QDropEvent *event)
{
  event->accept();
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
 event->accept();
}

MainWindow::~MainWindow()
{
    delete ui;
}
