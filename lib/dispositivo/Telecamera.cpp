/*
 * Telecamera.cpp
 *
 *  Created on: 15 set 2021
 *      Author: alexm
 */

#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

#include "Telecamera.h"

Telecamera::Telecamera(string n, bool s, string c, int costo, string modello) :
		DispositivoSicurezza(n, s, c, Telecamera::getTipo()), Produttore(costo, modello){
	proprietario = "Nessuno";
	posizione = Nord;
}

Telecamera::Telecamera(string n, bool s, string c, Posizione pos, int costo, string modello) :
		DispositivoSicurezza(n, s, c, Telecamera::getTipo()), Produttore(costo, modello) {
	proprietario = "Nessuno";
	posizione = pos;
}

Telecamera::Telecamera(string n, bool s, string c, Posizione pos, string pro, int costo, string modello) :
		DispositivoSicurezza(n, s, c, Telecamera::getTipo()), Produttore(costo, modello) {
	proprietario = pro;
	posizione = pos;
}

Telecamera::~Telecamera() {
	//cout<<"Distruggo: "<<this->getNome()<<" ..."<<endl;
}
string Telecamera::getPosizione() {
	switch(this->posizione){
	case Nord: return "Nord";
	case Sud: return "Sud";
	case Est: return "Est";
	case Ovest: return "Ovest";
	default: return "errore";

	}
}

string Telecamera::getProprietario() {
	return this->proprietario;
}

//override del metodo purevirtual
string Telecamera::getNomeClasse() {
	return "Telecamera";
}

string Telecamera::toString() {
	return Telecamera::getNomeClasse() + " :        " + this->getID()
			+ "\nNome:                 " + this->getNome()
			+ "\nStato Dispositivo:    " + this->stampaStato()
			+ "\nCollocamento:         " + this->getCollocamento()
			+ "\nPoszione:             " + getPosizione()
			+ "\nControllo telecamera: " + this->stampaRilevaMovimento()
			+ "\nModello:              " + getModello()
			+ "\nProprietario:         " + proprietario;
}
char Telecamera::getTipo(){
		return 't';
	}

