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

    static vector<vector<float> > things;
    static vector<int> names;
    static vector<int> parts;

public slots:
    void deletePart(QString name, QString part);
    void addPart(QString name);
    void savePart(QString name, QString part);

};

#endif // DB_H
