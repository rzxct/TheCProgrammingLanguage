#include <stdio.h>

int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; ++b)
    {
        x &= (x - 1);
    }
    return b;
}
int main()
{
    printf("%d\n", bitcount(0xF0));
    return 0;
}
