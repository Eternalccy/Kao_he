#include "Kao_he.h"
#include <QtWidgets/QApplication>
using namespace std;
int main(int argc, char *argv[])
{
    cout << "start" << endl;
    QApplication a(argc, argv);
    Kao_he w;
    w.show();
    return a.exec();
}
