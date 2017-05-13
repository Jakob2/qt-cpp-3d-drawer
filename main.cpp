#include "mainwindow.h"
#include <QApplication>
#include "guictrl.h"
#include "GL/freeglut.h"

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication a(argc, argv);
    //MainWindow w;
    MainWindow *w = new MainWindow;
    GuiCtrl guiCtrl;
    guiCtrl.setupUi(w);
    w->show();
    guiCtrl.connectGUI();
    guiCtrl.compass();
    guiCtrl.zoom();
    guiCtrl.addNames();

    return a.exec();
}
