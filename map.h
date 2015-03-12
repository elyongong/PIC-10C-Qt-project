#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QKeyEvent>
#include <QLabel>
#include <QPainter>
#include <QTimer>
#include <iostream>
#include "end.h"
namespace Ui {
class Map;
}

class Map : public QWidget
{
    Q_OBJECT
public slots:
    void update_stats();
    void update_info();
public:
    explicit Map(QWidget *parent = 0);
    ~Map();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void update_all(int a);
    void update_ghost(double a, double b){ghost_x=a;ghost_y=b;}
    void update_happniess(int a);
    void update_cleanness(int a);
    void update_health(int a);
    void update_energy(int a);
    void update_fullness(int a);
    bool valid_move(int x, int y);
    bool outsidemap1(int x,int y);
    bool intree1(int x, int y);
    bool isbuilding(int x, int y);
    bool goto_work();
    bool goto_eat();
    bool go_home();
    bool go_play();
    bool goto_hospital();
    void update_money(int a);
    void check_status();
private:
    QPixmap *ghostpicture;
    QPixmap *townimage;
    QPixmap *ghostpictureleft;
    QPixmap *winpicture;
    QPixmap *winpictureleft;
    Ui::Map *ui;
    QString info;
    double ghost_x;
    double ghost_y;
    int money;
    int cleanness;
    int fullness;
    int vigor;
    int happiness;
    int health;
    bool going_left;
    End* endofgame;
    bool gameover;
    bool win;
    QString ghost_string;
    QString ghostgoleft;
    QString ghost_string_upgraded;
    QString ghost_string_upgraded_goleft2;
    QString town_string;
};

#endif // MAP_H
