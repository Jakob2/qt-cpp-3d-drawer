#ifndef DB_H
#define DB_H

#include <vector>
#include <QtSql/QSqlQuery>
using namespace std;

class Db
{
public:
    Db();

    void connectSQL();
    void selectThings(QString name, QString part);
    void selectNames();
    void selectParts(QString name);
    //void upsertSQL(float a, float b, float c, float d, float name);

    static vector<vector<float> > things;
    static vector<int> names;
    static vector<int> parts;
};

#endif // DB_H
