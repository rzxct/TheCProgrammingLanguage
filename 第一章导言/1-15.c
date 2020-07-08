#include <stdio.h>

int convert(int fahr)
{
    return 5 * (fahr - 32) / 9;
}

int main()
{
    int fahr, celsius;
    int lower = 0, upper = 300, step = 20;
    fahr = lower;
    printf("Temperature conversion program\n");
    while (fahr <= upper)
    {
        celsius = convert(fahr);
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}
