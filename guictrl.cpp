#include "guictrl.h"
#include <iostream>
using namespace std;

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
        view.paintGL(0.5, rotation);
        break;
    case 1:
        view.resizeGL(391,361);
        view.paintGL(1.0, rotation);
        break;
    case 2:
        view.resizeGL(391,361);
        view.paintGL(2.0, rotation);
        break;
    }
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
    initA();
    initB();
    initC();
    initD();
    if(comboBox_part->count()) selectThings(comboBox_name->currentText(), comboBox_part->currentText());
    view.paintGL(1.0, rotation);
}

void GuiCtrl::initA(){
    doubleSpinBox_ax->setValue(Db::things[0][0]);
    doubleSpinBox_ay->setValue(Db::things[0][1]);
    doubleSpinBox_az->setValue(Db::things[0][2]);
}

void GuiCtrl::initB(){
    doubleSpinBox_bx->setValue(Db::things[1][0]);
    doubleSpinBox_by->setValue(Db::things[1][1]);
    doubleSpinBox_bz->setValue(Db::things[1][2]);
}

void GuiCtrl::initC(){
    doubleSpinBox_cx->setValue(Db::things[2][0]);
    doubleSpinBox_cy->setValue(Db::things[2][1]);
    doubleSpinBox_cz->setValue(Db::things[2][2]);
}

void GuiCtrl::initD(){
    doubleSpinBox_dx->setValue(Db::things[3][0]);
    doubleSpinBox_dy->setValue(Db::things[3][1]);
    doubleSpinBox_dz->setValue(Db::things[3][2]);
}

void GuiCtrl::rotateX(){
    rotation[0] = horizontalSlider_x->value();
    view.paintGL(1.0, rotation);
}

void GuiCtrl::rotateY(){
    rotation[1] = horizontalSlider_y->value();
    view.paintGL(1.0, rotation);
}

void GuiCtrl::rotateZ(){
    rotation[2] = horizontalSlider_z->value();
    view.paintGL(1.0, rotation);
}

void GuiCtrl::alterA(){
    Db::things[0][0] = doubleSpinBox_ax->value();
    Db::things[0][1] = doubleSpinBox_ay->value();
    Db::things[0][2] = doubleSpinBox_az->value();
    view.paintGL(1.0, rotation);
}

void GuiCtrl::alterB(){
    Db::things[1][0] = doubleSpinBox_bx->value();
    Db::things[1][1] = doubleSpinBox_by->value();
    Db::things[1][2] = doubleSpinBox_bz->value();
    view.paintGL(1.0, rotation);
}

void GuiCtrl::alterC(){
    Db::things[2][0] = doubleSpinBox_cx->value();
    Db::things[2][1] = doubleSpinBox_cy->value();
    Db::things[2][2] = doubleSpinBox_cz->value();
    view.paintGL(1.0, rotation);
}

void GuiCtrl::alterD(){
    Db::things[3][0] = doubleSpinBox_dx->value();
    Db::things[3][1] = doubleSpinBox_dy->value();
    Db::things[3][2] = doubleSpinBox_dz->value();
    view.paintGL(1.0, rotation);
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
