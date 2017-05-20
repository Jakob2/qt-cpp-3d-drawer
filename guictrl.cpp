#include "guictrl.h"
#include <iostream>
using namespace std;

int modPart;

GuiCtrl::GuiCtrl(){
    GlWidget view;
}

void GuiCtrl::connectGUI(){
    QObject::connect(dial_zoom, SIGNAL(valueChanged(int)), this, SLOT(zoom()));

    QObject::connect(comboBox_name, SIGNAL(currentIndexChanged(int)), this, SLOT(parts()));
    QObject::connect(comboBox_part, SIGNAL(currentIndexChanged(int)), this, SLOT(choosePart()));

    QObject::connect(horizontalSlider_x, SIGNAL(valueChanged(int)), this, SLOT(rotateX()));
    QObject::connect(horizontalSlider_y, SIGNAL(valueChanged(int)), this, SLOT(rotateY()));
    QObject::connect(horizontalSlider_z, SIGNAL(valueChanged(int)), this, SLOT(rotateZ()));

    QObject::connect(doubleSpinBox_ax, SIGNAL(valueChanged(double)), this, SLOT(alterA()));
    QObject::connect(doubleSpinBox_ay, SIGNAL(valueChanged(double)), this, SLOT(alterA()));
    QObject::connect(doubleSpinBox_az, SIGNAL(valueChanged(double)), this, SLOT(alterA()));

    QObject::connect(doubleSpinBox_bx, SIGNAL(valueChanged(double)), this, SLOT(alterB()));
    QObject::connect(doubleSpinBox_by, SIGNAL(valueChanged(double)), this, SLOT(alterB()));
    QObject::connect(doubleSpinBox_bz, SIGNAL(valueChanged(double)), this, SLOT(alterB()));

    QObject::connect(doubleSpinBox_cx, SIGNAL(valueChanged(double)), this, SLOT(alterC()));
    QObject::connect(doubleSpinBox_cy, SIGNAL(valueChanged(double)), this, SLOT(alterC()));
    QObject::connect(doubleSpinBox_cz, SIGNAL(valueChanged(double)), this, SLOT(alterC()));

    QObject::connect(doubleSpinBox_dx, SIGNAL(valueChanged(double)), this, SLOT(alterD()));
    QObject::connect(doubleSpinBox_dy, SIGNAL(valueChanged(double)), this, SLOT(alterD()));
    QObject::connect(doubleSpinBox_dz, SIGNAL(valueChanged(double)), this, SLOT(alterD()));

    QObject::connect(pushButton_new, SIGNAL(pressed()), this, SLOT(newPart()));
    QObject::connect(pushButton_save, SIGNAL(pressed()), this, SLOT(savePart()));
    QObject::connect(pushButton_del, SIGNAL(pressed()), this, SLOT(deletePart()));
}

void GuiCtrl::zoom(){
    switch(dial_zoom->value()){
    case 0:
        view.resizeGL(391,361);
        view.paintGL(0.5, rotation, comboBox_part->currentText());
        break;
    case 1:
        view.resizeGL(391,361);
        view.paintGL(1.0, rotation, comboBox_part->currentText());
        break;
    case 2:
        view.resizeGL(391,361);
        view.paintGL(2.0, rotation, comboBox_part->currentText());
        break;
    }
}

void GuiCtrl::rotateX(){
    rotation[0] = horizontalSlider_x->value();
    view.paintGL(1.0, rotation, comboBox_part->currentText());
}

void GuiCtrl::rotateY(){
    rotation[1] = horizontalSlider_y->value();
    view.paintGL(1.0, rotation, comboBox_part->currentText());
}

void GuiCtrl::rotateZ(){
    rotation[2] = horizontalSlider_z->value();
    view.paintGL(1.0, rotation, comboBox_part->currentText());
}

void GuiCtrl::addNames(){
    for(int i=0; i<(int)Db::names.size(); i++){
        comboBox_name->addItem(QString::number(Db::names[i]));
    }
}

void GuiCtrl::parts(){
    selectParts(comboBox_name->currentText());
    addParts();
}

