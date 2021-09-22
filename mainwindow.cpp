#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <gestoredispositivo/gestoreDispositivo.h>
#include <dispositivo/Allarme.h>
#include <dispositivo/SensoreRaggInfrarossi.h>
#include <dispositivo/Telecamera.h>
#include <dispositivo/TelecameraAllarmata.h>




#include <dispositivo/Telecamera.h>
#include <dialog_add_allarme.h>
#include <dialog_add_sensore.h>
#include <dialog_add_telecamera.h>
#include <dialog_add_telall.h>

#include <qprocess.h>
#include <iostream>
#include <sstream>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GestoreSicurezza::instance();



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_aggTelecamera_clicked()
{
    unique_ptr<Dialog_add_Telecamera> dialog_telecamera (new Dialog_add_Telecamera());
    dialog_telecamera->setModal(true);
    dialog_telecamera->setWindowTitle("Aggiungi telecamera");
    dialog_telecamera->exec();
    dialog_telecamera->close();
    on_visualizza_clicked();
}


void MainWindow::on_aggAllarme_clicked()
{
    unique_ptr<Dialog_add_Allarme> dialog_allarme (new Dialog_add_Allarme());
    //Dialog_add_Allarme dialog_allarme;
    dialog_allarme->setModal(true);
    dialog_allarme->setWindowTitle("Aggiungi allarme");
    dialog_allarme->exec();
    dialog_allarme->close();
    on_visualizza_clicked();

}

void MainWindow::on_aggSensore_clicked()
{
    unique_ptr<Dialog_add_Sensore> dialog_sensore (new Dialog_add_Sensore());
    dialog_sensore->setModal(true);
    dialog_sensore->setWindowTitle("Aggiungi sensore");
    dialog_sensore->exec();
    dialog_sensore->close();
    on_visualizza_clicked();

}

void MainWindow::on_aggTelAll_clicked()
{
    unique_ptr<Dialog_add_TelAll> dialog_telall (new Dialog_add_TelAll());
    dialog_telall->setModal(true);
    dialog_telall->setWindowTitle("Aggiungi sensore");
    dialog_telall->exec();
    dialog_telall->close();
    on_visualizza_clicked();

}

void MainWindow::on_visualizza_clicked()
{
    //il metodo stampaDispositiviTutti è un metodo void che stampa i dispositivi.
    //quello che faccio ora è leggo dall'output e vado a stamparlo

    //il buffer serve per mettere momentanemante la stringa in una varaibile temporaena
    stringstream buffer;
    cout.rdbuf(buffer.rdbuf());

    GestoreSicurezza::instance().stampaDispositiviTotali();
    //trasformo il testo in una stringa
    std::string testo = buffer.str();

    ui->visDispositivi->setText(QString::fromStdString(testo));
}

void MainWindow::on_visualizzaAccesi_clicked()
{
    stringstream buffer;
    cout.rdbuf(buffer.rdbuf());

    GestoreSicurezza::instance().stampaDispositiviAccesi();
    //trasformo il testo in una stringa
    std::string testo = buffer.str();

    ui->visDispositivi->setText(QString::fromStdString(testo));
}


void MainWindow::on_elimDispositivo_clicked()
{
    std::string id = ui->id_elimina->text().toStdString();
    ui->id_elimina->setText("");
    if(id.compare("") == 0){
        ui->messaggio->setStyleSheet("QLabel{Color:orange;}");
        ui->messaggio->setText("Errore: inserire l'id prima di elimanre!");
    }
    else{
       DispositivoSicurezza* temp = GestoreSicurezza::instance().cercaOggetto(id);
       if(temp==NULL){
           ui->messaggio->setStyleSheet("QLabel{Color:red;}");
           ui->messaggio->setText("Dispositivo non trovato");
       }
       else{
           ui->messaggio->setStyleSheet("QLabel{Color:green;}");
           ui->messaggio->setText("Dispositivo eliminato correttamente");
           GestoreSicurezza::instance().rimuoviDispositivoID(id);
       }
       on_visualizza_clicked();
    }
}


void MainWindow::on_accendi_clicked()
{
    std::string id = ui->id_accendi->text().toStdString();
    ui->id_accendi->setText("");
    if(id.compare("") == 0){
        ui->messaggio->setStyleSheet("QLabel{Color:orange;}");
        ui->messaggio->setText("Errore: inserire l'id prima di accendere!");
    }
    else{
       DispositivoSicurezza* temp = GestoreSicurezza::instance().cercaOggetto(id);
       if(temp==NULL){
           ui->messaggio->setStyleSheet("QLabel{Color:red;}");
           ui->messaggio->setText("Dispositivo non trovato");
       }
       else{
           ui->messaggio->setStyleSheet("QLabel{Color:green;}");
           ui->messaggio->setText("Dispositivo acceso correttamente");
           GestoreSicurezza::instance().accendiDispositivo(id);
       }
       on_visualizza_clicked();
    }
}


void MainWindow::on_spegni_clicked()
{
    std::string id = ui->id_spegni->text().toStdString();
    ui->id_spegni->setText("");
    if(id.compare("") == 0){
        ui->messaggio->setStyleSheet("QLabel{Color:orange;}");
        ui->messaggio->setText("Errore: inserire l'id prima di spegnere!");
    }
    else{
       DispositivoSicurezza* temp = GestoreSicurezza::instance().cercaOggetto(id);
       if(temp==NULL){
           ui->messaggio->setStyleSheet("QLabel{Color:red;}");
           ui->messaggio->setText("Dispositivo non trovato");
       }
       else{
           ui->messaggio->setStyleSheet("QLabel{Color:green;}");
           ui->messaggio->setText("Dispositivo spento correttamente");
           GestoreSicurezza::instance().SpegniDispositivo(id);
       }
       on_visualizza_clicked();
   }
}


void MainWindow::on_aggiungiDati_clicked()
{
    //aggiungo dati fittizzi per
    GestoreSicurezza::instance().aggiungiDispositivo(new Allarme("allarme1",false,"cucina"));
    GestoreSicurezza::instance().aggiungiDispositivo(new Telecamera("telecamera1",true,"box",199,"sony"));
    GestoreSicurezza::instance().aggiungiDispositivo(new SensoreRaggInfrarossi("Sensore1",false,"sala"));
    GestoreSicurezza::instance().aggiungiDispositivo(new TelecameraAllarmata("TArmadio",true,"camera",85,"ericcson"));
    on_visualizza_clicked();
}


void MainWindow::on_simulaMovimento_clicked()
{
    std::string id = ui->id_simula->text().toStdString();
    ui->id_simula->setText("");
    if(id.compare("") == 0){
        ui->messaggio->setStyleSheet("QLabel{Color:orange;}");
        ui->messaggio->setText("Errore: inserire l'id prima di simulare!");
    }
    else{
       DispositivoSicurezza* temp = GestoreSicurezza::instance().cercaOggetto(id);
       if(temp==NULL){
           ui->messaggio->setStyleSheet("QLabel{Color:red;}");
           ui->messaggio->setText("Dispositivo non trovato");
       }
       else{
           ui->messaggio->setStyleSheet("QLabel{Color:green;}");
           ui->messaggio->setText("Dispositivo simulato correttamente");
           GestoreSicurezza::instance().SegnalaMovimento(id);
       }
       on_visualizza_clicked();
   }
}
