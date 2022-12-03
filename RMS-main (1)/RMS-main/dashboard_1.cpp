#include "dashboard_1.h"
#include "ui_dashboard_1.h"
#include "admin.h"
#include"passback.h"
#include <QMessageBox>
#include<iostream>



extern QString email;
extern QString course;
extern QString sem;
dashboard_1::dashboard_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dashboard_1)
{
    ui->setupUi(this);
    ui->comboBox_chooseCourse->hide();
    ui->pushButton_updateTable->hide();

    loadTable("Sunday");

    conn.connOpen();
    if(!conn.connOpen())

        qDebug()<<"Failed to open db";
    else
         qDebug()<<"Connected";

    QSqlQuery qry1;
    qry1.prepare("select * from Info where Email='"+email+"' and checkAdmin='1'");
    if(qry1.exec())
    {
         while(qry1.next())
         {
             isAdmin++;
         }
         if (isAdmin==1)
         {
             admin();
         }
    }

}

void dashboard_1::admin()
{
        ui->comboBox_chooseCourse->show();
        ui->pushButton_updateTable->show();
}


void dashboard_1::loadTable (QString day)
{
    // To load database
    QSqlQueryModel * modal=new QSqlQueryModel () ;
    conn.connOpen();

            QSqlQuery* qryco = new QSqlQuery(conn.mydb);
            QSqlQuery* qrycv = new QSqlQuery(conn.mydb);

            qrycv->prepare("select Time,Subject,Teacher,RoomNO from Civil_I where Day='"+day+"'");
            qryco->prepare("select Time,Subject,Teacher,RoomNO from Computer_I where Day='"+day+"'");


       if (!isAdmin) //Student
            {
           if (course=="Computer Engineering" && sem=="I"){
               qryco->exec();
               modal->setQuery(*qryco);
           }

           else if (course=="Civil Engineering" && sem=="I"){
               qrycv->exec();
               modal->setQuery(*qrycv);
           }
            }

        else //Teacher
       {

            if (table == "Computer I"){
                qryco->exec();
                modal->setQuery(*qryco);
            }

            else if (table == "Civil I"){
                qrycv->exec();
                modal->setQuery(*qrycv);
            }
            else qDebug() << "No table detail found";
       }

       ui->tableView->setModel(modal); //For displaying table

}


void dashboard_1::on_pushButton_sun_clicked()
{
    day = "Sunday";
    loadTable(day);
}


void dashboard_1::on_pushButton_mon_clicked()
{
  day = "Monday";
  loadTable(day);
}


void dashboard_1::on_pushButton_tue_clicked()
{
    day = "Tuesday";
    loadTable(day);
}


void dashboard_1::on_pushButton_wed_clicked()
{
    day = "Wednesday";
    loadTable(day);
}


void dashboard_1::on_pushButton_thu_clicked()
{
    day = "Thursday";
    loadTable(day);
}


void dashboard_1::on_pushButton_friday_clicked()
{
    day = "Friday";
    loadTable(day);
}

void dashboard_1::on_comboBox_chooseCourse_currentTextChanged(const QString &arg1)
{
    qDebug() << arg1;
    table = arg1;
    loadTable("Sunday");
}

dashboard_1::~dashboard_1()
{
    delete ui;
}

void dashboard_1::on_pushButton_updateTable_clicked()
{
    class admin admin;

    admin.setModal(true);
    admin.exec();




}

