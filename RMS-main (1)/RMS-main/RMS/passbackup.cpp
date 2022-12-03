#include "passbackup.h"
#include "ui_passbackup.h"
#include <QMessageBox>

passbackup::passbackup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passbackup)
{
    ui->setupUi(this);


}

passbackup::~passbackup()
{
    delete ui;
}

void passbackup::on_pushButton_3_clicked()
{
    QMessageBox::information(this,"Forgot Password","Your new Password is sent to your Email.");
    passbackup::close();
}

