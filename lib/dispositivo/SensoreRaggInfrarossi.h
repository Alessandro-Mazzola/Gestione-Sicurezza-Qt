/*
 * SensoreRaggInfrarossi.h
 *
 *  Created on: 15 set 2021
 *      Author: alexm
 */
#ifndef SENSORE_RAGG_INFRAROSSI_H
#define SENSORE_RAGG_INFRAROSSI_H

#include <string>
using namespace std;

#include "DispositivoSicurezza.h"
#include "Produttore.h"

class SensoreRaggInfrarossi: public DispositivoSicurezza {
private:
	double copertura; //[m^3]
public:
	SensoreRaggInfrarossi(string n, bool s, string c, double lato);
	// overload del costruttore
	SensoreRaggInfrarossi(string n, bool s, string c);

	virtual ~SensoreRaggInfrarossi();
	double getCopertura();
	string stampaCheck();
	//override del metodo purevirtual
	virtual string getNomeClasse();
	virtual string toString();

	// utilizzo di template
	template<typename T> double CalcolaArea(T lato);

	//metodo che chiama un campo della classe Produttore
	string stampaModelloProduttore(const Produttore &p);

	static char getTipo();

};
#endif /* SENSORERAGGINFRAROSSI_H_ */
