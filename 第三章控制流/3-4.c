#include <stdio.h>
#include <limits.h>
void reverse(char to[], char from[])
{
    int max = 0;
    while (from[max++] != '\0');
    --max;
    to[max--] = '\0';
    for(int j = 0; j <= max; ++j)
    {
        to[j] = from[max-j];
    }
}

void itoa(int n, char s[])
{
    int i = 0, sign = n;
    char s2[1024];
	if (n == INT_MIN)
	{
		itoa(n + 1, s);
		while (s[i++] != '\0');
		s[i-2] += 1;
		return;
	}
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
    s2[i] = '\0';
    reverse(s, s2);
}

int main()
{
    char s[1024];
    int n = INT_MIN;
    itoa(n, s);
    printf("%s\n", s);
    return 0;
}
