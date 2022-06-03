#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //arg<<"/root/Desktop/QT/2jun22_2/mainwindow.h";
    process.start("/root/Desktop/QT/2jun22_2/2jun22_1", QStringList()<<"/root/Desktop/QT/2jun22_2/mainwindow.h");
    connect(&process, SIGNAL(readyReadStandardOutput()), this, SLOT(slot_app()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_app()
{
     //qDebug()<<process.readAllStandardOutput();
     ui->textEdit->setText(process.readAllStandardOutput());
}



