/*
 * SesnoriRaggInfrarossi.cpp
 *
 *  Created on: 15 set 2021
 *      Author: alexm
 */
#include <string>
#include <iostream>

#include "SensoreRaggInfrarossi.h"
using namespace std;

SensoreRaggInfrarossi::SensoreRaggInfrarossi(string n, bool s, string c) :
		DispositivoSicurezza(n, s, c, SensoreRaggInfrarossi::getTipo()) {
	copertura = CalcolaArea(5);
}

SensoreRaggInfrarossi::SensoreRaggInfrarossi(string n, bool s, string c,
		double lato) :
		DispositivoSicurezza(n, s, c, SensoreRaggInfrarossi::getTipo()) {
	copertura = CalcolaArea(lato);

}

SensoreRaggInfrarossi::~SensoreRaggInfrarossi() {
	//cout<<"Distruggo: "<<this->getNome()<<" ..."<<endl;
}

double SensoreRaggInfrarossi::getCopertura() {
	return copertura;
}

//override del metodo purevirtual
string SensoreRaggInfrarossi::getNomeClasse() {
	return "SesnoriRaggInfrarossi";
}

string SensoreRaggInfrarossi::toString() {
	return SensoreRaggInfrarossi::getNomeClasse() + " : " + this->getID()
			+ "\nNome:                   " + this->getNome()
			+ "\nStato Dispositivo:      " + this->stampaStato()
			+ "\nCollocamento:           " + this->getCollocamento()
			+ "\nControllo sensore:      " + this->stampaRilevaMovimento()
			+ "\nCopertura:              " + to_string(getCopertura());
}

// utilizzo di template
template<typename T> double SensoreRaggInfrarossi::CalcolaArea(T lato) {
	double temp = lato * 3;
	return temp;
}

// metodo che chiama modello della classe produttore
string SensoreRaggInfrarossi::stampaModelloProduttore(const Produttore &p) {
	return p.modello;
}

char SensoreRaggInfrarossi::getTipo() {
	return 's';
}

