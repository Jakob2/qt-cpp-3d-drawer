#include "guictrl.h"
#include <iostream>
using namespace std;

int modPart;
extern int display;

GuiCtrl::GuiCtrl(){
    GlWidget view;
}

void GuiCtrl::connectGUI(){
    QObject::connect(dial_zoom, SIGNAL(valueChanged(int)), this, SLOT(zoom()));
    QObject::connect(horizontalSlider_x, SIGNAL(valueChanged(int)), this, SLOT(rotateX()));
    QObject::connect(horizontalSlider_y, SIGNAL(valueChanged(int)), this, SLOT(rotateY()));
    QObject::connect(horizontalSlider_z, SIGNAL(valueChanged(int)), this, SLOT(rotateZ()));
    QObject::connect(radioButton_hide, SIGNAL(toggled(bool)), this, SLOT(hide()));

    QObject::connect(comboBox_name, SIGNAL(currentIndexChanged(int)), this, SLOT(parts()));
    QObject::connect(comboBox_part, SIGNAL(currentIndexChanged(int)), this, SLOT(choosePart()));

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
    QObject::connect(pushButton_name, SIGNAL(pressed()), this, SLOT(newName()));
    QObject::connect(pushButton_delName, SIGNAL(pressed()), this, SLOT(delName()));
}

