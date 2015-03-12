#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "map.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void construct_map();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Map* gameboard;
};

#endif // MAINWINDOW_H
