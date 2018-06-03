#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <generateauto.h>

int main(int argc, char *argv[])
{
    /*
    std::cout<<"enter path"<<std::endl;
    std::string path = "";
    std::cin >> path;
    std::cout<<"Enter Motor"<<std::endl;
    std::string motor;
    std::cin >> motor;
    GenerateAuto generateAuto = GenerateAuto(path);
    generateAuto.add_to_drive_motors(motor);
    bool invert = true;
    generateAuto.adjust_motor_inversion(0,invert);
    bool test = generateAuto.outputCode();
*/
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
