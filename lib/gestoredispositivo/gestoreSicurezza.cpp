/*
 * gestoreDispositivo.cpp
 *
 *  Created on: 16 set 2021
 *      Author: alexm
 */

#include "gestoreDispositivo.h"
//#include "../Dispositivo/Allarme.h"
//#include "../Dispositivo/SensoreRaggInfrarossi.h"
//#include "../Dispositivo/Telecamera.h"
//#include "../Dispositivo/TelecameraAllarmata.h"
//#include "../Dispositivo/DispositivoSicurezza.h"

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

GestoreSicurezza::GestoreSicurezza() {
}

GestoreSicurezza& GestoreSicurezza::instance() {
	//istanziazione
	static GestoreSicurezza INSTANCE;
	return INSTANCE;
}

GestoreSicurezza::~GestoreSicurezza() {
}

vector<DispositivoSicurezza*> GestoreSicurezza::getvettDispositivi() {
	return vettDispositivi;
}


DispositivoSicurezza* GestoreSicurezza::cercaOggetto(string s){
	DispositivoSicurezza* temp;
	for (std::vector<DispositivoSicurezza*>::iterator it = vettDispositivi.begin(); it != vettDispositivi.end(); ++it)
			if ((*it)->getID() == s){
				temp = *it;
				return temp;
				break;
			}
			return NULL;
}

void GestoreSicurezza::aggiungiDispositivo(DispositivoSicurezza *d) {
	vettDispositivi.push_back(d);
}

void GestoreSicurezza::rimuoviDispositivoID(string s) {
	vector<DispositivoSicurezza*>::iterator i = find(vettDispositivi.begin(),vettDispositivi.end(), cercaOggetto(s));
	if(i!=vettDispositivi.end()){
		delete(*i);
		vettDispositivi.erase(i);
	}
	else
		cout<<"**errore, dispositivo non trovato**"<<endl;
}

void GestoreSicurezza::rimuoviDispositivo(DispositivoSicurezza *d) {
	vector<DispositivoSicurezza*>::iterator i = find(vettDispositivi.begin(),vettDispositivi.end(), d);
	if(i!=vettDispositivi.end()){
			delete(*i);
			vettDispositivi.erase(i);
	}
	else
			cout<<"**errore: dispositivo non trovato**"<<endl;
}

void GestoreSicurezza::accendiDispositivo(string s) {
	vector<DispositivoSicurezza*>::iterator i = find(vettDispositivi.begin(),vettDispositivi.end(), cercaOggetto(s));
			(*i)->accendi();
}

void GestoreSicurezza::SpegniDispositivo(string s) {
	vector<DispositivoSicurezza*>::iterator i = find(vettDispositivi.begin(),vettDispositivi.end(), cercaOggetto(s));
			(*i)->spegni();
}

void GestoreSicurezza::SegnalaMovimento(string s){
	vector<DispositivoSicurezza*>::iterator i = find(vettDispositivi.begin(),vettDispositivi.end(), cercaOggetto(s));
		if((*i)->getStatoDispositivo())
			(*i)->setRilevaMovimento();
		else
			cout<<"** è necessario accendere il dispositivo!**"<<endl;

}


void GestoreSicurezza::spegniDispositivi() {
	for (std::vector<DispositivoSicurezza*>::iterator it = vettDispositivi.begin(); it != vettDispositivi.end(); ++it) {
		(*it)->spegni();
	}

}

void GestoreSicurezza::stampaDispositiviTotali() {
	for (std::vector<DispositivoSicurezza*>::iterator it = vettDispositivi.begin(); it != vettDispositivi.end(); ++it){
		cout << (*it)->toString() << endl << endl;
		cout<<"----------------------------------------------------"<<endl;
}
}

void GestoreSicurezza::stampaDispositiviAccesi() {
	for (std::vector<DispositivoSicurezza*>::iterator it = vettDispositivi.begin(); it != vettDispositivi.end(); ++it) {
		if ((*it)->getStatoDispositivo()){
			cout << (*it)->toString() << endl << endl;
			cout<<"----------------------------------------------------"<<endl;
		}

	}
}

// metodi che vanno a chiamare i metodi dei vari dispositivi di sicurezza

void GestoreSicurezza::AemettiSuono(string s){
	vector<DispositivoSicurezza*>::iterator i = find(vettDispositivi.begin(),vettDispositivi.end(), cercaOggetto(s));
		if ((*i)->getStatoDispositivo()){
			Allarme* temp = dynamic_cast<Allarme*>(*i);
				temp->emettiSuono();
		}
		else
			cout<<"**errore: dispositivo non trovato, oppure dispositivo spento**"<<endl;
	}
