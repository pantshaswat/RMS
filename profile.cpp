#include "profile.h"
#include "ui_profile.h"
#include"mainwindow.h"

profile::profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Shaswat/OneDrive/Pictures/fg.png");
    ui->label_6->setPixmap(pix);
     MainWindow conn;
    if(!conn.connOpen())
        ui->label->setText("Failed to open db");


}


profile::~profile()
{
    delete ui;
}

void profile::on_listWidget_itemSelectionChanged()
{
    QTabWidget tabWidget;
    tabWidget;
}

