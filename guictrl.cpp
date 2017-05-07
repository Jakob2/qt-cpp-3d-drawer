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
}

void GuiCtrl::compass(){
    switch(dial_compass->value()){
    case 0:
        view.resizeGL(391, 361, north[0], north[1]);
        view.paintGL(1.0);
         break;
    case 1:
        view.resizeGL(391, 361, east[0], east[1]);
        view.paintGL(1.0);
        break;
    case 2:
        view.resizeGL(391, 361, south[0], south[1]);
        view.paintGL(1.0);
        break;
    case 3:
        view.resizeGL(391, 361, west[0], west[1]);
        view.paintGL(1.0);
        break;
    }
}

void GuiCtrl::zoom(){
    switch(dial_zoom->value()){
    case 0:
        view.paintGL(0.5);
        break;
    case 1:
        view.paintGL(1.0);
        break;
    case 2:
        view.paintGL(2.0);
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
    view.paintGL(1.0);
}
