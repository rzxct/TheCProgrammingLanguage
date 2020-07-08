#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int maxline)
{
    int c, i;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
            s[i] = (char)c;
    }
    for (--i; i >= 0; --i)
    {
        if (s[i] != ' ' && s[i] != '\t')
        {
            if (c == '\n')
            {
                s[++i] = '\n';
            }
            s[++i] = '\0';
            break;
        }
    }
    if (i == -1 && (c == '\n' || s[0] == ' ' || s[0] == '\t'))
    {
        i = getline(s, MAXLINE);
    }
    return i;
}

int main()
{
    int len;
    char line[MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0)
    {
        printf("%d\t%s", len, line);
    }
    return 0;
}
