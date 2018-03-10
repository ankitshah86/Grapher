#include <iostream>
#include <QApplication>
#include "inputparser.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    InputParser p;
    p.show();

    return app.exec();
}
