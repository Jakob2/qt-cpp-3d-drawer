#include "style.h"

void Style::a(GuiCtrl &gui){
    gui.doubleSpinBox_ax->setStyleSheet("QDoubleSpinBox { background-color: tomato }");
    gui.doubleSpinBox_ay->setStyleSheet("QDoubleSpinBox { background-color: tomato }");
    gui.doubleSpinBox_az->setStyleSheet("QDoubleSpinBox { background-color: tomato }");
}

void Style::b(GuiCtrl &gui){
    gui.doubleSpinBox_bx->setStyleSheet("QDoubleSpinBox { background-color: lightgreen }");
    gui.doubleSpinBox_by->setStyleSheet("QDoubleSpinBox { background-color: lightgreen }");
    gui.doubleSpinBox_bz->setStyleSheet("QDoubleSpinBox { background-color: lightgreen }");
}

void Style::c(GuiCtrl &gui){
    gui.doubleSpinBox_cx->setStyleSheet("QDoubleSpinBox { background-color: lightblue }");
    gui.doubleSpinBox_cy->setStyleSheet("QDoubleSpinBox { background-color: lightblue }");
    gui.doubleSpinBox_cz->setStyleSheet("QDoubleSpinBox { background-color: lightblue }");
}

void Style::d(GuiCtrl &gui){
    gui.doubleSpinBox_dx->setStyleSheet("QDoubleSpinBox { background-color: gold }");
    gui.doubleSpinBox_dy->setStyleSheet("QDoubleSpinBox { background-color: gold }");
    gui.doubleSpinBox_dz->setStyleSheet("QDoubleSpinBox { background-color: gold }");
}

void Style::x(GuiCtrl &gui){
    gui.label_x->setStyleSheet("QLabel { color: red }");
}

void Style::y(GuiCtrl &gui){
    gui.label_y->setStyleSheet("QLabel { color: green }");
}

void Style::z(GuiCtrl &gui){
    gui.label_z->setStyleSheet("QLabel { color: blue }");
}

void Style::nX(GuiCtrl &gui){
    gui.doubleSpinBox_normalX->setStyleSheet("QDoubleSpinBox { background-color: red }");
}

void Style::nY(GuiCtrl &gui){
    gui.doubleSpinBox_normalY->setStyleSheet("QDoubleSpinBox { background-color: green }");
}

void Style::nZ(GuiCtrl &gui){
    gui.doubleSpinBox_normalZ->setStyleSheet("QDoubleSpinBox { background-color: blue }");
}

void Style::colorize(GuiCtrl &gui){
    a(gui);
    b(gui);
    c(gui);
    d(gui);
    x(gui);
    y(gui);
    z(gui);
    nX(gui);
    nY(gui);
    nZ(gui);
}
