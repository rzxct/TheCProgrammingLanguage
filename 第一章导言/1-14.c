#include <stdio.h>
#include <ctype.h>

void plot(unsigned int *num, size_t length, unsigned int align)
{
    if (align == 1)
    {
        for (unsigned i = 0; i < length; ++i)
        {
            printf("  %c", 124);
            for (unsigned j = 0; j < num[i]; ++j)
            {
                putchar(95);
            }
            printf("\n%c %c", 97 + i, 124);
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
            for (unsigned j = 0; j < length; ++j)
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
            printf("   %c  ", j + 97);
        }
    }
}

int main()
{
    int c;
    unsigned int num[26];
    for (unsigned i = 0; i < 26; ++i)
    {
        num[i] = 0;
    }
    while ((c = getchar()) != EOF)
    {
        if (isalpha(c))
        {
            ++num[tolower(c) - 97];
        }
    }
    plot(num, sizeof (num) / sizeof (num[0]), 0);
    return 0;
}
