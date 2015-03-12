#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Map)
{
    endofgame=new End;
    ui->setupUi(this);
    ghost_x=400;
    ghost_y=400;
    money=100;
    cleanness=100;
    happiness=100;
    fullness=100;
    vigor=100;
    health=100;

    win=false;
    //change the address of the picture here. changing differnt ghost and different map has not been implemented.
    ghost_string=QString("/Users/elyongong/Documents/Elyon Qt/hw8/gamedesign/minighost.gif");
    ghostgoleft=QString("/Users/elyongong/Documents/Elyon Qt/hw8/gamedesign/minighost2.gif");
    ghost_string_upgraded=QString("/Users/elyongong/Documents/Elyon Qt/hw8/gamedesign/upgraded.gif");
    ghost_string_upgraded_goleft2=QString( "/Users/elyongong/Documents/Elyon Qt/hw8/gamedesign/upgraded2.gif");
    town_string=QString("/Users/elyongong/Documents/Elyon Qt/hw8/gamedesign/Celedon.jpg");

    gameover=false;

    ghostpicture= new QPixmap(ghost_string);
    ghostpictureleft=new QPixmap(ghostgoleft);
    winpicture=new QPixmap(ghost_string_upgraded);
    winpictureleft=new QPixmap(ghost_string_upgraded_goleft2);
    townimage=new QPixmap(town_string);

    ui->clean->setRange(0,100);
    ui->clean->setValue(cleanness);
    ui->happy->setRange(0,100);
    ui->happy->setValue(happiness);
    ui->healthy->setRange(0,100);
    ui->healthy->setValue(health);
    ui->energy->setRange(0,100);
    ui->energy->setValue(vigor);
    ui->full->setRange(0,100);
    ui->full->setValue(fullness);
    ui->total_money->display(money);

    going_left=false;

    info="Press Enter in front of the buildings to do different things. Earn $1000 to beat this game!";
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_stats()));
    timer->start(3000);
    QTimer *timer2=new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(update_info()));
    timer2->start(10);
}
void Map::check_status(){
    if(health==0||happiness==0||fullness==0||vigor==0||cleanness==0){
        endofgame->show();
        this->close();
   }
    if(money>1000)
        win=true;
}
bool Map::goto_work(){
    //info="Your Ghost is working.";
    if ((ghost_x==170&&ghost_y==290)||(ghost_x==125&&ghost_y==290)){
        info="Your Ghost is working.";
        return true;
    }
    else
    return false;
}
bool Map::goto_eat(){
    if ((ghost_x==390&&ghost_y==390)||(ghost_x==450&&ghost_y==370)||(ghost_x==385&&ghost_y==390)){
        info="Your Ghost is eating.";
        return true;
    }
    else
    return false;
}
bool Map::go_play(){
    if((ghost_x==345&&ghost_y==250)||(ghost_x==345&&ghost_y==245)){
        info="Your Ghost is playing.";
        return true;
    }
    else
        return false;
}
bool Map::goto_hospital(){
   // info="Your Ghost is being taken care of.";
    if ((ghost_x==120&&ghost_y==510)||(ghost_x==125&&ghost_y==510)){
        //hosptialbuilding=true;
        info="Your Ghost is being taken care of.";
        return true;
    }
    else
    return false;
}

bool Map::go_home(){
    //info="Your Ghost is at home taking a shower.";
    if ((ghost_x==555&&ghost_y==245)||(ghost_x==555&&ghost_y==250)){
        //homebuilding=true;
        info="Your Ghost is at home taking a shower.";
        return true;
    }
    else
    return false;
}
void Map::update_money(int a){
    if(money>-a){
        money+=a;
    }
    else{
        info="The ghost does not have enough money.";
    }
}
void Map::update_info(){
    ui->total_money->display(money);
    ui->information->setText(info);
}
void Map::update_stats(){
   update_all(-1);
   info="Press Enter in front of the buildings to do different things. Earn $1000 to beat this game!";
}
void Map::update_all(int a){
    update_happniess(a);
    update_cleanness(a);
    update_energy(a);
    update_fullness(a);
    check_status();
}

