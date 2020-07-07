#include <stdio.h>

unsigned invert(unsigned x, unsigned p, unsigned n)
{
    return x ^ ((~0 << (p + 1)) ^ (~0 << (p + 1 - n)));
}
int main()
{
    unsigned a = 678; /*0010 1010 0110*/
    unsigned c = invert(a, 5, 3); /*0010 1001 1110*/
    printf("%d\n", c);
    return 0;
}
