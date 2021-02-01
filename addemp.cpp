#include "addemp.h"
#include "ui_addemp.h"
#include"secdialog.h"
#include"ui_secdialog.h"
#include"mainwindow.h"
#include<QMessageBox>
#include<QErrorMessage>

Addemp::Addemp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Addemp)
{
    ui->setupUi(this);
}

Addemp::~Addemp()
{
    delete ui;
}

void Addemp::on_pushButton_clicked()
{
    SecDialog *sec = new SecDialog();
    sec->show();
    this->close();
}

void Addemp::on_pushButton_2_clicked()
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
    qry.prepare("insert into addemployee (firstname,lastname,email,mobile,address,birthdate,designation)"
    "values (:firstname, :lastname, :email, :mobile, :address, :birthdate, :designation)");

    qry.bindValue(":firstname",firstname);
    qry.bindValue(":lastname",lastname);
    qry.bindValue(":email",email);
    qry.bindValue(":mobile",mobile);
    qry.bindValue(":address",address);
    qry.bindValue(":birthdate",birthdate);
    qry.bindValue(":designation",designation);

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Save"),tr("Insert Successfully!"));
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
        QMessageBox::critical(this,tr("eroor"),qry.lastError().text());
    }


}

void Addemp::on_clear_clicked()
{
    ui->firstname->setText("");
    ui->lastname->setText("");
    ui->email->setText("");
    ui->mobile->setText("");
    ui->address->setText("");
    ui->birthdate->setText("");
    ui->designation->setText("");


}
