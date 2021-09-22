#ifndef DIALOG_ADD_SENSORE_H
#define DIALOG_ADD_SENSORE_H

#include <QDialog>

namespace Ui {
class Dialog_add_Sensore;
}

class Dialog_add_Sensore : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_add_Sensore(QWidget *parent = nullptr);
    ~Dialog_add_Sensore();

private slots:
    void on_inserisciAllarme_clicked();

private:
    Ui::Dialog_add_Sensore *ui;
};

#endif // DIALOG_ADD_SENSORE_H
