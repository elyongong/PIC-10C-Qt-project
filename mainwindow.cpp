#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->startbuttom, SIGNAL(clicked()), this, SLOT(construct_map()));
    QObject::connect(ui->startbuttom, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->endbuttom, SIGNAL(clicked()), this, SLOT(close()));
}
 void MainWindow:: construct_map(){
      gameboard=new Map;
      gameboard->show();
  }
MainWindow::~MainWindow()
{
    delete ui;
}

