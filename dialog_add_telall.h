#ifndef DIALOG_ADD_TELALL_H
#define DIALOG_ADD_TELALL_H

#include <QDialog>

namespace Ui {
class Dialog_add_TelAll;
}

class Dialog_add_TelAll : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_add_TelAll(QWidget *parent = nullptr);
    ~Dialog_add_TelAll();

private slots:
    void on_inserisciAllarme_clicked();

private:
    Ui::Dialog_add_TelAll *ui;
};

#endif // DIALOG_ADD_TELALL_H
