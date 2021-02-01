#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(!connOpen())
        ui->label_3->setText("Database Error!");
    else
        ui->label_3->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    QString username,password;
     username = ui->Edit_username->text();
     password = ui->Edit_password->text();

    if(!mydb.isOpen()){
        qDebug()<<"Failed to open databse";
        return;
    }
    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from login where username='"+username+"' and password='"+password+"'");

    if(qry.exec()){
        int count = 0;
        while(qry.next())
        {
            count++;
        }
        if(count==1){
            ui->label_3->setText("");
            connClose();
            this->hide();

           SecDialog secdialog ;
           secdialog.setModal(true);
           secdialog.exec();

        }

        if(count<1)
            ui->label_3->setText("The Username or Password is incorrect!");

    }
}
