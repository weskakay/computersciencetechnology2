#define _CRT_SECURE_NO_WARNINGS
#define EINGABEDATEINAME "C:\Users\weska\Dropbox\Elektro-und Informationstechnik\HTWD\2 Semester_SS20\Informatik II\Informatik_II_Sobe_2021\Übung 21\Übung 3\ein.txt"
#define AUSGABEDATEINAME "C:\Users\weska\Dropbox\Elektro-und Informationstechnik\HTWD\2 Semester_SS20\Informatik II\Informatik_II_Sobe_2021\Übung 21\Übung 3\aus.txt"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f_ein, *f_aus;
	char c;
	int v = v;

	f_ein = fopen(EINGABEDATEINAME, "rt");
	if (f_ein == NULL)
	{
		printf("Fehler beim Oeffnen der Datei %s\n", EINGABEDATEINAME);
		return EXIT_FAILURE;
	}

	f_aus = fopen(AUSGABEDATEINAME, "wt");
	if (f_aus == NULL)
	{
		printf("Fehler beim Oeffnen der Datei %s\n", AUSGABEDATEINAME);
		return EXIT_FAILURE;
	}

	printf("Zeichenweise Uebertragung von %s nach %s\n",
		   EINGABEDATEINAME, AUSGABEDATEINAME);

	while (!feof(f_ein))
	{
		// einzelnes carackter einlesen
		c = fgetc(f_ein);
		if (c != EOF)
		{
			// Platz fuer Ihre Erweiterung

			// wie verschieben wir das Alphabet c = c + verschiebung
			c = (c + v) % 256;
			
			fputc(c, f_aus);
		}
	}
	fclose(f_ein);
	fclose(f_aus);
	// Entschlüsseln
	// öffnen der vorab geschriebenenn ( verschlüsselten Datei)
	// zeichenweises Lesen , Verschiebung Zeichen um -v
	// Ausgaben auf eine weitere Datei , bspweise pruef.txt

	return EXIT_SUCCESS;  // Rueckgabe Wert 0
}