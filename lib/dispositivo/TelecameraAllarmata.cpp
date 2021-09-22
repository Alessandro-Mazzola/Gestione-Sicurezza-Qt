/*
 * TelecameraAllarmata.cpp
 *
 *  Created on: 15 set 2021
 *      Author: alexm
 */

#include "../Dispositivo/TelecameraAllarmata.h"

#include <string>
#include <iostream>

#include "Telecamera.h"
using namespace std;


TelecameraAllarmata::TelecameraAllarmata(string n, bool s, string c, int costo, string modello):
		Telecamera(n, s, c, costo, modello), Allarme(n, s, c),
		DispositivoSicurezza(n,s,c,TelecameraAllarmata::getTipo()){

}

TelecameraAllarmata::~TelecameraAllarmata(){
	//cout<<"Distruggo: "<<this->getNome()<<" ..."<<endl;
}

void TelecameraAllarmata::Controllo(){
}


// metodo che mi serve per risolvere il name clash di "Produttore"
string TelecameraAllarmata::getProduttoreTA(){
	return Telecamera::getProprietario();
}
string TelecameraAllarmata::getProprietarioTA(){
	return Allarme::getProprietario();
}

//override del metodo purevirtual
// devo chiamarlo anche qui perchè altrimenti avrei name clash
string TelecameraAllarmata::getNomeClasse(){
		return "TelecameraAllarmata";
	}

string TelecameraAllarmata::toString() {
	return TelecameraAllarmata::getNomeClasse() + ":  " + this->getID()
						+ "\nNome:                 " + this->getNome()
						+ "\nStato Dispositivo:    " + this->stampaStato()
						+ "\nCollocamento:         " + this->getCollocamento()
						+ "\nPoszione:             " + getPosizione()
						+ "\nControllo telecamera: " + this->stampaRilevaMovimento()
						+ "\nModello:              " + getModello()
						+ "\nProprietario:         " + getProprietarioTA();
						+ "\nProduttore:           " + getProduttoreTA();

			;
}


char TelecameraAllarmata::getTipo() {
	return 'p';
}



