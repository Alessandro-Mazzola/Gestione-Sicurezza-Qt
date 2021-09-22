#ifndef DIALOG_ADD_ALLARME_H
#define DIALOG_ADD_ALLARME_H
#include <dispositivo/DispositivoSicurezza.h>
#include <QDialog>

namespace Ui {
class Dialog_add_Allarme;
}

class Dialog_add_Allarme : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_add_Allarme(QWidget *parent = nullptr);
    ~Dialog_add_Allarme();

private slots:
    void on_inserisciAllarme_clicked();

private:
    Ui::Dialog_add_Allarme *ui;
};

#endif // DIALOG_ADD_ALLARME_H
