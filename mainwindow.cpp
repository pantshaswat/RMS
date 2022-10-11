#include "mainwindow.h"
#include "passbackup.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "registration.h"
#include "profile.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/IMG resources/fg.png");
    ui->label_6->setPixmap(pix);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_password->text();

   /* if( username =="Test" && password=="Test")*/ //{
        hide();
        profile profile;                // opening profile window
        profile.setModal (true);
        profile.exec();

 //   }
   /* profile = new class profile(this);    // another way of opening new window for this we need to create an instance of 'profile' in private of mainwondow.h
    profile->show();*/

   /* else{
       QMessageBox::StandardButton reply = QMessageBox::critical(this,"Login","Username or password is not correct \n \n Try again?",QMessageBox::Yes | QMessageBox:: No);
        if (reply == QMessageBox::Yes){

        }
        else QApplication:: quit();
}*/
}



void MainWindow::on_commandLinkButton_2_clicked()
{
    registration registration;
    registration.setModal (true);
    registration.exec();

}


void MainWindow::on_commandLinkButton_clicked()
{
    passbackup passbackup;
    passbackup.setModal(true);
    passbackup.exec();
}

