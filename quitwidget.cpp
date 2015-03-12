#include "quitwidget.h"
#include "ui_quitwidget.h"
#include <QHBoxLayout>

QuitWidget::QuitWidget(QWidget *parent) :
    QWidget(parent)
{

    quit_label = new QLabel("Are you sure?");
    quit_cancel = new QPushButton("Cancel");
    quit_ok = new QPushButton("OK");

    QHBoxLayout* quit_hlayout = new QHBoxLayout;
    quit_hlayout->addWidget(quit_cancel);
    quit_hlayout->addWidget(quit_ok);

    QVBoxLayout* quit_vlayout = new QVBoxLayout;
    quit_vlayout->addWidget(quit_label);
    quit_vlayout->addLayout(quit_hlayout);

    this->setLayout(quit_vlayout);
    //quit_widget->show();

    QObject::connect(quit_cancel, SIGNAL(clicked()), this, SLOT(hide()));
    QObject::connect(quit_ok, SIGNAL(clicked()), this,SLOT(close()));

}


QuitWidget::~QuitWidget()
{ }
