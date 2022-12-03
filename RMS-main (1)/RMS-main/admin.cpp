#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);

    }





admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_clicked()
{
    QString subject,room,teacher;
    subject =ui->lineEdit_subject->text();
    room =ui->lineEdit_room->text();
    teacher =ui->lineEdit_teacher->text();
    conn.connOpen();

    QSqlQuery qryco,qrycv;
    qryco.prepare("update Computer_I set Subject='"+subject+"',RoomNO='"+room+"',Teacher='"+teacher+"' where id=:x");
    qryco.bindValue(":x",id);
    qrycv.prepare("update Civil_I set Subject='"+subject+"',RoomNO='"+room+"',Teacher='"+teacher+"' where id=:x");
    qrycv.bindValue(":x",id);
    if (table1 == "Computer I"){

        qryco.exec();
        QMessageBox::information(this,"Updated","Routine has been updated");
    }
    else if (table1 == "Civil I"){
        qrycv.exec();
        QMessageBox::information(this,"Updated","Routine has been updated");
    }
    else qDebug() << "Error!!!";
    qDebug() << id;
    value= value_routine * value_day * value_time;
    if (value)
    {

    }
}

void admin::display()          //dispaly the value in line_edit
{
    qDebug()<<id;
     QSqlQuery qryco1,qrycv1;
    qryco1.prepare("select * from Computer_I where id=:x");
    qryco1.bindValue(":x",id);
    qrycv1.prepare("select * from Civil_I where id=:x");
    qrycv1.bindValue(":x",id);
    if (table1 == "Computer I"){

        if(qryco1.exec())
            {
                while(qryco1.next())
                {
                    ui->lineEdit_subject->setText(qryco1.value(3).toString());
                    ui->lineEdit_room->setText(qryco1.value(4).toString());
                    ui->lineEdit_teacher->setText(qryco1.value(5).toString());


                }
            }
    }
    else if (table1 == "Civil I"){
        if(qrycv1.exec())
            {
                while(qrycv1.next())
                {
                    ui->lineEdit_subject->setText(qrycv1.value(3).toString());
                    ui->lineEdit_room->setText(qrycv1.value(4).toString());
                    ui->lineEdit_teacher->setText(qrycv1.value(5).toString());


                }
            }
    }
}
void admin::on_comboBox_currentTextChanged(const QString &arg1) //routine
{
    if(arg1 != "Choose Routine"){


    qDebug() << arg1;
    table1 = arg1;
    display();
    }
}



void admin::on_comboBox_2_currentIndexChanged(int index) //day
{
    if (index > 0){
        value_day=1;
        value= value_routine * value_day * value_time;



    int time_in_hrs = id % 100; //time
    id = index * 100;
    id += time_in_hrs;
     display();
    }
}


void admin::on_comboBox_3_currentIndexChanged(int index) //time
{
    if(index){
         value_time=1;
        value= value_routine * value_day * value_time;



    int day_number = id / 100; //day
    id = 8 + index;
    id = day_number * 100 + id;
    display();
    }
}


/*
#@@
DTT

# = 0
009
009 (invalid)

@@ = 09
100
109
*/

void admin::on_pushButton_2_clicked()
{
    QString student_email,student_name,student_course,student_sem;
    student_email = ui->lineEdit_email->text();
    student_name = ui->lineEdit_name->text();
    student_course = ui->comboBox_course->currentText();
    student_sem = ui->comboBox_sem->currentText();

    conn.connOpen();
    QSqlQuery qry,qry1;
    int count=0;
    qry1.prepare("select * from Info where Email='"+student_email+"'");
    qry.prepare("Update Info set Name='"+student_name+"',Course='"+student_course+"',Sem='"+student_sem+"'where Email='"+student_email+"'");
    //qry1.bindValue(":x",student_email);
    if(student_name == "" || student_course == "Choose your course"|| student_sem == "Choose your semester")
    {
             QMessageBox::information(this,"Missing","All the fields are mandatory");
    }
    if (qry1.exec()){
       while(qry1.next()){

           count++;
       }
       if (count==1){
            if(qry.exec()){
            QMessageBox::information(this,"Updated","Profile has been updated");
            }
            else {QMessageBox::information(this,"Email","db no run");}
            ui->lineEdit_email->setText("");
            ui->lineEdit_name->setText("");
            ui->comboBox_course->setCurrentIndex(0);
            ui->comboBox_sem->setCurrentIndex(0);
       }
       else {

           QMessageBox::information(this,"Email","The email does not exist");
       }
        }

}





void admin::on_pushButton_3_clicked()
{
   QString add_email = ui->lineEdit_email_2->text();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Insert into Info (Email)VALUES('"+add_email+"')");
    if(qry.exec())
    {
        QMessageBox::information(this,"Email","The student email has been added");
    }
    ui->lineEdit_email_2->setText("");

}

