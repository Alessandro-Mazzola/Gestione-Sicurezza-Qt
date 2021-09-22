/*
 * GestoreDispositivo.h
 *
 *  Created on: 16 set 2021
 *      Author: alexm
 */

#ifndef GESTOREDISPOSITIVO_H_
#define GESTOREDISPOSITIVO_H_

#include <string>
#include <vector>
#include "../Dispositivo/DispositivoSicurezza.h"
#include "../Dispositivo/Allarme.h"
#include "../Dispositivo/SensoreRaggInfrarossi.h"
#include "../Dispositivo/Telecamera.h"
#include "../Dispositivo/TelecameraAllarmata.h"
using namespace std;

class GestoreSicurezza {
private:
	vector<DispositivoSicurezza*> vettDispositivi;
	GestoreSicurezza();

public:

	//implemento singleton
	static GestoreSicurezza& instance();
	//distruttore
	~GestoreSicurezza();

	//mi assicuro che l'unica istanza della classe che posso usare è proprio istance
	GestoreSicurezza(GestoreSicurezza const&) = delete;
	void operator=(GestoreSicurezza const&) = delete;

	vector<DispositivoSicurezza*> getvettDispositivi();

	DispositivoSicurezza* cercaOggetto(string s);

	void aggiungiDispositivo(DispositivoSicurezza *d);
	void rimuoviDispositivoID(string s);
	void rimuoviDispositivo(DispositivoSicurezza *d);

	void accendiDispositivo(string s);
	void SpegniDispositivo(string s);

	void SegnalaMovimento(string s);


	void spegniDispositivi();
	void stampaDispositiviTotali();
	void stampaDispositiviAccesi();

	//vado a chiamare un metodo che esiste solo in allarme tramite il cast dinamico
	void AemettiSuono(string s);




};

#endif /* GESTOREDISPOSITIVO_H_ */