void Map::update_happniess(int a){
    if (happiness+a<100&&happiness+a>=0)
        happiness+=a;
    else if(happiness+a>100)
        happiness=100;

    ui->happy->setValue(happiness);
}
void Map::update_cleanness(int a){
    if(cleanness+a<100&&cleanness+a>=0)
        cleanness+=a;
    else if(cleanness+a>100)
        cleanness=100;
    ui->clean->setValue(cleanness);
    if (cleanness<50){
        update_health(-2);
    }
}
void Map::update_health(int a){
    if(health+a<100&&health+a>=0)
        health+=a;
    else if(health+a>100)
        health=100;
    ui->healthy->setValue(health);
}
void Map::update_energy(int a){
    if(vigor+a<100&&vigor+a>=0)
        vigor+=a;
    else if(vigor+a>100)
        vigor=100;
    ui->energy->setValue(vigor);
    if (vigor<50){
        update_health(-2);
    }
}
void Map::update_fullness(int a){
    if(fullness+a<100&&fullness+a>=0)
        fullness+=a;
    else if(fullness+a>100)
        fullness=100;
    ui->full->setValue(fullness);
    if (fullness<50){
        update_health(-2);
    }
}

void Map::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    double width = 700.0;
    double height = 550.0;
    QRect rectangle(ghost_x, ghost_y, 23, 20);
    QRect rectangle2(0,100, width, height);

    painter.drawPixmap(rectangle2,*townimage);
    if(!win){
        if(going_left){
            painter.drawPixmap(rectangle,*ghostpictureleft);
        }
        else{
            painter.drawPixmap(rectangle,*ghostpicture);}
    }
    else{
        if(going_left){
            painter.drawPixmap(rectangle,*winpictureleft);
        }
        else{
            painter.drawPixmap(rectangle,*winpicture);}
    }
}
bool Map:: valid_move(int x, int y){
    return !(intree1(x,y)||outsidemap1(x,y)||isbuilding(x,y));

}
bool Map:: outsidemap1(int x,int y){
    if(x<35||y<110||x>635||y>590)
        return true;
    else
        return false;
}
bool Map:: isbuilding(int x,int y){
    if (y>440&&y<500&&x>35&&x<275)
        return true;
    if(y<575&&x<275&&x>225&&y>440)
        return true;
    if(y>435&&x>355&&y<495&&x<595)
        return true;
    if(y>400&&x>505&&y<420&&x<625)
        return true;
    if(x>505&&y>320&&x<590&&y<400)
        return true;
    if(x>300&&y>140&&x<590&&y<250)
        return true;
    if(x>355&&y>315&&x<430&&y<385)
        return true;
    if(x>425&&y>315&&x<470&&y<375)
        return true;
    if(x>40&&y>145&&x<90&&y<255)
        return true;
    if(x>100&&y>145&&x<205&&y<290)
        return true;
    if(x>205&&y>145&&x<280&&y<255)
        return true;
    return false;
}

bool Map:: intree1(int x,int y){
    if(x>270&&x<450&&y>535&&y<575){
        return true;
    }
    if(x>470&&x<590&&y>535&&y<575){
        return true;
    }
    if(x>590&&y>415&&x<620&&y<495)
        return true;
    if(x>590&&y>415&&x<620&&y<495)
        return true;
     if(x>590&&y>290&&x<625&&y<385)
         return true;
     if(x>590&&y>290&&x<640&&y<365)
         return true;

    return false;
}
void Map::keyPressEvent(QKeyEvent *event){

    double target_x=ghost_x;
    double target_y=ghost_y;
    double a=5;
    switch (event->key()) {
    case Qt::Key_Left:
        if(valid_move(target_x-a,target_y)&&!gameover){
        update_ghost(target_x-a,target_y);
        going_left=true;
        break;}
    case Qt::Key_Right:
        if (valid_move(target_x+a,target_y)&&!gameover){
        update_ghost(target_x+a,target_y);
        going_left=false;
        break;}
    case Qt::Key_Up:
       if (valid_move(target_x,target_y-a)&&!gameover){
       update_ghost(target_x,target_y-a);
        break;}
    case Qt::Key_Down:
        if(valid_move(target_x,target_y+a)&&!gameover){
        update_ghost(target_x,target_y+a);
        break;}
    case Qt::Key_Space:
        if(valid_move(target_x,target_y)&&!gameover){
            if(goto_work()){
                update_money(20);
                update_energy(-5);
                update_fullness(-5);
                update_cleanness(-5);
                update_happniess(-5);
            }
            else if(goto_eat()){
                update_fullness(20);
                update_money(-5);
            }
            else if(goto_hospital()){
                update_money(-10);
                update_happniess(-10);
                update_health(20);

            }
            else if(go_home()){
                update_cleanness(10);
                update_money(-2);
            }
            else if(go_play()){
                update_happniess(10);
                update_money(-5);
            }
        break;}

        QWidget::keyPressEvent(event);
    }
    repaint();
    QCoreApplication::processEvents();
    return;
}
/*
void Map::closeEvent(QCloseEvent *e) {

    e->ignore();
    quit->show();
    QObject::connect(quit->quit_ok, SIGNAL(clicked()),this, SLOT(close()));
}*/
Map::~Map()
{
    delete ui;
}
