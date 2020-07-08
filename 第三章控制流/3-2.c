#include <stdio.h>

void escape(char s[], char t[])
{
    int i = 0, j = 0;
    for (i = 0; t[i] != '\0'; ++i)
    {
        switch (t[i])
        {
			case '\n': s[j++] = '\\'; s[j++] = 'n'; break;
			case '\t': s[j++] = '\\'; s[j++] = 't'; break;
			default  : s[j++] = t[i]; break;
        }
    }
    s[j] = '\0';
}
void antiEscape(char s[], char t[])
{
    int i = 0, j = 0;
    for (i = 0; t[i] != '\0'; ++i)
    {
        if (t[i] == '\\')
        {
            switch (t[++i])
            {
				case 't': s[j++]='\t'; break;
				case 'n': s[j++]='\n'; break;
            }
        }
        else
        {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}
int main()
{
    char t[1024] = "abcd\tefgh\n";
    char s[1024];
    printf("%s\n", t);
    escape(s, t);
    printf("%s\n", s);
    antiEscape(t, s);
    printf("%s\n", t);
    return 0;
}
