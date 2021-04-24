#include "feldfunktionen.h"

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