#include "viewemp.h"
#include "ui_viewemp.h"
#include"secdialog.h"
#include"ui_secdialog.h"
#include"mainwindow.h"

Viewemp::Viewemp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Viewemp)
{
    ui->setupUi(this);
}

Viewemp::~Viewemp()
{
    delete ui;
}

void Viewemp::on_pushButton_clicked()
{
 SecDialog *sec = new SecDialog();
 sec->show();
 this->close();
}

void Viewemp::on_pushButton_2_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from addemployee");

    qry->exec();
    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
    conn.connClose();

    qDebug() <<(modal->rowCount());
}
