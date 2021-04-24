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

int main()
{
	uint8_t a = 0xFF;
	uint16_t b = 0xAFFE;
	uint32_t c = 0xCAFEAFFE;
	uint32_t op1, op2, r;
	int v;

	bitwise_display_uint8(a);
	bitwise_display_uint16(b);
	bitwise_display_uint32(c);


	// Oktalkonstante
	printf("\nNutzung einer Oktalkonstante: uint32_t ok = 0131; ...\n");
	uint32_t ok = 0131;
	printf("Dualdarstellung von ok:"); bitwise_display_uint32(ok);
	printf("Dezimalwert von ok: %d\n", ok);


	printf("\nEinerkomplement:\n");
	printf(" AFFE :"); bitwise_display_uint16(b);
	uint16_t bek = ~b;
	printf("~AFFE :"); bitwise_display_uint16(bek);

	op1 = 0xAFFE000C;
	op2 = 0xCAFE0ADA;

	printf("\nBitweises UND:\n");
	r = op1 & op2;
	bitwise_display_uint32(op1);
	bitwise_display_uint32(op2);
	printf("---- bitweises & -----\n");
	bitwise_display_uint32(r);

	printf("\nBitweises ODER:\n");
	r = op1 | op2;
	bitwise_display_uint32(op1);
	bitwise_display_uint32(op2);
	printf("---- bitweises | -----\n");
	bitwise_display_uint32(r);


	printf("\nBitweises XOR:\n");
	r = op1 ^ op2;
	bitwise_display_uint32(op1);
	bitwise_display_uint32(op2);
	printf("---- bitweises ^ -----\n");
	bitwise_display_uint32(r);


	// Berechnung 42-24 mit Bitop.
	op1 = 42; op2 = 24;
	r = op1 + (~op2 + 1);
	printf("\nSubtraktion: %d - %d ergibt %d\n", op1, op2, r);


	printf("Multiplikation und Division:\n");
	op1 = 42;
	v = 2;
	r = op1 << v;
	printf("\n%d * (2 hoch %d) ergibt %d\n", op1, v, r);
	r = op1 >> v;
	printf("\n%d / (2 hoch %d) ergibt %d\n", op1, v, r);


	printf("\nTausch per XOR, ohne dritte Variable: \n");
	op1 = 100; op2 = 42;
	printf("Vorher ..... op1:%d, op2:%d\n", op1, op2);
	op1 = op1 ^ op2;
	op2 = op1 ^ op2;
	op1 = op2 ^ op1;
	printf("Nachher ..... op1:%d, op2:%d\n", op1, op2);

	return 0;
}