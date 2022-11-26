#include "dashboard_1.h"
#include "ui_dashboard_1.h"

dashboard_1::dashboard_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dashboard_1)
{
    ui->setupUi(this);
}

dashboard_1::~dashboard_1()
{
    delete ui;
}
