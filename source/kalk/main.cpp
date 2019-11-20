#include <QApplication>
#include <m-c/define/kalk.h>
#include <iostream>
#include <dati/define/frazione.h>

using namespace std;
int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    kalk kalK;
    kalK.startKalk();
    return app.exec();
}
