#ifndef END_H
#define END_H
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
namespace Ui {
class End;
}

class End : public QWidget
{
    Q_OBJECT

public:
    explicit End(QWidget *parent = 0);
    QPushButton* quit_ok;
private:

    QLabel* quit_label;
};

#endif // END_H
