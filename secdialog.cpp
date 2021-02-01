#include "secdialog.h"
#include "ui_secdialog.h"
#include"addemp.h"
#include"editdelemp.h"
#include"viewemp.h"

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_pushButton_addemp_clicked()
{
    Addemp *add = new Addemp();
    add->show();
    this->close();
}

void SecDialog::on_pushButton_editdel_clicked()
{
    Editdelemp *add = new Editdelemp();
    add->show();
    this->close();
}

void SecDialog::on_pushButton_viewemp_clicked()
{
    Viewemp *add = new Viewemp();
    add->show();
    this->close();
}
