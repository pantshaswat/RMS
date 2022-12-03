#ifndef PASSBACKUP_H
#define PASSBACKUP_H

#include <QDialog>

namespace Ui {
class passbackup;
}

class passbackup : public QDialog
{
    Q_OBJECT

public:
    explicit passbackup(QWidget *parent = nullptr);
    ~passbackup();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::passbackup *ui;
};

#endif // PASSBACKUP_H
