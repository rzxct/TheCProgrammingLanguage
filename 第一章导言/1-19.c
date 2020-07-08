#include <stdio.h>
#define MAXLINE 1000

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
int main()
{
    int len, max = 0;
    char line[MAXLINE], reverse_line[MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0)
    {
        reverse(reverse_line, line);
        printf("%s", reverse_line);
    }
    return 0;
}
