#include <stdio.h>

int main()
{
    int ch, b = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch == ' ')
        {
            if (b == 0)
            {
                putchar(ch);
                b = 1;
            }
        }
        else
        {
            putchar(ch);
            b = 0;
        }
    }
    return 0;
}
