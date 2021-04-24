#include <stdio.h>
#include <malloc.h> 
#include <stdlib.h>

#define MAX_NAME_LEN 50
#define N 20

struct student {
	unsigned int nummer;
	char name[MAX_NAME_LEN];
};

typedef struct student student_t;

int element_vergleich(const void* p1, const void* p2)
{
	student_t *sp1, *sp2;
	sp1 = (student_t*)p1;
	sp2 = (student_t*)p2;

	if (sp1->nummer < sp2->nummer)
		return -1;
	else  if (sp1->nummer > sp2->nummer)
		return 1;
	else
		return 0;
}

void sortiere(student_t* f, int n)
{
	qsort(f, n, sizeof(student_t), element_vergleich);
}

int main()
{
	student_t feld[N] = { {59112, "Peter Lustig"}, {45181, "Fritz Fuchs"}, {38984, "Bibi Blocksberg"},
						  {87191, "Bernd Brot"}, {58731, "Katie Sommer"}, {75442, "Hein Klug"} };
	int n = 6;   // Anzahl benutzter Elemente im Feld

	printf("Das Feld kann %d Elemente aufnehmen. Davon werden %d Elemente benutzt.\n", N , n);

	// Fügen Sie Ihre Lösungen für die Teilaufgaben ein!

	return 0;
}