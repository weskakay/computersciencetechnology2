#include <stdio.h>
#include <stdint.h>

void bitwise_display_uint8(uint8_t c)
{
	uint8_t maske = 0x80;

	while (maske)
	{
		if (c & maske)
			printf("1");
		else
			printf("0");
		maske = maske >> 1;
	}
	printf("\n");
}

void bitwise_display_uint16(uint16_t s)
{
	uint16_t maske = 0x8000;

	while (maske)
	{
		if (s & maske)
			printf("1");
		else
			printf("0");
		maske = maske >> 1;
	}
	printf("\n");
}

void bitwise_display_uint32(uint32_t w)
{
	uint32_t maske = 0x80000000;

	while (maske)
	{
		if (w & maske)
			printf("1");
		else
			printf("0");
		maske = maske >> 1;
	}
	printf("\n");
}
// Funktionen Übernommen aus Programm bitlevel2_stdint.c

int main()
{
	// Theoretisch im Kopf lösen
	// a 0000 0000
	// Deklaration einer Variable, geeigneten Datentyp wählen
	// unsigned int a = 0x0;
	uint8_t a = 0x00;
	bitwise_display_uint8(a);// Konsole: 00000000
	printf("entpricht Hexadezimal %02x\n", a);


	// b 0001 1100
	// unsigned int b = 0x1C;
	uint8_t b = 0x1C; // alternativ auch Zuweisung einer Dezimalzahl b =28;
	bitwise_display_uint8(b);// Konsole: 00011100
	printf("entpricht Hexadezimal %02x\n", b);

	// c 1100 1111
	// unsigned int c = 0xCF;
	uint8_t c = 0xCF;
	bitwise_display_uint8(c);// Konsole: 11001111
	printf("entpricht Hexadezimal %02x\n", c);

	// d 1010 1111 1111 101
	// unsigned int d = 0xAFFA;
	uint16_t d = 0xAFFA;
	bitwise_display_uint16(d);// Konsole: ...affa
	printf("entpricht Hexadezimal %04x\n", d);

	// e 0000 0000 1000 1110 0111 0001 0000 0000
	// unsigned int e = 0x8E7100;
	uint32_t e = 0x008E7100;
	bitwise_display_uint32(e);// Konsole: 0x8E7100
	printf("entpricht Hexadezimal %08x\n", e);
}