#ifndef SPIDER_H
#define SPIDER_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include "QtSvgLabel"
#include "svgtoggleswitch/qtsvgtoggleswitch.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace Ui {
class Spider;
}

class Spider : public QWidget
{
    Q_OBJECT

public:
    explicit Spider(QWidget *parent = 0);
    Spider(QWidget *parent,int w, int h);
    ~Spider();

private:
    Ui::Spider *ui;
    QtSvgToggleSwitch *lock;
    QtSvgLabel *left_up,*up,*right_up,*right,*right_down,*down,*left_down,*left;
    QString *style_gray;
    QString *style_white;
    int skin[8];
    void mousePressEvent(QMouseEvent *event);


private slots:
    void addSwichToLabel(QLabel *label,QtSvgToggleSwitch *swich, QString nameSkin);
    void addSvgToLabel(QLabel *label,QtSvgLabel *swich, QString path);
    void pressLeft();
    void pressLeftUp();
    void pressLeftDown();
    void pressRight();
    void pressRightUp();
    void pressRightDown();
    void pressUp();
    void pressDown();
    void pressLock();
};

#endif // SPIDER_H
