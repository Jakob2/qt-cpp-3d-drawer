#ifndef DB_H
#define DB_H

#include <vector>
#include <QtSql/QSqlQuery>
#include <QObject>
using namespace std;

class Db
{
public:
    Db();

    void connectSQL();

    void selectThings(QString name, QString part);
    void selectNames();
    void selectParts(QString name);
    void selectConstruct(QString name);

    static vector<vector<float> > things;
    static vector<vector<vector<float>>> construct;
    static vector<int> names;
    static vector<int> parts;

public slots:
    void deletePart(QString name, QString part);
    void addPartSQL(QString name);
    void savePartSQL(QString name, QString part, vector<vector<QString>> things);
    void deletePartSQL(QString name, QString part);

private:
    void updateA(QString name, QString part, QString x, QString y, QString z);
    void updateB(QString name, QString part, QString x, QString y, QString z);
    void updateC(QString name, QString part, QString x, QString y, QString z);
    void updateD(QString name, QString part, QString x, QString y, QString z);

    void setConstruct(int size);
    void setThings();

};

#endif // DB_H
