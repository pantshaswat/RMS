#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>

QString email;
QString name;
QString course;
QString sem;

registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);


    setWindowFlags( windowFlags() | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint );

    ui->lineEdit_name->setPlaceholderText("Enter Your Name");
    ui->lineEdit_email->setPlaceholderText("Enter Your Student Email");
    ui->lineEdit_pass->setPlaceholderText("Create Your Password");
    ui->lineEdit_cpass->setPlaceholderText("Re-write Your Password");

    conn.connOpen();
   if(!conn.connOpen())
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
    conn.connOpen();
    if (conn.connOpen()) {
        qDebug()<<" connected!!";

    }

    conn.connOpen();
    int count=0;
    QSqlQuery qry,qry1;
    qry1.prepare("select * from Info where Email='"+email+"'");
    qry.prepare("Update Info set Name='"+name+"', Password='"+password+"',Course='"+course+"',Sem='"+sem+"'where Email=:x");
    qry.bindValue(":x",email);

    if(name == "" || email == "" || password == ""|| cpassword == "" || course == "Choose your course"|| sem == "Choose your semester")
    {
             QMessageBox::information(this,"Missing","All the fields are mandatory");
    }
    else if(password.length()<=5)
       {
            ui->lineEdit_pass->setStyleSheet("border:1px solid red");
           QMessageBox::warning(this,"Password!","Password must be atleast 6 characters");
       }
    else {
        if(password!=cpassword)
               {
                    ui->lineEdit_pass->setStyleSheet("border:1px solid red");
                    ui->lineEdit_cpass->setStyleSheet("border:1px solid red");

            QMessageBox::warning(this,"Passwords!","Passwords doesn't match");

               }
        else if (qry1.exec()){
           while(qry1.next()){

               count++;
           }
           if (count==1){
                qry.exec();

                 QMessageBox::information(this,"Register","You are registered!");

           }
           else {
               ui->lineEdit_email->setStyleSheet("border:1px solid red");
               QMessageBox::information(this,"Email","The email does not exist");
           }
            }
    }

}


extern int count;
void registration::on_pushButton_eye_clicked()
{
    if (count==0){
    ui->pushButton_eye->setStyleSheet("border-image: url(:/img/IMG resources/view.png);");
    ui->lineEdit_pass->setEchoMode(QLineEdit::Normal);
    count=1;
    }
    else
    {
        ui->pushButton_eye->setStyleSheet("border-image: url(:/img/IMG resources/hide.png);");
        ui->lineEdit_pass->setEchoMode(QLineEdit::Password);\
        count=0;
    }
}


void registration::on_pushButton_eye_2_clicked()
{
    if (count==0){
    ui->pushButton_eye_2->setStyleSheet("border-image: url(:/img/IMG resources/view.png);");
    ui->lineEdit_cpass->setEchoMode(QLineEdit::Normal);
    count=1;
    }
    else
    {
        ui->pushButton_eye_2->setStyleSheet("border-image: url(:/img/IMG resources/hide.png);");
        ui->lineEdit_cpass->setEchoMode(QLineEdit::Password);\
        count=0;
    }
}

