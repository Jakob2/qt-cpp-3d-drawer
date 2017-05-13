#ifndef GUICTRL_H
#define GUICTRL_H

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
    void compass();
    void zoom();
    void parts();
    void choosePart();
    void rotateX();
    void rotateY();
    void rotateZ();

private:
    GlWidget view;
    vector<float> north = {-0.5, 0.5};
    vector<float> east = {-0.5, -0.5};
    vector<float> south = {0.5, -0.5};
    vector<float> west = {0.5, 0.5};

    vector<int> rotation = {0,0,0};

    void initA();
    void initB();
    void initC();
    void initD();

    float ax;
    float ay;
    float az;

    float bx;
    float by;
    float bz;

    float cx;
    float cy;
    float cz;

    float dx;
    float dy;
    float dz;
};

#endif // GUICTRL_H
