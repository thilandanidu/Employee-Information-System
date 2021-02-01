#include "editdelemp.h"
#include "ui_editdelemp.h"
#include"secdialog.h"
#include"ui_secdialog.h"
#include"mainwindow.h"
#include<QMessageBox>
#include<QErrorMessage>

Editdelemp::Editdelemp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Editdelemp)
{
    ui->setupUi(this);
}

Editdelemp::~Editdelemp()
{
    delete ui;
}

void Editdelemp::on_pushButton_clicked()
{
    SecDialog *sec = new SecDialog();
    sec->show();
    this->close();
}

void Editdelemp::on_pushButton_3_clicked()
{
    MainWindow conn;
    QSqlQueryModel *modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select firstname from addemployee");

    qry->exec();
    modal->setQuery(*qry);

    ui->comboBox->setModel(modal);
    conn.connClose();

    qDebug() <<(modal->rowCount());
}

void Editdelemp::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString firstname=ui->comboBox->currentText();

    MainWindow conn;
    if(!conn.connOpen()){
        qDebug()<<"Failed Database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from addemployee where firstname='"+firstname+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->firstname->setText(qry.value(0).toString());
            ui->lastname->setText(qry.value(1).toString());
            ui->email->setText(qry.value(2).toString());
            ui->mobile->setText(qry.value(3).toString());
            ui->address->setText(qry.value(4).toString());
            ui->birthdate->setText(qry.value(5).toString());
            ui->designation->setText(qry.value(6).toString());
        }
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("eroor"),qry.lastError().text());
    }
}

void Editdelemp::on_pushButton_2_clicked()
{
    MainWindow conn;
    QString firstname,lastname,email,mobile,address,birthdate,designation;
    firstname=ui->firstname->text();
    lastname=ui->lastname->text();
    email=ui->email->text();
    mobile=ui->mobile->text();
    address=ui->address->text();
    birthdate=ui->birthdate->text();
    designation=ui->designation->text();

    if(!conn.connOpen()){
        qDebug()<<"Failed to open database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update addemployee set firstname='"+firstname+"',lastname='"+lastname+"',email='"+email+"',mobile='"+mobile+"',address='"+address+"',birthdate='"+birthdate+"',designation='"+designation+"' where firstname='"+firstname+"'");

    if(qry.exec())
    {
    QMessageBox::critical(this,tr("Update"),tr("Updated Successfully!"));
    ui->firstname->setText("");
    ui->lastname->setText("");
    ui->email->setText("");
    ui->mobile->setText("");
    ui->address->setText("");
    ui->birthdate->setText("");
    ui->designation->setText("");
    conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error!"),qry.lastError().text());
    }
}

void Editdelemp::on_clear_clicked()
{
   // ui->firstname->setText("");
    ui->lastname->setText("");
    ui->email->setText("");
    ui->mobile->setText("");
    ui->address->setText("");
    ui->birthdate->setText("");
    ui->designation->setText("");
}

void Editdelemp::on_pushButton_4_clicked()
{
    MainWindow conn;
    QString firstname,lastname,email,mobile,address,birthdate,designation;
    firstname=ui->firstname->text();
    lastname=ui->lastname->text();
    email=ui->email->text();
    mobile=ui->mobile->text();
    address=ui->address->text();
    birthdate=ui->birthdate->text();
    designation=ui->designation->text();

    if(!conn.connOpen()){
        qDebug()<<"Failed to open database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from addemployee"
           " where firstname=:firstname  ");

    qry.bindValue(":firstname",firstname);


    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Delete"),tr("Delete Successfully!"));

        conn.connClose();

    }
    else{
        QMessageBox::critical(this,tr("eroor"),qry.lastError().text());
    }



};

