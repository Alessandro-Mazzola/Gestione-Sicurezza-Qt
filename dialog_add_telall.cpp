#include "dialog_add_telall.h"
#include "ui_dialog_add_telall.h"
#include <dispositivo/DispositivoSicurezza.h>
#include <dispositivo/TelecameraAllarmata.h>
#include <gestoredispositivo/gestoreDispositivo.h>

Dialog_add_TelAll::Dialog_add_TelAll(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add_TelAll)
{
    ui->setupUi(this);
}

Dialog_add_TelAll::~Dialog_add_TelAll()
{
    delete ui;
}

void Dialog_add_TelAll::on_inserisciAllarme_clicked()
{
    std::string n = ui->nome->text().toStdString();
    std::string c = ui->collocamento->text().toStdString();
    std::string costo = ui->costo->text().toStdString();
    std::string mod = ui->modello->text().toStdString();

    if(n.compare("") == 0 || c.compare("") == 0 || costo.compare("") == 0 || mod.compare("") == 0){
        ui->messaggio->setStyleSheet("QLabel{Color:red;}");
        ui->messaggio->setText("ERRORE: inserire tutti i campi!");
    }
    else{
        DispositivoSicurezza* temp = new TelecameraAllarmata(n,false,c, std::stoi(costo),mod);
        ui->elemIns->setText("---- Elemento inserito: ----\n"+QString::fromStdString(temp->toString()));
        GestoreSicurezza::instance().aggiungiDispositivo(temp);
    }
    ui->nome->setText("");
    ui->collocamento->setText("");
    ui->costo->setText("");
    ui->modello->setText("");
}

