// bitlevel1.c
// Das Programm demonstriert die Manipulation einzelner Bits in einem 8-Bit-Wort (uint8_t)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdint.h>

#define STRLEN 20


void set_bit(uint8_t *bits, int pos)
{
	uint8_t mask = 0x01;
	mask=mask<<pos;  // Verschieben der Eins auf Position pos
	*bits |= mask;   // bitweises Oder der Eins auf Position pos   
}
void reset_bit(uint8_t *bits, int pos)
{
	uint8_t mask = 0x01;
	mask = mask<<pos;
	mask = ~mask;   // jetzt alles Einsen, bis auf Stelle i mit 0
	*bits &= mask;  // bitweises UND der 0 auf Position i
}
int isset_bit(uint8_t bits, int pos)
{
  uint8_t result;
  uint8_t mask = 0x01;
  mask=mask<<pos;             // Verschieben der Eins auf Position 
  result = bits & mask;       // bitweises UND von 1 auf Position i  
  if (result != 0)
	  return 1;
  else
	  return 0;
}

void bitwise_display_uchar(uint8_t c)
{
	uint8_t mask = 0x80;

	while (mask)
	{
		if (c & mask)
			printf("1");
		else
			printf("0");
		mask = mask >> 1;
	}
	printf("\n");
}


int main()
{
	char inputstr[STRLEN];
	char choice;
	int pos;

	uint8_t  bitfield = 0x00;  // Ausgangspunkt: kein Bit ist gesetzt

	do {
	  printf("Funktionen: [A]nzeigen [S]etzen [R]uecksetzen [P]ruefen [E]nde ...");
	  do {
		  fgets(inputstr, STRLEN, stdin);
	  } while (sscanf(inputstr, "%c", &choice) != 1);
	  choice = toupper(choice);

	  if (choice=='A') 
		  bitwise_display_uchar(bitfield);

	  if (choice=='S' || choice=='R' || choice=='P' ) 
	  {
        printf("Bitposition:"); 
		do {
			fgets(inputstr, STRLEN, stdin);
		} while( sscanf(inputstr, "%d", &pos)!=1);
		if (pos<0 || pos>7) 
		{ printf("Position fehlerhaft! 0...7 erwartet.\n");
	  	  continue;
		}
		if (choice=='S') 
			set_bit(&bitfield, pos);
		else if (choice=='R')
			reset_bit(&bitfield, pos);
		else
		{
			if (isset_bit(bitfield, pos))
				printf("Bitposition %d ist gesetzt.\n",pos);
			else
				printf("Bitposition %d ist nicht gesetzt.\n", pos);
		}
	  }	  
	  
	} while (choice!='E');

	return 0;
}

