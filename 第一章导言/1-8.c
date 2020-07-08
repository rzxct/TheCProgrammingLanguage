#include <stdio.h>

int main()
{
    unsigned int num_of_space = 0, num_of_tabs = 0, num_of_linebreak = 0;
    int ch;
    while ((ch = getchar()) != EOF)
    {
        switch (ch)
        {
            case ' ' : ++num_of_space;     break;
            case '\t': ++num_of_tabs;      break;
            case '\n': ++num_of_linebreak; break;
			default  : break;
        }
    }
    printf("num of space:%d\n", num_of_space);
    printf("num of tabs:%d\n", num_of_tabs);
    printf("num of linebreak:%d\n", num_of_linebreak);
    return 0;
}