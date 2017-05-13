#include "guictrl.h"
#include <iostream>
using namespace std;

GuiCtrl::GuiCtrl(){
    GlWidget view;
}

void GuiCtrl::connectGUI(){
    QObject::connect(dial_compass, SIGNAL(valueChanged(int)), this, SLOT(compass()));
    QObject::connect(dial_zoom, SIGNAL(valueChanged(int)), this, SLOT(zoom()));
    QObject::connect(comboBox_name, SIGNAL(currentIndexChanged(int)), this, SLOT(parts()));
    QObject::connect(comboBox_part, SIGNAL(currentIndexChanged(int)), this, SLOT(choosePart()));
    QObject::connect(horizontalSlider_x, SIGNAL(valueChanged(int)), this, SLOT(rotateX()));
    QObject::connect(horizontalSlider_y, SIGNAL(valueChanged(int)), this, SLOT(rotateY()));
    QObject::connect(horizontalSlider_z, SIGNAL(valueChanged(int)), this, SLOT(rotateZ()));
}

void GuiCtrl::compass(){
    switch(dial_compass->value()){
    case 0:
        view.resizeGL(391, 361, north[0], north[1]);
        view.paintGL(1.0, rotation);
         break;
    case 1:
        view.resizeGL(391, 361, east[0], east[1]);
        view.paintGL(1.0, rotation);
        break;
    case 2:
        view.resizeGL(391, 361, south[0], south[1]);
        view.paintGL(1.0, rotation);
        break;
    case 3:
        view.resizeGL(391, 361, west[0], west[1]);
        view.paintGL(1.0, rotation);
        break;
    }
}

void GuiCtrl::zoom(){
    switch(dial_zoom->value()){
    case 0:
        view.paintGL(0.5, rotation);
        break;
    case 1:
        view.paintGL(1.0, rotation);
        break;
    case 2:
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
    this->selectParts(comboBox_name->currentText());
    this->addParts();
}

void GuiCtrl::addParts(){
    comboBox_part->clear();
    for(int i=0; i<(int)Db::parts.size(); i++){
        comboBox_part->addItem(QString::number(Db::parts[i]));
    }
}

void GuiCtrl::choosePart(){
    this->selectThings(comboBox_name->currentText(), comboBox_part->currentText());
    view.paintGL(1.0, rotation);
    initA();
    initB();
    initC();
    initD();
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
