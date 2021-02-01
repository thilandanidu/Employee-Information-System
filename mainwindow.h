#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secdialog.h"
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;

    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);

    }

    bool connOpen(){
        mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/thila/Documents/Qt/LoginApp/employee.db");

        {
            if(!mydb.open()){
                qDebug()<<("");
                return false;

            }
            else{
                qDebug()<<("");
                return true;
            }

    }
    }

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;
    SecDialog *secDialog;
};
#endif // MAINWINDOW_H
