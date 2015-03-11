#ifndef STRUCT_H
#define STRUCT_H

#include <QWidget>
#include <QHBoxLayout>
#include "QtSvgLabel"

namespace Ui {
class Struct;
}

class Struct : public QWidget
{
    Q_OBJECT

public:
    explicit Struct(QWidget *parent = 0);
    Struct(QWidget *parent,int w, int h);
    ~Struct();

private:
    Ui::Struct *ui;
    QtSvgLabel *direction;
};

#endif // STRUCT_H
