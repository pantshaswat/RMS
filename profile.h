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

    void on_pushButton_6_clicked();

    void on_right_arrow_2_clicked();

    void on_hamburger_clicked();

    void on_pushButton_dashboard_clicked();

    void on_pushButton_editProfile_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_passupdate_clicked();

    void on_hamburgerButton_clicked();

    void on_pushButton_EditProfile_clicked();

    void on_pushButton_editProfile_2_clicked();

private:
    Ui::profile *ui;
    QSqlDatabase mydb;
};

#endif // PROFILE_H
