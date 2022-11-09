#include "passbackup.h"
#include "ui_passbackup.h"
#include <QMessageBox>

passbackup::passbackup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passbackup)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Shaswat/OneDrive/Pictures/fg.png");
    ui->label_6->setPixmap(pix);
    QPixmap pic("C:/Users/Shaswat/OneDrive/Pictures/Screenshots/routine.jpg");
    ui->label_4->setPixmap(pic);
}

passbackup::~passbackup()
{
    delete ui;
}

void passbackup::on_pushButton_3_clicked()
{
    QMessageBox::information(this,"Forgot Password","Your new Password is sent at your Email.");
    passbackup::close();
}

