#ifndef DIALOG_ADD_TELECAMERA_H
#define DIALOG_ADD_TELECAMERA_H

#include <QDialog>

namespace Ui {
class Dialog_add_Telecamera;
}

class Dialog_add_Telecamera : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_add_Telecamera(QWidget *parent = nullptr);
    ~Dialog_add_Telecamera();

private slots:
    void on_inserisciAllarme_clicked();

private:
    Ui::Dialog_add_Telecamera *ui;
};

#endif // DIALOG_ADD_TELECAMERA_H
