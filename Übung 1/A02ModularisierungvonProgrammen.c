#include <stdio.h> 
#include <math.h>
#include "feldfunktionen.h"
/*Funktionsschnittstellen: intalle_gleich(double*feld,intn);intpruefe_sort(double*feld,intn);doublemax_delta(double*feld,intn);intalle_in_intervall(double*feld,intn,doubleu_grenze,doubleo_grenze);intalle_vz_gleich(double*feld,intn);*/


int main() {

	//Vorschlag für Felddeklarationen und Initialisierungen :
	int rc; // Rückkehrcode
	int n = 4;
	double werte_praktisch_gleich[] = { 9.9995,10.0,10.0002,9.99991 };
	double werte_sort_0123[] = { 0,1,2,3 };
	double werte_unsortiert[] = { 1,3,2,0 };
	double werte_maxabw_0komma1[] = { 1.0,1.05,0.95,1.01 };
	double werte_gleiche_vz[] = { 0,1,2,3 };
	double werte_verschiedene_vz[] = { -1,0,1,2 };

	double einerfeld[1] = { 1 };
	// Prüfen, ob isch die Funtkion richtig verhält
	// 
	//kommt 1 für rc raus	
	/*
	rc = alle_gleich(werte_praktisch_gleich, n);

	printf("rc-%d\n", rc);
	*/

	// info tester - prüfen auf fehlfunktion

	if (alle_gleich(werte_praktisch_gleich, n) != 1 || alle_gleich(einerfeld,1)!=0)
	{
		printf("TEST mit Funktionen alle_gleich() fehlgeschlagen...\n");
		return 0;		// exit fail oder succes
	}

	if (pruefe_sort(werte_sort_0123, n) != 0 || pruefe_sort(werte_unsortiert,n)!=0 || pruefe_sort(einerfeld,1)!=0)
	{
		printf("TEST mit Funktionen alle_gleich() fehlgeschlagen...\n");
		return 0;		// exit fail oder succes
	}

	printf("alle Tests erfolgreich.\n");
	return 0;
}
