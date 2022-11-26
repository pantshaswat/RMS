#include "profile.h"
#include "ui_profile.h"


extern QString email;

profile::profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);
    ui->frame->hide();
    ui->left_arrow->hide();
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





















void profile::on_right_arrow_clicked()
{
    ui->frame->show();
    ui->left_arrow->show();
    ui->right_arrow->hide();
}


void profile::on_left_arrow_clicked()
{
    ui->frame->hide();
    ui->right_arrow->show();
    ui->left_arrow->hide();
}

