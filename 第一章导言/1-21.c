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
void entab(char to[], char from[])
{
    int j = 0, sum = 0;
    for (int i = 0; from[i] != '\0'; ++i)
    {
        if (from[i] != ' ' && from[i] != '\t')
        {
            to[j++] = from[i];
        }
        else
        {
            for (; from[i] != '\0'; ++i)
            {
                if (from[i] == ' ')
                {
                    sum += 1;
                }
                else if (from[i] == '\t')
                {
                    sum += TAB;
                }
                else
                {
                    --i;
                    break;
                }
            }
            for (int k = 0; k < sum / TAB; ++k)
            {
                to[j++] = '\t';
            }
            for (int k = 0; k < sum % TAB; ++k)
            {
                to[j++] = ' ';
            }
            sum = 0;
        }
    }
    to[j] = '\0';
}
int main()
{
    int len;
    char line[MAXLINE], entab_line[MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0)
    {
        entab(entab_line, line);
        printf("%s", entab_line);
    }
    return 0;
}
