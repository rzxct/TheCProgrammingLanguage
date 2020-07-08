#include <stdio.h>
#include <ctype.h>
void plot(unsigned int *num, size_t length, unsigned int align)
{
	for (size_t i = length - 1; i >= 0; --i)
	{
		if (num[i] != 0)
		{
			length = i + 1;
			break;
		}
	}
    if (align == 1)
    {
        for (unsigned i = 0; i < length; ++i)
        {
            printf("  %c", 124);
            for (unsigned j = 0; j < num[i]; ++j)
            {
                putchar(95);
            }
            printf("\n%2u%c", i, 124);
            if (num[i] > 0)
            {
                for (unsigned j = 0; j < num[i]; ++j)
                {
                    putchar(' ');
                }
                putchar(124);
            }
            printf("%d\n  %c", num[i], 124);
            if (num[i] > 0)
            {
                for (unsigned j = 0; j < num[i]; ++j)
                {
                    putchar(95);
                }
                putchar(124);
            }
            printf("\n");
        }
    }
    else if (align == 0)
    {
        unsigned max = 0;
        for (unsigned i = 0; i < length; ++i)
        {
            if (max < num[i])
            {
                max = num[i];
            }
        }
        for (unsigned i = max; i > 0; --i)
        {
            printf("%2d%c", i, 124);
            for (unsigned j=0; j < length; ++j)
            {
                printf("  ");
                if (num[j] == i)
                {
                    printf("____");
                }
                else if (num[j] > i)
                {
                    printf("%c  %c", 124, 124);
                }
                else
                {
                    printf("    ");
                }
            }
            putchar('\n');
        }
        printf("   ");
        for (unsigned j = 0; j < length; ++j)
        {
            printf("------");
        }
        printf("\n   ");
        for (unsigned j = 0; j < length; ++j)
        {
            printf("   %2d ", j + 1);
        }
    }
}
int main()
{
    int c, length = 0, state = 1;
    unsigned int num[40];
    for (unsigned i = 0; i < 40; ++i)
    {
        num[i] = 0;
    }
    while ((c = getchar()) != EOF)
    {
		if (!isalpha(c))
        {
            if (state == 0)
            {
                --length;
                if (length >= 39)
                {
                    ++num[39];
                }
                else
                {
                    ++num[length];
                }
                length = 0;
                state = 1;
            }
        }
        else
        {
            ++length;
            state=0;
        }
    }
    plot(num, sizeof (num) / sizeof (num[0]), 1);
    return 0;
}
