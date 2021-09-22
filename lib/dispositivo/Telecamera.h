/*
 * Telecamera.h
 *
 *  Created on: 15 set 2021
 *      Author: alexm
 */
#ifndef TELECAMERA_H
#define TELECAMERA_H

#include <string>
using namespace std;

#include "DispositivoSicurezza.h"
#include "Produttore.h"
#include "Posizione.h"

class Telecamera : virtual public DispositivoSicurezza, private Produttore{
private:
	Posizione posizione;
	string proprietario;


public:
	// costruttori (con overload del costruttore) + distruttore
	Telecamera(string n, bool s, string c, int costo, string modello);
	Telecamera(string n, bool s, string c, Posizione pos, int costo, string modello);
	Telecamera(string n, bool s, string c, Posizione pos, string pro, int costo, string modello);
	virtual ~Telecamera();


	string getPosizione();
	bool getRilevaMovimento();
	string getProprietario();

	//metodo reso pubblico dopo aver ereditato la classe in modo privato
	using Produttore::getModello;

	//override del metodo purevirtual
	virtual string getNomeClasse();
	virtual string toString();

	static char getTipo();


};
#endif/* TELECAMERA_H */
