#include <stdio.h>

void reverse(char to[], char from[])
{
    int max = 0;
    while (from[max++] != '\0');
    --max;
    to[max--] = '\0';
    for (int j = 0; j <= max; ++j)
    {
        to[j] = from[max-j];
    }
}

void itoa(int n, char s[], int w)
{
    int i = 0, sign = n;
    char s2[1024];
    if (sign < 0)
    {
        n = -n;
    }
    do {
        s2[i++] = n % 10 + '0';
    }while ((n /= 10) > 0);
    if (sign < 0)
    {
        s2[i++] = '-';
    }
    while (i < w)
    {
        s2[i++] = ' ';
    }
    s2[i] = '\0';
    reverse(s, s2);
}
int main()
{
    char s[1024];
    int n = -12345;
    itoa(n, s, 10);
    printf("%s\n", s);
    return 0;
}
