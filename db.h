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

private:
    QString db = "3dg";
    QString table = "poly";
    void updateA(QString name, QString part, QString x, QString y, QString z);
    void updateB(QString name, QString part, QString x, QString y, QString z);
    void updateC(QString name, QString part, QString x, QString y, QString z);
    void updateD(QString name, QString part, QString x, QString y, QString z);

    void setConstruct(int size);
    //void setThings();

};

#endif // DB_H
