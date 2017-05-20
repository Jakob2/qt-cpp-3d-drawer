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

vector<vector<float>> Db::things;
vector<vector<vector<float>>> Db::construct;
vector<int> Db::names;
vector<int> Db::parts;

Db::Db(){
    connectSQL();
    selectNames();
    setThings();
    setConstruct(1);
}

void Db::connectSQL(){
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("/home/ok/jakob/QT4/DATABASES/3dg");
    if(!m_db.open()) cout<< "Error: connection with database fail"<<endl;
    else cout<< "Database: connection ok"<<endl;
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

void Db::setConstruct(int size){
    Db::construct.clear();
    for(int i=0; i<size; i++){
        Db::construct.push_back(vector<vector<float>>());
        for(int j=0; j<4; j++){
            Db::construct[i].push_back(vector<float>());
            for(int k=0; k<3; k++){
             Db::construct[i][j].push_back(0);
            }
        }
    }
}

void Db::setThings(){
    Db::things.clear();
    for(int i=0; i<4; i++){
        Db::things.push_back(vector<float>());
        for(int j=0; j<3; j++){
            Db::things[i].push_back(0);
        }
    }
}

void Db::selectConstruct(QString name){
    int range;
    Db::construct.clear();
    QSqlQuery query;
    if(query.exec("SELECT COUNT(*) FROM poly WHERE name="+name+"")) cout<<"construct range selected"<<endl;
    else qDebug()<<"construct range error: "<<query.lastError()<<" / "<<query.lastQuery();
    while(query.next()) range = query.value(0).toInt();
    setConstruct(range);
    int index = 0;
    if(query.exec("SELECT ax,ay,az, bx,by,bz, cx,cy,cz, dx,dy,dz FROM poly WHERE name="+name+"")) cout<<"construct selected"<<endl;
    else qDebug()<<"construct error: "<<query.lastError()<<" / "<<query.lastQuery();
    while(query.next()){
        Db::construct[index][0][0] = query.value(0).toFloat();
        Db::construct[index][0][1] = query.value(1).toFloat();
        Db::construct[index][0][2] = query.value(2).toFloat();

        Db::construct[index][1][0] = query.value(3).toFloat();
        Db::construct[index][1][1] = query.value(4).toFloat();
        Db::construct[index][1][2] = query.value(5).toFloat();

        Db::construct[index][2][0] = query.value(6).toFloat();
        Db::construct[index][2][1] = query.value(7).toFloat();
        Db::construct[index][2][2] = query.value(8).toFloat();

        Db::construct[index][3][0] = query.value(9).toFloat();
        Db::construct[index][3][1] = query.value(10).toFloat();
        Db::construct[index][3][2] = query.value(11).toFloat();

        index++;
    }
    /*for(int i=0; i<(int)Db::construct.size(); i++){
        for(int j=0; j<(int)Db::construct[i].size(); j++){
            for(int k=0; k<(int)Db::construct[i][j].size(); k++){
                cout<<i<<"/"<<j<<"/"<<k<<"/"<<Db::construct[i][j][k]<<endl;
            }
        }
    }*/
}

void Db::selectParts(QString name){
    Db::parts.clear();
    QSqlQuery query;
    if(query.exec("SELECT part FROM poly WHERE name ='"+name+"'")){
        selPart = "New part selected. Unsaved changes are lost.";
        cout<<"parts selected"<<endl;
    }else{
        selPart = "Select part error.";
        qDebug()<<"select parts error: "<<query.lastError()<<" / "<<query.lastQuery();
    }
    while(query.next()){
        Db::parts.push_back(query.value(0).toInt());
    }
}

void Db::addPartSQL(QString name){
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
    if(query.exec("INSERT INTO poly(name, part, ax,ay,az, bx,by,bz, cx,cy,cz, dx,dy,dz) VALUES ('"+name+"', '"+newPart+"', '0','0','0', '0','0','0', '0','0','0', '0','0','0')")){
        addPart = "New part created.";
        cout<<"new part inserted"<<endl;
    }else{
        addPart = "Create new part error";
        qDebug()<<"insert part error: "<<query.lastError()<<" / "<<query.lastQuery();
    }
}

void Db::updateA(QString name, QString part, QString x, QString y, QString z){
    QSqlQuery query;
    if(query.exec("UPDATE poly SET ax="+x+", ay="+y+", az="+z+" WHERE name="+name+" AND part="+part+"")){
        cout<<"updated A"<<endl;
    }else{
        qDebug()<<"update A error: "<<query.lastError()<<" / "<<query.lastQuery();
    }
}

void Db::updateB(QString name, QString part,QString x, QString y, QString z){
    QSqlQuery query;
    if(query.exec("UPDATE poly SET bx="+x+", by="+y+", bz="+z+" WHERE name="+name+" AND part="+part+"")){
        cout<<"updated B"<<endl;
    }else{
        qDebug()<<"update B error: "<<query.lastError()<<" / "<<query.lastQuery();
    }
}

void Db::updateC(QString name, QString part,QString x, QString y, QString z){
    QSqlQuery query;
    if(query.exec("UPDATE poly SET cx="+x+", cy="+y+", cz="+z+" WHERE name="+name+" AND part="+part+"")){
        cout<<"updated C"<<endl;
    }else{
        qDebug()<<"update C error: "<<query.lastError()<<" / "<<query.lastQuery();
    }
}

void Db::updateD(QString name, QString part,QString x, QString y, QString z){
    QSqlQuery query;
    if(query.exec("UPDATE poly SET dx="+x+", dy="+y+", dz="+z+" WHERE name="+name+" AND part="+part+"")){
        cout<<"updated D"<<endl;
    }else{
        qDebug()<<"update D error: "<<query.lastError()<<" / "<<query.lastQuery();
    }
}

void Db::savePartSQL(QString name, QString part, vector<vector<vector<QString>>> construct){
    updateA(name, part, construct[0][0][0], construct[0][0][1], construct[0][0][2]);
    updateB(name, part, construct[0][1][0], construct[0][1][1], construct[0][1][2]);
    updateC(name, part, construct[0][2][0], construct[0][2][1], construct[0][2][2]);
    updateD(name, part, construct[0][3][0], construct[0][3][1], construct[0][3][2]);
    savPart = "Part "+part+" saved.";
}

void Db::deletePartSQL(QString name, QString part){
    QSqlQuery query;
    if(query.exec("DELETE FROM poly WHERE name="+name+" AND part="+part+"")){
        delPart = "Part "+part+" deleted.";
        cout<<"deleted part"<<endl;
    }else{
        delPart = "Delete error.";
        qDebug()<<"delete part error: "<<query.lastError()<<" / "<<query.lastQuery();
    }
}

void Db::resetPartsSQL(QString name){
    vector<QString> oldIndex;
    QSqlQuery query;
    if(query.exec("SELECT part FROM poly WHERE name="+name+"")) cout<<"reset parts selected"<<endl;
    else qDebug()<<"reset parts select error: "<<query.lastError()<<" / "<<query.lastQuery();
    while(query.next()){
        oldIndex.push_back(query.value(0).toString());
    }
    QString ni;
    for(int i=0; i<(int)oldIndex.size(); i++){
        ni = QString::number(i);
        if(query.exec("UPDATE poly SET part="+ni+" WHERE name="+name+" AND part="+oldIndex[i]+"")){
            resPart = "Part indexes resetted.";
            cout<<"new "<<i<<" index updated"<<endl;
        }else{
            resPart = "Part indexes reset error.";
            qDebug()<<"reset parts error: "<<query.lastError()<<" / "<<query.lastQuery();
        }
    }
}

void Db::addName(){
    QVariant max;
    QString maxName;
    QSqlQuery query;
    if(query.exec("SELECT MAX(name) FROM poly")) cout<<"names selected"<<endl;
    else qDebug()<<"select names error: "<<query.lastError()<<" / "<<query.lastQuery();
    while(query.next()){
        max = query.value(0).toInt();
    }
    int z = max.toInt();
    z++;
    max = z;
    maxName = max.toString();
    if(query.exec("INSERT INTO poly (name, part, ax,ay,az, bx,by,bz, cx,cy,cz,dx,dy,dz) VALUES ("+maxName+",0, 0,0,0, 0,0,0, 0,0,0, 0,0,0)")) cout<<"name added"<<endl;
    else qDebug()<<"add name error: "<<query.lastError()<<" / "<<query.lastQuery();
}

void Db::removeName(QString name){
    QSqlQuery query;
    if(query.exec("DELETE FROM poly WHERE name="+name+"")) cout<<"name deleted"<<endl;
    else qDebug()<<"delete name error: "<<query.lastError()<<" / "<<query.lastQuery();
}
