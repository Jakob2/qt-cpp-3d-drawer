#include "style.h"

void Style::a(GuiCtrl &gui){
    gui.doubleSpinBox_ax->setStyleSheet("QDoubleSpinBox { background-color: red }");
    gui.doubleSpinBox_ay->setStyleSheet("QDoubleSpinBox { background-color: red }");
    gui.doubleSpinBox_az->setStyleSheet("QDoubleSpinBox { background-color: red }");
}

void Style::b(GuiCtrl &gui){
    gui.doubleSpinBox_bx->setStyleSheet("QDoubleSpinBox { background-color: green }");
    gui.doubleSpinBox_by->setStyleSheet("QDoubleSpinBox { background-color: green }");
    gui.doubleSpinBox_bz->setStyleSheet("QDoubleSpinBox { background-color: green }");
}

void Style::c(GuiCtrl &gui){
    gui.doubleSpinBox_cx->setStyleSheet("QDoubleSpinBox { background-color: blue }");
    gui.doubleSpinBox_cy->setStyleSheet("QDoubleSpinBox { background-color: blue }");
    gui.doubleSpinBox_cz->setStyleSheet("QDoubleSpinBox { background-color: blue }");
}

void Style::d(GuiCtrl &gui){
    gui.doubleSpinBox_dx->setStyleSheet("QDoubleSpinBox { background-color: yellow }");
    gui.doubleSpinBox_dy->setStyleSheet("QDoubleSpinBox { background-color: yellow }");
    gui.doubleSpinBox_dz->setStyleSheet("QDoubleSpinBox { background-color: yellow }");
}
