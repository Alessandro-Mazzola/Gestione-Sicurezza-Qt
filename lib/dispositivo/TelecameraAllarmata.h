/*
 * TelecameraAllarmata.h
 *
 *  Created on: 15 set 2021
 *      Author: alexm
 */

#ifndef TELECAMERAALLARMATA_H_
#define TELECAMERAALLARMATA_H_

#include <string>

#include "String.h"

#include "Allarme.h"
#include "Telecamera.h"
using namespace std;

class TelecameraAllarmata : public Telecamera, public Allarme
{
public:
	TelecameraAllarmata(string n, bool s, string c, int costo, string modello);
	~TelecameraAllarmata();

	// metodo che controlla il campo rilevaMovimento, se è a true fa partire l'allarme
	void Controllo();
	string getProduttoreTA();
	string getProprietarioTA();

	//implemento metodo astratto super classe
	string getNomeClasse();
	string toString();


	static char getTipo();

};




#endif /* TELECAMERAALLARMATA_H_ */
