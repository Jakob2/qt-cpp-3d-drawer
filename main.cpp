#include "global.h"
#include "mainwindow.h"
#include <QApplication>
#include "guictrl.h"
#include "GL/freeglut.h"
#include "style.h"

int modPart;
int display;
int REAL;
int WIDTH = 391;
int HEIGHT = 361;
/*int LX = 1;
int LY = 1;
int LZ = 1;*/

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
    guiCtrl.textBrowser->append("Application start. Don't forget to save your changes.");

    Style style;
    style.colorize(guiCtrl);

    return a.exec();
}
