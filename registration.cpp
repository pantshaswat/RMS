#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>

registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/sqlite3/RMS1.db");



   if(!mydb.open())
       ui->label_2->setText("Failed to open db");
   else
       ui->label_2->setText("Register Here");
}

registration::~registration()
{
    delete ui;
}

void registration::on_pushButton_3_clicked()
{

    QString name,email,password,cpassword,course,sem;
    name=ui->lineEdit_name->text();
    email=ui->lineEdit_email->text();
    password=ui->lineEdit_pass->text();
    cpassword=ui->lineEdit_cpass->text();
    course=ui->comboBox_course->currentText();
    sem=ui->comboBox_sem->currentText();
    if (mydb.open()) {
        qDebug()<<" connected!!";

    }

    mydb.open();
    QSqlQuery qry;
    qry.prepare("insert INTO Info (Name,Email,Password,Course,Sem) VALUES('"+name+"','"+email+"','"+password+"','"+course+"','"+sem+"')");
    if(password!=cpassword)
       { QMessageBox::warning(this,"Register","Passwords doesn't match");
    }
    else if (qry.exec())
    {
        QMessageBox::information(this,"Register","You are registered");
          // registration::done(1);

    }







}

