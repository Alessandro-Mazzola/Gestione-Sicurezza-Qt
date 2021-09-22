/*
 * Allarme.h
 *
 *  Created on: 15 set 2021
 *      Author: alexm
 */
#ifndef ALLARME_H
#define ALLARME_H

#include <string>
using namespace std;

#include "../Dispositivo/DispositivoSicurezza.h"

class Allarme: virtual public DispositivoSicurezza {
public:
	string proprietario;

public:
	//costruttori (con overload costruttore) + distruttore
	Allarme(string n, bool s, string c);
	Allarme(string n, bool s, string c, string prop);
	virtual ~Allarme();

	//metodo che mi avvisa che l'allarme è scattato
	string getProprietario();
	void emettiSuono();

	//override del metodo pure virtual
	virtual string getNomeClasse();
	virtual string toString();

	static char getTipo();

};

#endif
