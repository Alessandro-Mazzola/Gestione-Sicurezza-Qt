#include "dialog_add_sensore.h"
#include "ui_dialog_add_sensore.h"
#include <dispositivo/DispositivoSicurezza.h>
#include <dispositivo/SensoreRaggInfrarossi.h>
#include <gestoredispositivo/gestoreDispositivo.h>

Dialog_add_Sensore::Dialog_add_Sensore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add_Sensore)
{
    ui->setupUi(this);
}

Dialog_add_Sensore::~Dialog_add_Sensore()
{
    delete ui;
}


void Dialog_add_Sensore::on_inserisciAllarme_clicked()
{
    std::string n = ui->nome->text().toStdString();
    std::string c = ui->collocamento->text().toStdString();
    if(n.compare("") == 0 || c.compare("") == 0){
        ui->messaggio->setStyleSheet("QLabel{Color:red;}");
        ui->messaggio->setText("ERRORE: inserire tutti i campi!");
    }
    else{
        DispositivoSicurezza* temp = new SensoreRaggInfrarossi(n,false,c);
        ui->elemIns->setText("---- Elemento inserito: ----\n"+QString::fromStdString(temp->toString()));
        GestoreSicurezza::instance().aggiungiDispositivo(temp);
    }
    ui->nome->setText("");
    ui->collocamento->setText("");
}

