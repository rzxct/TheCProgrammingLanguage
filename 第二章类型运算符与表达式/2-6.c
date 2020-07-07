#include <stdio.h>

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
    unsigned b = (y & ~(~0 << n)) << (p + 1 - n);
    unsigned a = x & ~((~0 << (p + 1)) ^ (~0 << (p + 1 - n)));
    return a + b;
}
int main()
{
    unsigned a = 678, b = 345; /*0010 1010 0110     0001 0101 1001*/
    printf("%d\t%d\n", a, b);
    unsigned c = setbits(a, 5, 3, b); /*0010 1000 1110*/
    printf("%d\n", c);
    return 0;
}
