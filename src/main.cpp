#include "landing.h"
#include "settings.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    landing w;
    w.show();

    return a.exec();
}
