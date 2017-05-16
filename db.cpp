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
    else qDebug()<<"select error: "<<query.lastError()<<" / "<<query.lastQuery();
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

void Db::deletePart(QString name, QString part){
    QSqlQuery query;
    if(query.exec("DELETE FROM poly WHERE name="+name+" AND part="+part+"")) cout<<"part deleted"<<endl;
    else qDebug()<<"delete error: "<<query.lastError()<<" / "<<query.lastQuery();
}

void Db::addPart(QString name){
    int maxPart;
    QVariant tmp;
    QString newPart;
    QSqlQuery query;
    if(query.exec("SELECT MAX(part) FROM poly WHERE name="+name+"")) cout<<"max part selected"<<endl;
    else qDebug()<<"max part error: "<<query.lastError()<<" / "<<query.lastQuery();
    while(query.next()){
        maxPart = query.value(0).toInt();
    }
    maxPart += 1;
    tmp = maxPart;
    newPart = tmp.toString();
    if(query.exec("INSERT INTO poly(name, part, ax,ay,az, bx,by,bz, cx,cy,cz, dx,dy,dz) VALUES ('"+name+"', '"+newPart+"', '0','0','0', '0','0','0', '0','0','0', '0','0','0')")) cout<<"new part inserted"<<endl;
    else qDebug()<<"insert part error: "<<query.lastError()<<" / "<<query.lastQuery();
}

void Db::updateA(QString name, QString part,QString x, QString y, QString z){
    QSqlQuery query;
    if(query.exec("UPDATE poly SET ax="+x+", ay="+y+", az="+z+" WHERE name="+name+" AND part="+part+"")) cout<<"updated A"<<endl;
    else qDebug()<<"update A error: "<<query.lastError()<<" / "<<query.lastQuery();

}

void Db::updateB(QString name, QString part,QString x, QString y, QString z){
    QSqlQuery query;
    if(query.exec("UPDATE poly SET bx="+x+", by="+y+", bz="+z+" WHERE name="+name+" AND part="+part+"")) cout<<"updated B"<<endl;
    else qDebug()<<"update B error: "<<query.lastError()<<" / "<<query.lastQuery();

}

void Db::updateC(QString name, QString part,QString x, QString y, QString z){
    QSqlQuery query;
    if(query.exec("UPDATE poly SET cx="+x+", cy="+y+", cz="+z+" WHERE name="+name+" AND part="+part+"")) cout<<"updated C"<<endl;
    else qDebug()<<"update C error: "<<query.lastError()<<" / "<<query.lastQuery();

}

void Db::updateD(QString name, QString part,QString x, QString y, QString z){
    QSqlQuery query;
    if(query.exec("UPDATE poly SET dx="+x+", dy="+y+", dz="+z+" WHERE name="+name+" AND part="+part+"")) cout<<"updated D"<<endl;
    else qDebug()<<"update D error: "<<query.lastError()<<" / "<<query.lastQuery();

}

void Db::savePartSQL(QString name, QString part, vector<vector<QString>> things){
    updateA(name, part, things[0][0], things[0][1], things[0][2]);
    updateB(name, part, things[1][0], things[1][1], things[1][2]);
    updateC(name, part, things[2][0], things[2][1], things[2][2]);
    updateD(name, part, things[3][0], things[3][1], things[3][2]);
}