void GuiCtrl::addParts(){
    comboBox_part->clear();
    for(int i=0; i<(int)Db::parts.size(); i++){
        comboBox_part->addItem(QString::number(Db::parts[i]));
    }
}

void GuiCtrl::choosePart(){
    modPart = comboBox_part->currentText().toInt();
    selectConstruct(comboBox_name->currentText());
    initA(comboBox_name->currentText());
    initB(comboBox_name->currentText());
    initC(comboBox_name->currentText());
    initD(comboBox_name->currentText());
    if(comboBox_part->count()) selectThings(comboBox_name->currentText(), comboBox_part->currentText());
    view.paintGL(1.0, rotation, comboBox_part->currentText());
}

void GuiCtrl::initA(QString name){
    int n = name.toInt();
    doubleSpinBox_ax->setValue(Db::construct[n][0][0]);
    doubleSpinBox_ay->setValue(Db::construct[n][0][1]);
    doubleSpinBox_az->setValue(Db::construct[n][0][2]);
}

void GuiCtrl::initB(QString name){
    int n = name.toInt();
    doubleSpinBox_bx->setValue(Db::construct[n][1][0]);
    doubleSpinBox_by->setValue(Db::construct[n][1][1]);
    doubleSpinBox_bz->setValue(Db::construct[n][1][2]);
}

void GuiCtrl::initC(QString name){
    int n = name.toInt();
    doubleSpinBox_cx->setValue(Db::construct[n][2][0]);
    doubleSpinBox_cy->setValue(Db::construct[n][2][1]);
    doubleSpinBox_cz->setValue(Db::construct[n][2][2]);
}

void GuiCtrl::initD(QString name){
    int n = name.toInt();
    doubleSpinBox_dx->setValue(Db::construct[n][3][0]);
    doubleSpinBox_dy->setValue(Db::construct[n][3][1]);
    doubleSpinBox_dz->setValue(Db::construct[n][3][2]);
}

void GuiCtrl::alterA(){
    Db::construct[modPart][0][0] = doubleSpinBox_ax->value();
    Db::construct[modPart][0][1] = doubleSpinBox_ay->value();
    Db::construct[modPart][0][2] = doubleSpinBox_az->value();
    view.paintGL(1.0, rotation, comboBox_part->currentText());
}

void GuiCtrl::alterB(){
    Db::construct[modPart][1][0] = doubleSpinBox_bx->value();
    Db::construct[modPart][1][1] = doubleSpinBox_by->value();
    Db::construct[modPart][1][2] = doubleSpinBox_bz->value();
    view.paintGL(1.0, rotation, comboBox_part->currentText());
}

void GuiCtrl::alterC(){
    Db::construct[modPart][2][0] = doubleSpinBox_cx->value();
    Db::construct[modPart][2][1] = doubleSpinBox_cy->value();
    Db::construct[modPart][2][2] = doubleSpinBox_cz->value();
    view.paintGL(1.0, rotation, comboBox_part->currentText());
}

void GuiCtrl::alterD(){
    Db::construct[modPart][3][0] = doubleSpinBox_dx->value();
    Db::construct[modPart][3][1] = doubleSpinBox_dy->value();
    Db::construct[modPart][3][2] = doubleSpinBox_dz->value();
    view.paintGL(1.0, rotation, comboBox_part->currentText());
}

void GuiCtrl::newPart(){
    addPartSQL(comboBox_name->currentText());
    selectParts(comboBox_name->currentText());
    addParts();
}

void GuiCtrl::savePart(){
    savePartSQL(comboBox_name->currentText(), comboBox_part->currentText(), convertThings());
}

vector<vector<QString>> GuiCtrl::convertThings(){
    vector<vector<QString>> res;
    res.resize(4*3);
    for(int i=0; i<(int)Db::things.size(); i++){
        for(int j=0; j<(int)Db::things[i].size(); j++){
            res[i].push_back(QString::number(Db::things[i][j]));
        }
    }
    return res;
}

void GuiCtrl::deletePart(){
    deletePartSQL(comboBox_name->currentText(), comboBox_part->currentText());
    selectParts(comboBox_name->currentText());
    addParts();
}
