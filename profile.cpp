#include "profile.h"
#include "ui_profile.h"

profile::profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Shaswat/OneDrive/Pictures/fg.png");
    ui->label_6->setPixmap(pix);

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

