#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include "mainwindow.h"


//For database connection
#include <QtSql>
#include <QDebug>
#include <QFileInfo>


namespace Ui {
class registration;
}

class registration : public QDialog
{
    Q_OBJECT

public:
    MainWindow conn;
    explicit registration(QWidget *parent = nullptr);
    ~registration();

private slots:
    void on_pushButton_3_clicked();





private:
    Ui::registration *ui;
    QSqlDatabase mydb;
};

#endif // REGISTRATION_H
