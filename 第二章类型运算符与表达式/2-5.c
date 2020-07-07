#include <stdio.h>

int any(char s1[], char s2[])
{
    int i, j, k;
    for(i = j = 0; s1[i] != '\0'; ++i)
    {
        for (k = 0; s2[k] != '\0'; ++k)
        {
            if (s1[i] == s2[k])
            {
                return i;
            }
        }
    }
    return -1;
}
int main()
{
    char s1[1024], s2[1024];
    printf("Please enter s1 string:");
    scanf("%s", s1);
    printf("Please enter s2 string:");
    scanf("%s", s2);
    printf("%s\t%s\n", s1, s2);
    int position = any(s1, s2);
    if (position == -1)
    {
        printf("s2 did not appear in s1");
    }
    else
    {
        printf("s2 appears in the %d position of s1", position);
    }
    return 0;
}
