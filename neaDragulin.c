#include <stdio.h>

unsigned suma_cifrelor(unsigned n)
{
	unsigned  sc = 0;

	while (n != 0) { sc += n % 10; n /= 10; }

	return sc;
}

unsigned short sufix_din_trei_cifre(unsigned n, unsigned k)
{
	if (n > 99 && n < 1000) return n;

	if (n > 999) return (n/100%10*100 + n/10%10*10 + n%10);

	while (n < 100 && k > 1) {
		n = n > 9 ? n*100 + n : n*10 + n;
		k--;
	}
	
	if (n > 999) return sufix_din_trei_cifre(n, 1);

	return n;
}

int main()
{
	unsigned n, k;
	unsigned short r1, r2;
	short R;

	scanf("%u %u", &n, &k);
	
	r1 = (unsigned long long)suma_cifrelor(n) * k % 9;

	r2 = sufix_din_trei_cifre(n, k) % 8;

	R = 9*r2 - 8*r1;

	if (R < 0) R += 72;

	printf("%hu", R);

	return 0;
}
// scor 100
