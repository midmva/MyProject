#include "widget.h"
#include "ui_widget.h"
#include <QDesktopWidget>
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QDesktopWidget desk;
    this->setGeometry(desk.screenGeometry(0));
    ui->verticalLayoutWidget->setGeometry(geometry());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addSpider(){
    spider = new Spider(this,ui->label_9->height()*3/5,ui->label_9->height()*3/5);
    spider->setGeometry(QRect(ui->label_9->pos().rx()+5,ui->label_9->pos().ry()+5,spider->size().width(),spider->size().height()));
    //spider->setGeometry(QRect(ui->label_9->pos(),spider->size()));
    spider->show();
    size = new Struct(this,spider->width(), this->height()-(spider->pos().ry()+spider->height()+75+10));
    size->setGeometry(spider->pos().rx(),spider->pos().ry()+spider->height()+5,size->width(),size->height());
    size->show();
}
