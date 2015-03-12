#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include "map.h"
namespace Ui {
class GameBoard;
}

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget *parent = 0);
    ~GameBoard();

private:
    Ui::GameBoard *ui;
    Map mapitem;
};

#endif // GAMEBOARD_H
