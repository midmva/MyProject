#include "spider.h"
#include "ui_spider.h"
#include <QDesktopWidget>

Spider::Spider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Spider)
{

}

Spider::Spider(QWidget *parent, int w, int h):
    QWidget(parent),
    ui(new Ui::Spider)
{
    for (int i = 0; i<8; i++){
        skin[i] = 1;
    }
    ui->setupUi(this);
    style_gray = new QString("QLabel{background:black}");
    style_white = new QString("QLabel{background:white}");
    setGeometry(0,0,w,h);
    ui->gridLayoutWidget->setGeometry(geometry());
    lock = new QtSvgToggleSwitch();
    addSwichToLabel(ui->label_lock,lock,"lock");
    QObject::connect(lock,SIGNAL(clicked()),SLOT(pressLock()));
    left_up = new QtSvgLabel();
    addSvgToLabel(ui->label_left_up,left_up,":/res/1/left_up.svg");
    left = new QtSvgLabel();
    addSvgToLabel(ui->label_left,left,":/res/1/left.svg");
    left_down = new QtSvgLabel();
    addSvgToLabel(ui->label_left_down,left_down,":/res/1/left_down.svg");
    down = new QtSvgLabel();
    addSvgToLabel(ui->label_down,down,":/res/1/down.svg");
    right_down = new QtSvgLabel();
    addSvgToLabel(ui->label_right_down,right_down,":/res/1/right_down.svg");
    right = new QtSvgLabel();
    addSvgToLabel(ui->label_right,right,":/res/1/right.svg");
    right_up = new QtSvgLabel();
    addSvgToLabel(ui->label_right_up,right_up,":/res/1/right_up.svg");
    up = new QtSvgLabel();
    addSvgToLabel(ui->label_up,up,":/res/1/up.svg");
}

Spider::~Spider()
{
    delete ui;
}

void Spider::mousePressEvent(QMouseEvent *event){
    if (ui->label_left->geometry().contains(event->pos()))pressLeft();
    else if (ui->label_left_up->geometry().contains(event->pos()))pressLeftUp();
    else if (ui->label_left_down->geometry().contains(event->pos()))pressLeftDown();
    else if (ui->label_right->geometry().contains(event->pos()))pressRight();
    else if (ui->label_right_up->geometry().contains(event->pos()))pressRightUp();
    else if (ui->label_right_down->geometry().contains(event->pos()))pressRightDown();
    else if (ui->label_down->geometry().contains(event->pos()))pressDown();
    else if (ui->label_up->geometry().contains(event->pos()))pressUp();
}


void Spider::addSwichToLabel(QLabel *label, QtSvgToggleSwitch *swich, QString nameSkin){
    QHBoxLayout *lay = new QHBoxLayout();
    lay->setContentsMargins(0,0,0,0);
    label->setLayout(lay);
    swich->setLockalSkin(":/res/",nameSkin);
    lay->addWidget(swich);
}

void Spider::addSvgToLabel(QLabel *label, QtSvgLabel *swich, QString path){
    QHBoxLayout *lay = new QHBoxLayout();
    lay->setContentsMargins(0,0,0,0);
    label->setLayout(lay);
    swich->setLockalSkin(path,"Spider");
    lay->addWidget(swich);
}

