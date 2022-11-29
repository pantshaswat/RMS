#include "profile.h"
#include "dashboard_1.h"
#include "ui_profile.h"
#include "dashboard_1.h"
#include <QMessageBox>


extern QString email;
extern QString password;

profile::profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);
           /* ui->pushButton_profile->hide();
            ui->pushButton_dashboard->hide();
            ui->pushButton_calender->hide();
            ui->pushButton_ToDo->hide();
            ui->pushButton_about->hide();
            ui->pushButton_help->hide();*/
            ui->frame_2->hide();
            ui->groupBox_editProfile_2->hide();
            ui->groupBox_editProfile->hide();
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/sqlite3/RMS1.db");
    if(mydb.open())
    {
        QSqlQuery qry;
        qry.prepare("select * from Info where Email='"+email+"'");

        if(qry.exec())
            {
                while(qry.next())
                {
                    ui->label->setText(qry.value(0).toString());
                    ui->label_name->setText(qry.value(0).toString());
                    ui->label_email->setText(qry.value(1).toString());
                    ui->label_course->setText(qry.value(3).toString());
                    ui->label_sem->setText(qry.value(4).toString());

                }
            }

}
}
profile::~profile()
{
    delete ui;
}
void profile::on_pushButton_dashboard_clicked()
{
    dashboard_1 dashboard_1;
    dashboard_1.setModal (true);
    dashboard_1.exec();
}






void profile::on_pushButton_update_clicked()
{
    QString editname,editcourse,editsem;
    editname=ui->lineEdit_editName->text();
    editcourse=ui->comboBox_editCourse->currentText();
    editsem=ui->comboBox_editSem->currentText();
    if (mydb.open()) {
        qDebug()<<" connected!!";

    }

    mydb.open();

    QSqlQuery qry1;

    qry1.prepare("Update Info set Name='"+editname+"',Course='"+editcourse+"',Sem='"+editsem+"'where Email='"+email+"'");
    if(editname == ""|| editcourse == "Choose your course"|| editsem == "Choose your semester")
    {
             QMessageBox::information(this,"Missing","All the fields are mandatory");
    }

        else if (qry1.exec()){

                 QMessageBox::information(this,"Updated","Profile has been updated successfully");
                 ui->label->setText(editname);
                 ui->label_name->setText(editname);
                 ui->label_course->setText(editcourse);
                 ui->label_sem->setText(editsem);
           }
           else {

               QMessageBox::critical(this,"Error","Profile has not been updated");
           }
    ui->groupBox_editProfile->hide();
    ui->lineEdit_editName->setText("");

            }






void profile::on_pushButton_passupdate_clicked()
{
    QString newpass,cnewpass,oldpass;

    newpass=ui->lineEdit_newpass->text();
    cnewpass=ui->lineEdit_cnewpass->text();
    oldpass=ui->lineEdit_oldpass->text();


    mydb.open();

    QSqlQuery qry1;

           if (password==oldpass){

              qry1.prepare("Update Info set Password='"+newpass+"'where Email='"+email+"'");

               if(newpass.length()<=5)
                 {
                      ui->lineEdit_newpass->setStyleSheet("border:1px solid red");
                     QMessageBox::warning(this,"Password!","Password must be atleast 6 characters");
                 }

                  else if(newpass!=cnewpass)
                         {
                              ui->lineEdit_newpass->setStyleSheet("border:1px solid red");
                              ui->lineEdit_cnewpass->setStyleSheet("border:1px solid red");

                      QMessageBox::warning(this,"Passwords!","Passwords doesn't match");

                         }
               else if(qry1.exec()) {QMessageBox::warning(this,"Passwords!","Your password has been changed");
                ui->groupBox_editProfile_2->hide();
               }
           }
           else {
               ui->lineEdit_oldpass->setStyleSheet("border:1px solid red");
               QMessageBox::information(this,"Email","Old password does not match");
           }


            ui->lineEdit_newpass->setText("");
            ui->lineEdit_cnewpass->setText("");

}





int count=0;
void profile::on_hamburgerButton_clicked()

    {

        if (count==0)
        {
            ui->pushButton_profile->hide();
            ui->pushButton_dashboard->hide();
            ui->pushButton_calender->hide();
            ui->pushButton_ToDo->hide();
            ui->pushButton_about->hide();
            ui->pushButton_help->hide();
            ui->frame_2->show();

            count=1;
            }
        else {

            ui->pushButton_profile->show();
            ui->pushButton_dashboard->show();
            ui->pushButton_calender->show();
            ui->pushButton_ToDo->show();
            ui->pushButton_about->show();
            ui->pushButton_help->show();
            ui->frame_2->hide();
            count=0;
        }

    }







void profile::on_pushButton_EditProfile_clicked()
{
    if (count==0)
    {
        ui->groupBox_editProfile->show();
        count=1;
        }
    else {

        ui->groupBox_editProfile->hide();
        count=0;
    }
}


void profile::on_pushButton_editProfile_2_clicked()
{
    if (count==0)
    {
        ui->groupBox_editProfile_2->show();
        count=1;
        }
    else {

        ui->groupBox_editProfile_2->hide();
        count=0;
    }
}

