/*
 * Allarme.cpp
 *
 *  Created on: 15 set 2021
 *      Author: alexm
 */

#include "Allarme.h"

#include <string>
#include <iostream>
using namespace std;

Allarme::Allarme(string n, bool s, string c) :
		DispositivoSicurezza(n, s, c, Allarme::getTipo()) {
	proprietario = "Nessuno";
}

Allarme::Allarme(string n, bool s, string c, string prop) :
		DispositivoSicurezza(n, s, c, Allarme::getTipo()) {
	proprietario = prop;
}

void Allarme::emettiSuono(){
	cout<<"*!*!*!*STO SUONANDO*!*!*!*!*!*"<<endl;
}

Allarme::~Allarme() {
	//cout<<"Distruggo: "<<this->getNome()<<" ..."<<endl;
}

string Allarme::getProprietario() {
	return proprietario;
}

//override del metodo purevirtual
string Allarme::getNomeClasse() {
	return "Allarme";
}
string Allarme::toString() {
	return Allarme::getNomeClasse() + " :          " + this->getID()
			+ "\nNome:              " + this->getNome()
			+ "\nStato Dispositivo: " + this->stampaStato()
			+ "\nCollocamento:      " + this->getCollocamento()
			+ "\nControllo allarme: " + this->stampaRilevaMovimento()
			+ "\nProprietario:      "+ getProprietario();
}

char Allarme::getTipo() {
	return 'a';
}

