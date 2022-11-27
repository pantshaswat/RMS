#ifndef DASHBOARD_1_H
#define DASHBOARD_1_H
// database connection
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

#include <QDialog>

namespace Ui {
class dashboard_1;
}

class dashboard_1 : public QDialog
{
    Q_OBJECT

public:
    explicit dashboard_1(QWidget *parent = nullptr);
    ~dashboard_1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dashboard_1 *ui;
    QSqlDatabase mydb;
};

#endif // DASHBOARD_1_H
