#ifndef DASHBOARD_1_H
#define DASHBOARD_1_H

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

private:
    Ui::dashboard_1 *ui;
};

#endif // DASHBOARD_1_H
