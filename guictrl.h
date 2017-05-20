#ifndef GUiCTRL_H
#define GUiCTRL_H

#include "log.h"
#include <QDialog>
#include "ui_mainwindow.h"
#include "db.h"
#include <QObject>

class GuiCtrl : public QDialog, public Ui::MainWindow, public Db
{
    Q_OBJECT
public:
    GuiCtrl();
    void connectGUI();
    void addNames();
    void addParts();

public slots:
    void zoom();
    void rotateX();
    void rotateY();
    void rotateZ();
    void hide();

    void parts();
    void choosePart();

    void alterA();
    void alterB();
    void alterC();
    void alterD();

    void newPart();
    void savePart();
    void deletePart();
    void newName();

private:
    GlWidget view;
    /*vector<float> north = {-0.5, 0.5};
    vector<float> east = {-0.5, -0.5};
    vector<float> south = {0.5, -0.5};
    vector<float> west = {0.5, 0.5};*/

    vector<int> rotation = {0,0,0};

    void initA(QString part);
    void initB(QString part);
    void initC(QString part);
    void initD(QString part);

    //vector<vector<QString>> convertThings();
    vector<vector<vector<QString>>> convertConstruct(int index);
};

#endif // GUiCTRL_H
