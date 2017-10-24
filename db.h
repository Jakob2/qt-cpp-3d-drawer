<<<<<<< HEAD
=======

>>>>>>> 4e5c2f3978a3d2d038cf18b8394c137600d51d01
#ifndef DB_H
#define DB_H

#include "log.h"
#include <vector>
#include <QtSql/QSqlQuery>
#include <QObject>
using namespace std;

class Db : protected Log
{
public:
    Db();

    void connectSQL();

    void selectNames();
    void selectParts(QString name);
    void selectConstruct(QString name);

    static vector<vector<float> > things;
    static vector<vector<vector<float>>> construct;
    static vector<int> names;
    static vector<int> parts;

    void addPartSQL(QString name);
    void savePartSQL(QString name, QString part, vector<vector<vector<QString>>> construct);
    void deletePartSQL(QString name, QString part);
    void resetPartsSQL(QString name);
    void addName();
    void removeName(QString name);
    void saveColor(QString name, QString part, QString r, QString g, QString b);

    void updateNormal(QString name, QString part, QString nX, QString nY, QString nZ);
    void selectNormal(QString name);
    static vector<vector<float>> normal;

private:
    QString db = "3dg";
    QString table = "poly";
    void updateA(QString name, QString part, QString x, QString y, QString z);
    void updateB(QString name, QString part, QString x, QString y, QString z);
    void updateC(QString name, QString part, QString x, QString y, QString z);
    void updateD(QString name, QString part, QString x, QString y, QString z);

    void setConstruct(int size);
    //void setThings();
    void setNormal(int size);

};

#endif // DB_H
