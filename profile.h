#ifndef PROFILE_H
#define PROFILE_H
#include "mainwindow.h"

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
    void on_listWidget_itemSelectionChanged();

private:
    Ui::profile *ui;
};

#endif // PROFILE_H