void Spider::pressLock(){

    if (lock->isChecked()){
        left->setLockalSkin(QString(":/res/%1/left.svg").arg(skin[0]+3),"1");
        left_up->setLockalSkin(QString(":/res/%1/left_up.svg").arg(skin[1]+3),"1");
        left_down->setLockalSkin(QString(":/res/%1/left_down.svg").arg(skin[2]+3),"1");
        right->setLockalSkin(QString(":/res/%1/right.svg").arg(skin[3]+3),"1");
        right_up->setLockalSkin(QString(":/res/%1/right_up.svg").arg(skin[4]+3),"1");
        right_down->setLockalSkin(QString(":/res/%1/right_down.svg").arg(skin[5]+3),"1");
        up->setLockalSkin(QString(":/res/%1/up.svg").arg(skin[6]+3),"1");
        down->setLockalSkin(QString(":/res/%1/down.svg").arg(skin[7]+3),"1");
    }
    else {
        left->setLockalSkin(QString(":/res/%1/left.svg").arg(skin[0]),"1");
        left_up->setLockalSkin(QString(":/res/%1/left_up.svg").arg(skin[1]),"1");
        left_down->setLockalSkin(QString(":/res/%1/left_down.svg").arg(skin[2]),"1");
        right->setLockalSkin(QString(":/res/%1/right.svg").arg(skin[3]),"1");
        right_up->setLockalSkin(QString(":/res/%1/right_up.svg").arg(skin[4]),"1");
        right_down->setLockalSkin(QString(":/res/%1/right_down.svg").arg(skin[5]),"1");
        up->setLockalSkin(QString(":/res/%1/up.svg").arg(skin[6]),"1");
        down->setLockalSkin(QString(":/res/%1/down.svg").arg(skin[7]),"1");
    }
}

void Spider::pressLeft(){
    if (lock->isChecked()){
        if (skin[0]++>2)skin[0] = 1;
        left->setLockalSkin(QString(":/res/%1/left.svg").arg(skin[0]+3),"1");
    }
    else{
        if (skin[0] < 3)
        skin[0] = skin[3] = skin[6] = skin[7] +=1;
        else skin[0] = skin[3] = skin[6] = skin[7] = 1;
        left->setLockalSkin(QString(":/res/%1/left.svg").arg(skin[0]),"1");
        right->setLockalSkin(QString(":/res/%1/right.svg").arg(skin[3]),"1");
        up->setLockalSkin(QString(":/res/%1/up.svg").arg(skin[6]),"1");
        down->setLockalSkin(QString(":/res/%1/down.svg").arg(skin[7]),"1");
    }
}

void Spider::pressLeftUp(){
    if (lock->isChecked()){
        if (skin[1]++>2)skin[1] = 1;
        left_up->setLockalSkin(QString(":/res/%1/left_up.svg").arg(skin[1]+3),"1");
    }
    else{
        if (skin[1] < 3){
            skin[1] = skin[2] = skin[4] = skin[5] +=1;
        }
        else {
            skin[1] = skin[2] = skin[4] = skin[5] = 1;
        }
        left_up->setLockalSkin(QString(":/res/%1/left_up.svg").arg(skin[1]),"1");
        left_down->setLockalSkin(QString(":/res/%1/left_down.svg").arg(skin[2]),"1");
        right_up->setLockalSkin(QString(":/res/%1/right_up.svg").arg(skin[4]),"1");
        right_down->setLockalSkin(QString(":/res/%1/right_down.svg").arg(skin[5]),"1");
    }
}

void Spider::pressLeftDown(){
    if (lock->isChecked()){
        if (skin[2]++>2)skin[2] = 1;
        left_down->setLockalSkin(QString(":/res/%1/left_down.svg").arg(skin[2]+3),"1");
    }
    else{
        if (skin[1] < 3)
        skin[1] = skin[2] = skin[4] = skin[5] +=1;
        else skin[1] = skin[2] = skin[4] = skin[5] = 1;
        left_up->setLockalSkin(QString(":/res/%1/left_up.svg").arg(skin[1]),"1");
        left_down->setLockalSkin(QString(":/res/%1/left_down.svg").arg(skin[2]),"1");
        right_up->setLockalSkin(QString(":/res/%1/right_up.svg").arg(skin[4]),"1");
        right_down->setLockalSkin(QString(":/res/%1/right_down.svg").arg(skin[5]),"1");
    }
}