void GuiCtrl::zoom(){
    switch(dial_zoom->value()){
    case 0:
        view.resizeGL(391,361);
        view.paintGL(0.25, rotation, comboBox_part->currentText());
        break;
    case 1:
        view.resizeGL(391,361);
        view.paintGL(0.5, rotation, comboBox_part->currentText());
        break;
    case 2:
        view.resizeGL(391,361);
        view.paintGL(1.0, rotation, comboBox_part->currentText());
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
    comboBox_name->clear();
    for(int i=0; i<(int)Db::names.size(); i++){
        comboBox_name->addItem(QString::number(Db::names[i]));
    }
}

void GuiCtrl::hide(){
    display == 0 ? display = 1 : display = 0;
    view.paintGL(1.0, rotation, comboBox_part->currentText());
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
    initA(comboBox_part->currentText());
    initB(comboBox_part->currentText());
    initC(comboBox_part->currentText());
    initD(comboBox_part->currentText());
    view.paintGL(1.0, rotation, comboBox_part->currentText());
    textBrowser->append(selPart);
}

void GuiCtrl::initA(QString part){
    int n = part.toInt();
    QObject::disconnect(doubleSpinBox_ax, SIGNAL(valueChanged(double)), this, SLOT(alterA()));
    QObject::disconnect(doubleSpinBox_ay, SIGNAL(valueChanged(double)), this, SLOT(alterA()));
    QObject::disconnect(doubleSpinBox_az, SIGNAL(valueChanged(double)), this, SLOT(alterA()));
    doubleSpinBox_ax->setValue(Db::construct[n][0][0]);
    doubleSpinBox_ay->setValue(Db::construct[n][0][1]);
    doubleSpinBox_az->setValue(Db::construct[n][0][2]);
    QObject::connect(doubleSpinBox_ax, SIGNAL(valueChanged(double)), this, SLOT(alterA()));
    QObject::connect(doubleSpinBox_ay, SIGNAL(valueChanged(double)), this, SLOT(alterA()));
    QObject::connect(doubleSpinBox_az, SIGNAL(valueChanged(double)), this, SLOT(alterA()));
}

void GuiCtrl::initB(QString part){
    int n = part.toInt();
    QObject::disconnect(doubleSpinBox_bx, SIGNAL(valueChanged(double)), this, SLOT(alterB()));
    QObject::disconnect(doubleSpinBox_by, SIGNAL(valueChanged(double)), this, SLOT(alterB()));
    QObject::disconnect(doubleSpinBox_bz, SIGNAL(valueChanged(double)), this, SLOT(alterB()));
    doubleSpinBox_bx->setValue(Db::construct[n][1][0]);
    doubleSpinBox_by->setValue(Db::construct[n][1][1]);
    doubleSpinBox_bz->setValue(Db::construct[n][1][2]);
    QObject::connect(doubleSpinBox_bx, SIGNAL(valueChanged(double)), this, SLOT(alterB()));
    QObject::connect(doubleSpinBox_by, SIGNAL(valueChanged(double)), this, SLOT(alterB()));
    QObject::connect(doubleSpinBox_bz, SIGNAL(valueChanged(double)), this, SLOT(alterB()));
}

void GuiCtrl::initC(QString part){
    int n = part.toInt();
    QObject::disconnect(doubleSpinBox_cx, SIGNAL(valueChanged(double)), this, SLOT(alterC()));
    QObject::disconnect(doubleSpinBox_cy, SIGNAL(valueChanged(double)), this, SLOT(alterC()));
    QObject::disconnect(doubleSpinBox_cz, SIGNAL(valueChanged(double)), this, SLOT(alterC()));
    doubleSpinBox_cx->setValue(Db::construct[n][2][0]);
    doubleSpinBox_cy->setValue(Db::construct[n][2][1]);
    doubleSpinBox_cz->setValue(Db::construct[n][2][2]);
    QObject::connect(doubleSpinBox_cx, SIGNAL(valueChanged(double)), this, SLOT(alterC()));
    QObject::connect(doubleSpinBox_cy, SIGNAL(valueChanged(double)), this, SLOT(alterC()));
    QObject::connect(doubleSpinBox_cz, SIGNAL(valueChanged(double)), this, SLOT(alterC()));
}

void GuiCtrl::initD(QString part){
    int n = part.toInt();
    QObject::disconnect(doubleSpinBox_dx, SIGNAL(valueChanged(double)), this, SLOT(alterD()));
    QObject::disconnect(doubleSpinBox_dy, SIGNAL(valueChanged(double)), this, SLOT(alterD()));
    QObject::disconnect(doubleSpinBox_dz, SIGNAL(valueChanged(double)), this, SLOT(alterD()));
    doubleSpinBox_dx->setValue(Db::construct[n][3][0]);
    doubleSpinBox_dy->setValue(Db::construct[n][3][1]);
    doubleSpinBox_dz->setValue(Db::construct[n][3][2]);
    QObject::connect(doubleSpinBox_dx, SIGNAL(valueChanged(double)), this, SLOT(alterD()));
    QObject::connect(doubleSpinBox_dy, SIGNAL(valueChanged(double)), this, SLOT(alterD()));
    QObject::connect(doubleSpinBox_dz, SIGNAL(valueChanged(double)), this, SLOT(alterD()));
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
    textBrowser->append(addPart);
}

void GuiCtrl::savePart(){
    QString name = comboBox_name->currentText();
    QString part = comboBox_part->currentText();
    savePartSQL(name, part, convertConstruct(part.toInt()));
    textBrowser->append(savPart);
}

/*vector<vector<QString>> GuiCtrl::convertThings(){
    vector<vector<QString>> res;
    res.resize(4*3);
    for(int i=0; i<(int)Db::things.size(); i++){
        for(int j=0; j<(int)Db::things[0].size(); j++){
            res[i].push_back(QString::number(Db::things[i][j]));
        }
    }
    return res;
}*/

vector<vector<vector<QString>>> GuiCtrl::convertConstruct(int index){
    vector<vector<vector<QString>>> res;
    for(int i=0; i<1; i++){
        res.push_back(vector<vector<QString>>());
        for(int j=0; j<4; j++){
            res[i].push_back(vector<QString>());
        }
    }
    for(int i=0; i<1; i++){
        for(int j=0; j<(int)Db::construct[i].size(); j++){
            for(int k=0; k<(int)Db::construct[i][j].size(); k++){
                res[i][j].push_back(QString::number(Db::construct[index][j][k]));
            }
        }
    }
    return res;
}

void GuiCtrl::deletePart(){
    deletePartSQL(comboBox_name->currentText(), comboBox_part->currentText());
    resetPartsSQL(comboBox_name->currentText());
    selectParts(comboBox_name->currentText());
    addParts();
    textBrowser->append(delPart);
    textBrowser->append(resPart);
}

void GuiCtrl::newName(){
    QObject::disconnect(comboBox_name, SIGNAL(currentIndexChanged(int)), this, SLOT(parts()));
    QObject::disconnect(comboBox_part, SIGNAL(currentIndexChanged(int)), this, SLOT(choosePart()));
    addName();
    selectNames();
    addNames();
    QObject::connect(comboBox_name, SIGNAL(currentIndexChanged(int)), this, SLOT(parts()));
    QObject::connect(comboBox_part, SIGNAL(currentIndexChanged(int)), this, SLOT(choosePart()));
}

void GuiCtrl::delName(){
    QObject::disconnect(comboBox_name, SIGNAL(currentIndexChanged(int)), this, SLOT(parts()));
    QObject::disconnect(comboBox_part, SIGNAL(currentIndexChanged(int)), this, SLOT(choosePart()));
    removeName(comboBox_name->currentText());
    selectNames();
    addNames();
    QObject::connect(comboBox_name, SIGNAL(currentIndexChanged(int)), this, SLOT(parts()));
    QObject::connect(comboBox_part, SIGNAL(currentIndexChanged(int)), this, SLOT(choosePart()));
}
