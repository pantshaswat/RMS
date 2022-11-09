#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>

registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);


}

registration::~registration()
{
    delete ui;
}

void registration::on_pushButton_3_clicked()
{
    QMessageBox::information(this,"Register","You are registered");

    registration::done(1);
}

