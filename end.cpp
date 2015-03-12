#include "end.h"
#include "ui_end.h"

End::End(QWidget *parent) :
    QWidget(parent)

{
    quit_label = new QLabel("Gameover");
    quit_ok = new QPushButton("OK");

    QVBoxLayout* quit_vlayout = new QVBoxLayout;
    quit_vlayout->addWidget(quit_label);
    quit_vlayout->addWidget(quit_ok);

    this->setLayout(quit_vlayout);
    //quit_widget->show();

    QObject::connect(quit_ok, SIGNAL(clicked()), this,SLOT(close()));
}
