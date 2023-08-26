#include <stdio.h>

unsigned suma_cifrelor(unsigned n)
{
	unsigned  sc = 0;

	while (n != 0) {
		sc += n % 10;
		n /= 10;
	}

	return sc;
}

unsigned short sufix_din_trei_cifre(unsigned n)
{
	char cifra_sutelor, cifra_zecilor, cifra_unitatilor;

	if (n < 100) return 0;

	if (n < 1000) return n;

	cifra_sutelor = n / 100 % 10;

	cifra_zecilor = n / 10 % 10;

	cifra_unitatilor = n % 10;

	return cifra_sutelor * 100 + cifra_zecilor * 10 + cifra_unitatilor;
}

int main()
{
	unsigned n, k, r1, r2, sufix;

	scanf("%u %u", &n, &k);

	r1 = (suma_cifrelor(n) * k) % 9;

	sufix = sufix_din_trei_cifre(n);

	if (sufix == 0) {
		if (n < 10 && k > 2)
			sufix = n * 100 + n * 10 + n;
		else if (n < 100 && k > 1)
		       	sufix = sufix_din_trei_cifre(n * 100 + n);
		else 
			sufix = n;
	}

	r2 = sufix % 8;

	printf("%u", 9 * r2 - 8 * r1);

	return 0;
}

// scor 60
