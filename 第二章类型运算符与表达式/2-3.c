#include <stdio.h>

int htoi(char s[])
{
    int num = 0, begin = 0;
    for(int i = 0; s[i] != '\0'; ++i)
    {
        if(begin == 1)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                num = num * 16 + (s[i] - '0');
            }
            else if (s[i] >= 'a' && s[i] <= 'f')
            {
                num = num * 16 + (s[i] - 'a') + 10;
            }
            else if (s[i] >= 'A' && s[i] <= 'F')
            {
                num = num * 16 + (s[i] - 'A') + 10;
            }
        }
        else if((s[i] == 'x' || s[i] == 'X') && s[i-1] == '0')
        {
            begin = 1;
        }
    }
    return num;
}

int main()
{
    char hex[1024];
    int i, c;
    for(i = 0; i < 1023 && (c = getchar()) != '\n' && c != EOF; ++i)
    {
        hex[i] = (char)c;
    }
    hex[i] = '\0';
    printf("%d", htoi(hex));
    return 0;
}
