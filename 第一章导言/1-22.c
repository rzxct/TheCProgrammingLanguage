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
void split(char from[])
{
    int sum = 0, begin = 0, end = 0;
    for (int i = 0; from[i] != '\0' && from[i] != '\n'; ++i)
    {
        if (from[i] == '\t')
        {
            sum += TAB;
        }
        else
        {
            ++sum;
        }
        if (sum >= 32)
        {
            if (end == begin)
            {
                end = i;
            }
            for (int j = begin; j <= end; ++j)
            {
                putchar(from[j]);
            }
            putchar('\n');
            sum = 0;
            for (int j = end + 1; ; ++j)
            {
                if (from[j] == '\0' || from[j] == '\n')
                {
                    --i;
                    break;
                }
                if (from[j] != '\t' && from[j] != ' ')
                {
                    begin = end = i = j;
                    break;
                }
            }
        }
        if (from[i] == '\t' || from[i] == ' ')
        {
            end = i - 1;
        }
    }
    for (int i = begin; from[i] != '\0'; ++i)
    {
        putchar(from[i]);
    }
}
int main()
{
    int len;
    char line[MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0)
    {
        split(line);
    }
    return 0;
}
