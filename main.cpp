#include "mainwindow.h"
#include <QApplication>
#include "guictrl.h"
#include "GL/freeglut.h"
#include "style.h"

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow;
    GuiCtrl guiCtrl;
    guiCtrl.setupUi(w);
    w->show();
    guiCtrl.connectGUI();
    guiCtrl.zoom();
    guiCtrl.addNames();

    Style style;
    style.colorize(guiCtrl);

    return a.exec();
}
