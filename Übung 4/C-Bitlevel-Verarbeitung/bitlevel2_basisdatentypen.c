#include <stdio.h>

void bitwise_display_uchar(unsigned char c)
{
	unsigned char maske = 0x80;

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

void bitwise_display_ushort(unsigned short s)
{
	unsigned short maske = 0x8000;

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

void bitwise_display_uint(unsigned int w)
{
	unsigned int maske = 0x80000000;

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
	unsigned char a = 0xFF;
	unsigned short b = 0xAFFE;
	unsigned int c = 0xCAFEAFFE;
	unsigned int op1, op2, r;
	int v;

	bitwise_display_uchar(a);
	bitwise_display_ushort(b);
	bitwise_display_uint(c);


	// Oktalkonstante
	printf("Nutzung einer Oktalkonstante: unsigned int ok = 0131; ...\n");
	unsigned int ok = 0131;
	printf("Dualdarstellung von ok:"); bitwise_display_uint(ok);
	printf("Dezimalwert von ok: %d\n", ok);


	printf("Einerkomplement:\n");
	printf(" AFFE :"); bitwise_display_ushort(b);
	unsigned short bek = ~b;
	printf("~AFFE :"); bitwise_display_ushort(bek);

	op1 = 0xAFFE000C;
	op2 = 0xCAFE0ADA;

	printf("Bitweises UND:\n");
	r = op1 & op2;
	bitwise_display_uint(op1);
	bitwise_display_uint(op2);
	printf("---- bitweises & -----\n");
	bitwise_display_uint(r);

	printf("Bitweises ODER:\n");
	r = op1 | op2;
	bitwise_display_uint(op1);
	bitwise_display_uint(op2);
	printf("---- bitweises | -----\n");
	bitwise_display_uint(r);


	printf("Bitweises XOR:\n");
	r = op1 ^ op2;
	bitwise_display_uint(op1);
	bitwise_display_uint(op2);
	printf("---- bitweises ^ -----\n");
	bitwise_display_uint(r);


	// Berechnung 42-24 mit Bitop.
	op1 = 42; op2 = 24;
	r = op1 + (~op2 + 1);
	printf("Subtraktion: %d - %d ergibt %d\n", op1, op2, r);


	printf("Multiplikation und Division:\n");
	op1 = 42;
	v = 2;
	r = op1 << v;
	printf("%d * (2 hoch %d) ergibt %d\n", op1, v, r);
	r = op1 >> v;
	printf("%d / (2 hoch %d) ergibt %d\n", op1, v, r);


	printf("Tausch per XOR, ohne dritte Variable: \n");
	op1 = 100; op2 = 42;
	printf("Vorher ..... op1:%d, op2:%d\n", op1, op2);
	op1 = op1 ^ op2;
	op2 = op1 ^ op2;
	op1 = op2 ^ op1;
	printf("Nachher ..... op1:%d, op2:%d\n", op1, op2);

	return 0;
}