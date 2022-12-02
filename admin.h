#ifndef ADMIN_H
#define ADMIN_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    MainWindow conn;
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(int index);
    void display();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::admin *ui;
    QString table1;
    int id = 000;
    int value=0,value_routine = 0,value_day=0,value_time=0;  //checks whether the input for update table is provided'

};

#endif // ADMIN_H
