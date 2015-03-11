#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font = a.font();
    font.setPixelSize(20);
    a.setFont(font);
    Widget w;
    w.show();
    w.addSpider();

    return a.exec();
}
