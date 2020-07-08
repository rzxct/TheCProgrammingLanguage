#include <stdio.h>
#define MAXLINE 1000
#define TAB 4
int getline(char s[], int maxline)
{
    int c, i;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = (char)c;
    }
    if (c == '\n')
    {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';
    return i;
}
void detab(char to[], char from[])
{
    int j = 0;
    for (int i = 0; from[i] != '\0'; ++i)
    {
        if (from[i] != '\t')
        {
            to[j++] = from[i];
        }
        else
        {
            for (int k = 0; k < TAB; ++k)
            {
                to[j++] = ' ';
            }
        }
    }
    to[j] = '\0';
}
int main()
{
    int len;
    char line[MAXLINE], detab_line[MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0)
    {
        detab(detab_line, line);
        printf("%s", detab_line);
    }
    return 0;
}
