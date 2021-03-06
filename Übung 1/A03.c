#include <stdio.h> 
#include <math.h>
/*Funktionsschnittstellen: intalle_gleich(double*feld,intn);intpruefe_sort(double*feld,intn);doublemax_delta(double*feld,intn);intalle_in_intervall(double*feld,intn,doubleu_grenze,doubleo_grenze);intalle_vz_gleich(double*feld,intn);*/

/*
int alle_gleich(double* feld, int n)
{
	int i;
	double min, max;
	if (n < 2)
		return 0;

	max = feld[0];
	min = feld[0];
	for (i = 1; i < n; i++)
	{
		if (feld[i] > max) max = feld[i];
		if (feld[i] < min) min = feld[i];
	}
	if (max - min <= 0.001)	//retun max - min <= 0.001;
		return 1;
	else
		return 0;
}

int pruefe_sort(double* feld, int n)
{
	if (n < 2)
		return 0;
	for (int i = 1; i < n; i++)
	if (feld[i - 1] - feld[i] > 0)
		return 0;

	return 1;
}

double max_delta(double* feld, int n)
{
	int i;
	double min, max;

	if (n < 2)
		return 0.0;

	max = feld[0];
	min = max; //min = feld[0];

	for (i = 1; i < n; i++)
	{
		if (feld[i] > max) max = feld[i];
		if (feld[i] > min) min = feld[i];
	}
	return max - min;

}

/*


for (int m = 0; m < n; m++)
    for (int i = 0; i < n; i++)
        if (fabs(feld[m] - feld[i]) > dif)
            dif = fabs(feld[m] - feld[i]);

 */

/*
int main() {

	//Vorschlag f?r Felddeklarationen und Initialisierungen :
	int rc; // R?ckkehrcode
	int n = 4;
	double werte_praktisch_gleich[] = { 9.9995,10.0,10.0002,9.99991 };
	double werte_sort_0123[] = { 0,1,2,3 };
	double werte_unsortiert[] = { 1,3,2,0 };
	double werte_maxabw_0komma1[] = { 1.0,1.05,0.95,1.01 };
	double werte_gleiche_vz[] = { 0,1,2,3 };
	double werte_verschiedene_vz[] = { -1,0,1,2 };

	double einerfeld[1] = { 1 };

	// Pr?fen, ob isch die Funtkion richtig verh?lt
	//kommt 1 f?r rc raus	
	/*
	rc = alle_gleich(werte_praktisch_gleich, n);

	printf("rc-%d\n", rc);
	*/

	// info tester - pr?fen auf fehlfunktion
/*
	if (alle_gleich(werte_praktisch_gleich, n) != 1 || alle_gleich(einerfeld, 1) != 0)
	{
		printf("TEST mit Funktionen alle_gleich() fehlgeschlagen...\n");
		return 0;		// exit fail oder succes
	}

	if (pruefe_sort(werte_sort_0123, n) != 0 || pruefe_sort(werte_unsortiert, n) != 0 || pruefe_sort(einerfeld, 1) != 0)
	{
		printf("TEST mit Funktionen alle_gleich() fehlgeschlagen...\n");
		return 0;		// exit fail oder succes
	}

	if (fabs(max_delta(werte_maxabw_0komma1, n) -0.1)>1e-15 || max_delta(einerfeld,1)!= 0.0)
	{	//ACHTUNG: > statt <, oben include math.h
		printf("TEST mit Finktion max_delta() fehlgechlagen.\n");
		return 0;
	}

	printf("alle Tests erfolgreich.\n");
	return 0;
}
