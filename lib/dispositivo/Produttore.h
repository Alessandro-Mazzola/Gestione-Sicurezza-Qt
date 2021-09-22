/*
 * Produttore.h
 *
 *  Created on: 15 set 2021
 *      Author: alexm
 */
#ifndef PRODUTTORE_H
#define PRODUTTORE_H

#include <string>
using namespace std;

class Produttore {
private:
	int costo;
	string modello;
	bool exist;

public:
	Produttore(int c, string m, bool e=true);
	virtual ~Produttore();
	string getModello();
	friend class SensoreRaggInfrarossi;

};
#endif
