#include <stdio.h>

unsigned rightrot(unsigned x, unsigned n)
{
    unsigned left = x >> n;
    unsigned right = (x & ~(~0 << n)) << (32 - n);
    return left + right;
}
int main()
{
    unsigned a = 0xff;
    unsigned c = rightrot(a, 8);
    printf("%u\n", c);
    return 0;
}
