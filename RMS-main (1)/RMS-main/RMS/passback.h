#ifndef PASSBACK_H
#define PASSBACK_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class passback;
}

class passback : public QDialog
{
    Q_OBJECT

public:

    MainWindow conn;
    explicit passback(QWidget *parent = nullptr);
    ~passback();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_changepass_clicked();

    void on_pushButton_eye_clicked();

    void on_pushButton_ceye_clicked();

private:
    Ui::passback *ui;
};

#endif // PASSBACK_H
