/*
 * Produttore.cpp
 *
 *  Created on: 15 set 2021
 *      Author: alexm
 */

#include "Produttore.h"

#include <string>
#include <iostream>

using namespace std;
//utilizzo di initializer list e campo facoltativo
Produttore::Produttore(int c, string m, bool e):costo(c),modello(m),exist(e) {}

Produttore::~Produttore(){

}

string Produttore::getModello(){
	return this->modello;
}



