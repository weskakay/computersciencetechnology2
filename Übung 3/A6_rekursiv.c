#include <stdio.h>

//iterativ
int element_finde_index(int* feld, int n, int suchwert)
{
	// bin�re Suche, iterativ
	// https://de.wikipedia.org/wiki/Bin%C3%A4re_Suche
	int li, re, mi; // links,rechts,mitte

	li = 0;
	re = n - 1;

	// .... Zyklus ...

	while (li <= re)
	{
		mi = (li + re) / 2;
		if (feld[mi] == suchwert)
			return mi;
		else
		{
			if (feld[mi] < suchwert)
				// Intervallgrenzen so verschieben, dass rechts von Mitte weitergesucht wird
				li = mi + 1;
			else // hier ist das feld[mi]>suchwert
				// Intervallgrenzen so verschieben, dass links von Mitte weitergesucht wird
				re = mi - 1;
		}
	}
	return -1;

}

// rekursiv - keine zyklen
int element_finde_index_rekursiv(int* feld, int li, int re, int suchwert)
{
	int mi;
	if (li <= re)
	{
		mi = (li + re) / 2;
		if (feld[mi] == suchwert)
			return mi;
		else
		{
			if (feld[mi] < suchwert)
				return element_finde_index_rekursiv(feld, mi + 1, re, suchwert);
			else
				return element_finde_index_rekursiv(feld, li, mi - 1, suchwert);

		}
	}
	else
		return -1;
}

int main(void)
{
	int nummernfeld[] = { 1,3,4,6,8,9,12,17 };
	unsigned anz_elemente = 8; // Anzahl Elemente

	int pos, such;
	for (such = -1; such <= 20; such++)
	{
		// iterative
		// pos = element_finde_index(nummernfeld, anz_elemente, such);
		// rekursive
		pos = element_finde_index_rekursiv(nummernfeld, 0, anz_elemente-1, such);

		if (pos >= 0)
			print("Wert %d gefunden an Indexposition %d\n", such, pos);
		else
			print("Wert %d nicht enthalten.\n", such);
	}
	return 0;
}

