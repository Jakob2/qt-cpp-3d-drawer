#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <iostream>
#include "db.h"
#include <vector>
using namespace std;

vector<vector<float> > Db::things;
vector<int> Db::names;
vector<int> Db::parts;

Db::Db(){
    this->connectSQL();
    this->selectNames();
    Db::things.resize(4*3);
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            Db::things[i].push_back(0);
        }
    }
}

void Db::connectSQL(){
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("/home/ok/jakob/QT4/DATABASES/3dg");
    if(!m_db.open()) cout<< "Error: connection with database fail"<<endl;
    else cout<< "Database: connection ok"<<endl;
}

void Db::selectThings(QString name, QString part){
    Db::things.clear();
    QSqlQuery query;
    if(query.exec("SELECT ax,ay,az, bx,by,bz, cx,cy,cz, dx,dy,dz FROM poly WHERE name ='"+name+"' AND part ='"+part+"'")) cout<<"selected"<<endl;
    else qDebug()<<"insert error: "<<query.lastError()<<" / "<<query.lastQuery();
    while(query.next()){
        Db::things.resize(4*3);

        Db::things[0].push_back(query.value(0).toFloat());
        Db::things[0].push_back(query.value(1).toFloat());
        Db::things[0].push_back(query.value(2).toFloat());

        Db::things[1].push_back(query.value(3).toFloat());
        Db::things[1].push_back(query.value(4).toFloat());
        Db::things[1].push_back(query.value(5).toFloat());

        Db::things[2].push_back(query.value(6).toFloat());
        Db::things[2].push_back(query.value(7).toFloat());
        Db::things[2].push_back(query.value(8).toFloat());

        Db::things[3].push_back(query.value(9).toFloat());
        Db::things[3].push_back(query.value(10).toFloat());
        Db::things[3].push_back(query.value(11).toFloat());
    }
    /*for(int i=0; i<(int)Db::things.size(); i++){
        for(int j=0; j<(int)Db::things[i].size(); j++){
            cout<<Db::things[i][j]<<endl;
        }
    }*/
}

void Db::selectNames(){
    Db::names.clear();
    QSqlQuery query;
    if(query.exec("SELECT DISTINCT name FROM poly")) cout<<"names selected"<<endl;
    else qDebug()<<"insert error: "<<query.lastError()<<" / "<<query.lastQuery();
    while(query.next()){
        Db::names.push_back(query.value(0).toInt());
    }
}

void Db::selectParts(QString name){
    Db::parts.clear();
    QSqlQuery query;
    if(query.exec("SELECT part FROM poly WHERE name ='"+name+"'")) cout<<"parts selected"<<endl;
    else qDebug()<<"insert error: "<<query.lastError()<<" / "<<query.lastQuery();
    while(query.next()){
        Db::parts.push_back(query.value(0).toInt());
    }
}

/*void Db::upsertSQL(float a, float b, float c, float d, float name){
    bool find = false;
    QSqlQuery query;
    if(query.exec("SELECT "+name+" FROM poly")) cout<<"upsert selected"<<endl;
    while(query.next()){
        find = true;
    }
    if(find) query.exec("UPDATE poly SET a ="+a+" AND b="+b+" AND c="+c+" AND d="+d+" WHERE name = "+name);
    else query.exec("INSERT INTO poly (a,b,c,d,name) VALUES ("+a+","+b+","+c+","+d+","+name+")");
}*/


