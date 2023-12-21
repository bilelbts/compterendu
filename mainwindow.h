#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setupModel();
    void changervaleur();
private slots:
    //void updateButtons(int row);

private:
    Ui::MainWindow *ui;

    //QStandardItemModel *model;
    //QDataWidgetMapper *mapper;
};
#endif // MAINWINDOW_H
