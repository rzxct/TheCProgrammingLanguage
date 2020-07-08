#include <stdio.h>
int main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\'')
        {
            putchar(c);
            putchar(c = getchar());
            if (c == '\\')
            {
                putchar(getchar());
            }
            putchar(getchar());
        }
		/*AZdasfsa*/
        else if (c == '\"')
        {
            putchar(c);
            while (1)
            {
                putchar(c = getchar());
                if (c == '\\')
                {
                    putchar(getchar());
                }
                else if (c == '\"')
                {
                    break;
                }
            }
        }
        else if (c == '/')
        {
            getchar();
            while (1)
            {
                if (c == '*')
                {
                    if ((c = getchar()) == '/')
                    {
                        break;
                    }
                }
                else
                {
                    c = getchar();
                }
            }
        }
        else
        {
            putchar(c);
        }
    }
    return 0;
}
