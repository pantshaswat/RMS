#include "dashboard_1.h"
#include "ui_dashboard_1.h"
#include <QMessageBox>



dashboard_1::dashboard_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dashboard_1)
{
    ui->setupUi(this);





}
void dashboard_1::loadTable (QString day)
{
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/sqlite3/RMS1.db");


    // To load table
    QSqlQueryModel * modal=new QSqlQueryModel () ;

        mydb.open();

            QSqlQuery* qry = new QSqlQuery(mydb);
            qry->prepare("select Time,Subject,Teacher,RoomNO from Computer_I where Day='"+day+"'");
            qry->exec();

                 modal->setQuery(*qry);
                ui->tableView->setModel(modal);
}





void dashboard_1::on_pushButton_sun_clicked()
{
    day = "sun";
    loadTable(day);
}


void dashboard_1::on_pushButton_mon_clicked()
{
  day = "mon";
  loadTable(day);
}


void dashboard_1::on_pushButton_tue_clicked()
{
    day = "tue";
    loadTable(day);
}


void dashboard_1::on_pushButton_wed_clicked()
{
    day = "wed";
    loadTable(day);
}


void dashboard_1::on_pushButton_thu_clicked()
{
    day = "thu";
    loadTable(day);
}


void dashboard_1::on_pushButton_friday_clicked()
{
    day = "fri";
    loadTable(day);
}

dashboard_1::~dashboard_1()
{
    delete ui;
}
