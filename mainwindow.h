#ifndef MAiNWiNDOW_H
#define MAiNWiNDOW_H

#include <QMainWindow>
#include "global.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAiNWiNDOW_H
