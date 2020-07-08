#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int maxline)
{
    int c, i;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (i < maxline - 1)
        {
            s[i] = (char)c;
        }
    }
    if (c == '\n')
    {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';
    s[maxline - 1] = '\0';
    return i;
}
int main()
{
    int len;
    char line[MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > 80)
        {
            printf("%s", line);
        }
    }
    return 0;
}
