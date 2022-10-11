#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>

namespace Ui {
class registration;
}

class registration : public QDialog
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = nullptr);
    ~registration();

private slots:
    void on_pushButton_3_clicked();



    void on_toolButton_triggered(QAction *arg1);

private:
    Ui::registration *ui;
};

#endif // REGISTRATION_H
