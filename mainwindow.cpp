#include "mainwindow.h"           // bibliotheque a utiliser
#include "ui_mainwindow.h"
#include <QSqlTableModel>
#include <QPushButton>
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");//connection a la bdd
    db.setHostName("127.0.0.1");
    db.setDatabaseName("equipe");
    db.setUserName("student");
    db.setPassword("crif2024sn");
    if(db.open())
    {
        qDebug() <<"Vous etes maintenant connecté à " << db.hostName();}// ligne de code qui permet d'approuver a l'utilisateur  quil est bien connecter a la base de donner

    connect(ui->pushButton,&QPushButton::clicked, this, &MainWindow::setupModel);//Cette ligne de code est associée à la manipulation du bouton dans l'interface UI
    connect(ui->pushButton_2, &QPushButton::clicked,this,&MainWindow::changervaleur);//Cette ligne de code est associée à la manipulation du bouton dans l'interface UI


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setupModel(){
    QSqlQueryModel *Model = new QSqlQueryModel;

    Model->setQuery("SELECT * from jeu"); // Définition de la requête SQL pour sélectionner toutes les colonnes de la table jeu
    ui->tableView->setModel(Model);
}
void MainWindow::changervaleur(){// Méthode appelée en réponse au clic sur un bouton

    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();//renvoie une valeur ou une référence à une valeur provenant d'un tableau
    if(!selectedIndexes.isEmpty()){// Vérification si des index ont été sélectionnés
        int row = selectedIndexes.first().row();// Récupération du numéro de ligne du premier élément sélectionné
        int idPlayer = ui->tableView->model()->data(ui->tableView->model()->index(row,0)).toInt(); // Récupération de la valeur de la première colonne de la ligne sélectionnée
        QSqlQuery query;

        query.prepare("UPDATE jeu SET note = :note WHERE id = :id");// Création d'une requête SQL préparée pour mettre à jour la valeur de la colonne note
        query.bindValue(":note",ui->lineEdit->text());
        query.bindValue(":id",idPlayer);
        query.exec();// Exécution de la requête pour mettre à jour la base de données
        setupModel();
    }
}
