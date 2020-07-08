#include <stdio.h>

void expand(char s1[], char s2[])
{
    int j = 0;
    for (int i = 0; s1[i] != '\0'; ++i)
    {
        if (s1[i] == '-')
        {
            char end = s1[++i];
            for (char c = s1[i-2] + 1; c <= end; ++c)
            {
                s2[j++] = c;
            }
        }
        else
        {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}
int main()
{
    char s1[1024] = "a-d-f";
    char s2[1024];
    expand(s1, s2);
    printf("%s\n", s1);
    printf("%s\n", s2);
    return 0;
}
