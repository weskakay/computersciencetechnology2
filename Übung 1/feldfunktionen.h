#pragma once

//pr�ft ob alle Elemente nicht mehr als 0.001 voneinander abweichen
//r�ckgabe 1 wenn Eigenschaften erf�llt, 0 anderenfalls
// bei n<2 wird 0 zur�ckgegebn

int alle_gleich(double* feld, int n);

int pruefe_sort(double* feld, int n);

double max_delta(double* feld, int n);
