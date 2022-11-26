#ifndef PROFILE_H
#define PROFILE_H

#include <QtSql>
#include<QtDebug>
#include<QFileInfo>

#include <QDialog>

namespace Ui {
class profile;
}

class profile : public QDialog
{
    Q_OBJECT

public:

    explicit profile(QWidget *parent = nullptr);
    ~profile();

private slots:



    void on_pushButton_clicked();

    void on_commandLinkButton_clicked();

    void on_pushButton_10_clicked();

    void on_right_arrow_clicked();

    void on_left_arrow_clicked();

private:
    Ui::profile *ui;
    QSqlDatabase mydb;
};

#endif // PROFILE_H
