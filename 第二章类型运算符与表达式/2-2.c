#include <stdio.h>

int getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1; ++i)
    {
        if ((c = getchar()) == '\n')
        {
            break;
        }
        else if (c == EOF)
        {
            break;
        }
        else
        {
            s[i] = (char)c;
        }
    }
    if (c == '\n')
    {
        s[i++] = '\n';
    }
    s[i] = '\0';
    return i;
}
int main()
{
    char str[1024];
    while (getline(str, 1024) > 0)
    {
        printf("%s", str);
    }
    return 0;
}
