#include "passback.h"
#include "ui_passback.h"
#include <QMessageBox>

extern QString email;
extern QString name;
passback::passback(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passback)
{
    ui->setupUi(this);
    ui->pushButton_eye->setStyleSheet("border-image: url(:/img/IMG resources/hide.png);");
    ui->pushButton_ceye->setStyleSheet("border-image: url(:/img/IMG resources/hide.png);");
    conn.connOpen();
    if(!conn.connOpen())
        qDebug()<<"Failed to open db";
    else
         qDebug()<<"Connected";

}


QString emailback;
void passback::on_pushButton_3_clicked()
{
    QString emailback=ui->lineEdit_email->text();
    QString nameback=ui->lineEdit_name->text();
    QString newpass,cnewpass;
    newpass= ui->lineEdit_newpass->text();
    cnewpass=ui->lineEdit_cnewpass->text();
    conn.connOpen();

    QSqlQuery qry, qry1;
    qry.prepare("select * from Info where Email='"+emailback+"'and Name='"+nameback+"'");
        if (qry.exec())
        {
            int count=0;
            while (qry.next())
            {
                    count++;
            }
            if (count==1)
            {
                qry1.prepare("Update Info set Password='"+newpass+"' where Email='"+emailback+"'");
                if(newpass.length()<=5)
                 {

                     QMessageBox::information(this,"Password!","Passwords must be atleast 6 characters");
                 }
                else if(newpass!=cnewpass)
                {
                    QMessageBox::information(this,"Passwords!","Passwords does not match");
                }

                else if (qry1.exec())
                {
                      QMessageBox::information(this,"Changed","Password has been reset");
                }
            }

            else
          QMessageBox::warning(this,"Login Failed!","Email and Name does not match");
        }
    }



/*
void passback::on_pushButton_changepass_clicked()
{
    QString newpass,cnewpass;
    newpass= ui->lineEdit_newpass->text();
    cnewpass=ui->lineEdit_cnewpass->text();
    conn.connOpen();
    QSqlQuery qry;
    qry1.prepare("Update Info set Password='"+newpass+"' where Email='"+email+"'");
    if(newpass.length()<=5)
     {

         QMessageBox::information(this,"Password!","Passwords must be atleast 6 characters");
     }
    else if(newpass!=cnewpass)
    {
        QMessageBox::information(this,"Passwords!","Passwords does not match");
    }

    if (qry1.exec())
    {
          QMessageBox::information(this,"Changed","Password has been reset");
    }


}*/
passback::~passback()
{
    delete ui;
}
extern int count;
void passback::on_pushButton_eye_clicked()
{
    if (count==0){
    ui->pushButton_eye->setStyleSheet("border-image: url(:/img/IMG resources/view.png);");
    ui->lineEdit_newpass->setEchoMode(QLineEdit::Normal);
    count=1;
    }
    else
    {
        ui->pushButton_eye->setStyleSheet("border-image: url(:/img/IMG resources/hide.png);");
        ui->lineEdit_newpass->setEchoMode(QLineEdit::Password);\
        count=0;
    }
}


void passback::on_pushButton_ceye_clicked()
{
    if (count==0){
    ui->pushButton_ceye->setStyleSheet("border-image: url(:/img/IMG resources/view.png);");
    ui->lineEdit_cnewpass->setEchoMode(QLineEdit::Normal);
    count=1;
    }
    else
    {
        ui->pushButton_ceye->setStyleSheet("border-image: url(:/img/IMG resources/hide.png);");
        ui->lineEdit_cnewpass->setEchoMode(QLineEdit::Password);\
        count=0;
    }
}

