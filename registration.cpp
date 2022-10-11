#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>

registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Shaswat/OneDrive/Pictures/fg.png");
    ui->label_6->setPixmap(pix);
    QPixmap pic("C:/Users/Shaswat/OneDrive/Pictures/Screenshots/routine.jpg");
    ui->label_4->setPixmap(pic);
}

registration::~registration()
{
    delete ui;
}

void registration::on_pushButton_3_clicked()
{
    QString password1=ui->lineEdit_4->text();
    QString password2=ui->lineEdit_5->text();
    if( password1 ==password2){
        QMessageBox::information(this,"Register ","You are registered");

    registration::done(1);
}
    else { QMessageBox::critical(this,"Register","Passwords does not match");}
}
