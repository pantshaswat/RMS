#include "dashboard_1.h"
#include "ui_dashboard_1.h"
#include <QMessageBox>



dashboard_1::dashboard_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dashboard_1)
{
    ui->setupUi(this);
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/sqlite3/RMS1.db");

    // To load table
    QSqlQueryModel * modal=new QSqlQueryModel () ;

        mydb.open();

            QSqlQuery* qry = new QSqlQuery(mydb);
            qry->prepare("select * from Info");
            qry->exec();

                 modal->setQuery(*qry);
                ui->tableView->setModel(modal);



}

dashboard_1::~dashboard_1()
{
    delete ui;
}




