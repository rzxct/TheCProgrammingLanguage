#include <stdio.h>
#define IN  1
#define OUT 0
int main()
{
    int c, state;
    while ((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            if(state == IN)
            {
                putchar('\n');
                state = OUT;
            }
        }
        else
        {
            putchar(c);
            state = IN;
        }
    }
    return 0;
}
