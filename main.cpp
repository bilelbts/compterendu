#include "mainwindow.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlQuery>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   /* QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("equipe");
    db.setUserName("student");
    db.setPassword("crif2024sn");
    if(db.open())
    {
        qDebug() <<"Vous etes maintenant connecté à " << db.hostName();

        QSqlQuery query;
        query.exec("SELECT * FROM `jeu` ");
            while (query.next()) {
            QString id= query.value(0).toString();
            QString nom = query.value(1).toString();
            QString prenom = query.value(2).toString();
              QString club = query.value(3).toString();
            QString note = query.value(4).toString();

            qDebug() <<"\t|----------------------------------------------------------------------------------------------------";
            qDebug() <<"\t|" <<"\t|"<< id << "\t|" << nom <<"\t|" << prenom<<"\t|" << club  <<"\t|" << note  <<"\t|" ;
        }
            qDebug() <<"\t|----------------------------------------------------------------------------------------------------";
            qDebug() << "Requete ok ! :";
            db.close();
    }
    else
    {
        qDebug() << "La connexion a échouée, désolée" << db.lastError().text();
    }
*/
    w.show();

    return a.exec();
}
