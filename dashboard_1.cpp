#include "dashboard_1.h"
#include "ui_dashboard_1.h"
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
    loadTable("Sunday");
    ui->comboBox_chooseCourse->hide();
    ui->pushButton_updateTable->hide();

    conn.connOpen();
    if(!conn.connOpen())

        qDebug()<<"Failed to open db";
    else
         qDebug()<<"Connected";

    QSqlQuery qry1;
    qry1.prepare("select * from Info where Email='"+email+"' and checkAdmin='1'");
    if(qry1.exec())
    {       int count=0;
         while(qry1.next())
         {
             count++;
         }
         if (count==1)
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
    MainWindow conn;

    // To load table
    QSqlQueryModel * modal=new QSqlQueryModel () ;

        conn.connOpen();


            QSqlQuery* qry = new QSqlQuery(conn.mydb);
            QSqlQuery* qrycv = new QSqlQuery(conn.mydb);
            qrycv->prepare("select Time,Subject,Teacher,RoomNO from Civil_I where Day='"+day+"'");
            qry->prepare("select Time,Subject,Teacher,RoomNO from Computer_I where Day='"+day+"'");
            if (course=="Computer Engineering" && sem=="I"){
                qry->exec();
                modal->setQuery(*qry);
               ui->tableView->setModel(modal);
            }
            else if (course=="Civil Engineering" && sem=="I"){
                qrycv->exec();
                modal->setQuery(*qrycv);
               ui->tableView->setModel(modal);
            }

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









dashboard_1::~dashboard_1()
{
    delete ui;
}
