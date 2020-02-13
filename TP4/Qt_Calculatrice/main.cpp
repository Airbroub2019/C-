#include "qt.hh"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    calcul f;
    f.show();
    return app.exec();
}