void Spider::pressRight(){
    if (lock->isChecked()){
        if (skin[3]++>2)skin[3] = 1;
        right->setLockalSkin(QString(":/res/%1/right.svg").arg(skin[3]+3),"1");
    }
    else{
        if (skin[0] < 3)
        skin[0] = skin[3] = skin[6] = skin[7] +=1;
        else skin[0] = skin[3] = skin[6] = skin[7] = 1;
        left->setLockalSkin(QString(":/res/%1/left.svg").arg(skin[0]),"1");
        right->setLockalSkin(QString(":/res/%1/right.svg").arg(skin[3]),"1");
        up->setLockalSkin(QString(":/res/%1/up.svg").arg(skin[6]),"1");
        down->setLockalSkin(QString(":/res/%1/down.svg").arg(skin[7]),"1");
    }
}

void Spider::pressRightUp(){
    if (lock->isChecked()){
        if (skin[4]++>2)skin[4] = 1;
        right_up->setLockalSkin(QString(":/res/%1/right_up.svg").arg(skin[4]+3),"1");
    }
    else{
        if (skin[1] < 3)
        skin[1] = skin[2] = skin[4] = skin[5] +=1;
        else skin[1] = skin[2] = skin[4] = skin[5] = 1;
        left_up->setLockalSkin(QString(":/res/%1/left_up.svg").arg(skin[1]),"1");
        left_down->setLockalSkin(QString(":/res/%1/left_down.svg").arg(skin[2]),"1");
        right_up->setLockalSkin(QString(":/res/%1/right_up.svg").arg(skin[4]),"1");
        right_down->setLockalSkin(QString(":/res/%1/right_down.svg").arg(skin[5]),"1");
    }
}

void Spider::pressRightDown(){
    if (lock->isChecked()){
        if (skin[5]++>2)skin[5] = 1;
        right_down->setLockalSkin(QString(":/res/%1/right_down.svg").arg(skin[5]+3),"1");
    }
    else{
        if (skin[1] < 3)
        skin[1] = skin[2] = skin[4] = skin[5] +=1;
        else skin[1] = skin[2] = skin[4] = skin[5] = 1;
        left_up->setLockalSkin(QString(":/res/%1/left_up.svg").arg(skin[1]),"1");
        left_down->setLockalSkin(QString(":/res/%1/left_down.svg").arg(skin[2]),"1");
        right_up->setLockalSkin(QString(":/res/%1/right_up.svg").arg(skin[4]),"1");
        right_down->setLockalSkin(QString(":/res/%1/right_down.svg").arg(skin[5]),"1");
    }
}

void Spider::pressUp(){
    if (lock->isChecked()){
        if (skin[6]++>2)skin[6] = 1;
        up->setLockalSkin(QString(":/res/%1/up.svg").arg(skin[6]+3),"1");
    }
    else{
        if (skin[0] < 3)
        skin[0] = skin[3] = skin[6] = skin[7] +=1;
        else skin[0] = skin[3] = skin[6] = skin[7] = 1;
        left->setLockalSkin(QString(":/res/%1/left.svg").arg(skin[0]),"1");
        right->setLockalSkin(QString(":/res/%1/right.svg").arg(skin[3]),"1");
        up->setLockalSkin(QString(":/res/%1/up.svg").arg(skin[6]),"1");
        down->setLockalSkin(QString(":/res/%1/down.svg").arg(skin[7]),"1");
    }
}

void Spider::pressDown(){
    if (lock->isChecked()){
        if (skin[7]++>2)skin[7] = 1;
        down->setLockalSkin(QString(":/res/%1/down.svg").arg(skin[7]+3),"1");
    }
    else{
        if (skin[0] < 3)
        skin[0] = skin[3] = skin[6] = skin[7] +=1;
        else skin[0] = skin[3] = skin[6] = skin[7] = 1;
        left->setLockalSkin(QString(":/res/%1/left.svg").arg(skin[0]),"1");
        right->setLockalSkin(QString(":/res/%1/right.svg").arg(skin[3]),"1");
        up->setLockalSkin(QString(":/res/%1/up.svg").arg(skin[6]),"1");
        down->setLockalSkin(QString(":/res/%1/down.svg").arg(skin[7]),"1");
    }
}
