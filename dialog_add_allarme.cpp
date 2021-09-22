#include "dialog_add_allarme.h"
#include "ui_dialog_add_allarme.h"
#include <dialog_add_allarme.h>
#include <dispositivo/DispositivoSicurezza.h>
#include <dispositivo/Allarme.h>
#include <dialog_add_sensore.h>
#include <dialog_add_telecamera.h>
#include <gestoredispositivo/gestoreDispositivo.h>


Dialog_add_Allarme::Dialog_add_Allarme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add_Allarme)
{
    ui->setupUi(this);
    GestoreSicurezza::instance();

}

Dialog_add_Allarme::~Dialog_add_Allarme()
{
    delete ui;

}


void Dialog_add_Allarme::on_inserisciAllarme_clicked()
{
    std::string n = ui->nome->text().toStdString();
    std::string c = ui->collocamento->text().toStdString();
    if(n.compare("") == 0 || c.compare("") == 0){
        ui->messaggio->setStyleSheet("QLabel{Color:red;}");
        ui->messaggio->setText("ERRORE: inserire tutti i campi!");
    }
    else{
        DispositivoSicurezza* temp = new Allarme(n,false,c);
        ui->elemIns->setText("---- Elemento inserito: ----\n"+QString::fromStdString(temp->toString()));
        GestoreSicurezza::instance().aggiungiDispositivo(temp);
    }
    ui->nome->setText("");
    ui->collocamento->setText("");
}

