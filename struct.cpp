#include "struct.h"
#include "ui_struct.h"

Struct::Struct(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Struct)
{
    ui->setupUi(this);
}

Struct::Struct(QWidget *parent, int w, int h):
    QWidget(parent),
    ui(new Ui::Struct)
{
    ui->setupUi(this);
    ui->width->setContentsMargins(0,0,0,0);
    ui->height->setContentsMargins(0,0,0,0);
    setGeometry(0,0,w,h);
    ui->gridLayoutWidget->setGeometry(geometry());
    direction = new QtSvgLabel();
    direction->setLockalSkin(":/res/struct/no_struct.svg","1");
    direction->setFixedSize(w/5,w/5);
    QHBoxLayout *l = new QHBoxLayout();
    l->setContentsMargins(0,0,0,0);
    ui->direction->setLayout(l);
    ui->direction->setContentsMargins(0,0,0,0);
    l->addWidget(direction);
}

Struct::~Struct()
{
    delete ui;
}
