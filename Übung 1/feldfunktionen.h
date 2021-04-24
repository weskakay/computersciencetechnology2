#pragma once

//prüft ob alle Elemente nicht mehr als 0.001 voneinander abweichen
//rückgabe 1 wenn Eigenschaften erfüllt, 0 anderenfalls
// bei n<2 wird 0 zurückgegebn

int alle_gleich(double* feld, int n);

int pruefe_sort(double* feld, int n);

double max_delta(double* feld, int n);
