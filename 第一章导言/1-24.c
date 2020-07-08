#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#define YES 1
#define NO 0;

int apostropheProcess(char *str, int i)
{
    if (str[i+1] == '\\' && str[i+3] == '\'')
    {
        str[i] = str[i+1] = str[i+2] = str[i+3] = ' ';
        return i + 3;
    }
    else if (str[i+2] == '\'')
    {
        str[i] = str[i+1] = str[i+2] = ' ';
        return i + 2;
    }
    else
    {
        return -1;
    }
}

int doublequotesProcess(char *str, int i)
{
    int j = i;
    while (str[++j] != '\n')
    {
        if (str[j] == '\"' && str[j-1] != '\\')
        {
            for (; i <= j; ++i)
            {
                str[i] = ' ';
            }
            return j;
        }
    }
    if (str[j] == '\n')
    {
        return -1;
    }
}

int commentProcess(char *str, int i)
{
    int j = i;
    if (str[++j] != '*')
    {
        return -1;
    }
    else
    {
        while (str[++j] != '\0')
        {
            if (str[j] == '/' && str[j-1] == '*')
            {
                for (; i <= j; ++i)
                {
                    str[i]=' ';
                }
                return j;
            }
        }
        if (str[j] == '\0')
        {
            for (; i < j; ++i)
            {
                str[i] = ' ';
            }
            return j - 1;
        }
    }
}

int parenthesesProcess(char *str, int i)
{
    int j = i;
    while (str[++j] != '\0')
    {
        if (str[j] == ')')
        {
            for (; i <= j; ++i)
            {
                str[i] = ' ';
            }
            return j;
        }
        else if (str[j] == '{' || str[j] == '}' || str[j] == ']')
        {
            return -1;
        }
        else if (str[j] == '(')
        {
            int order = parenthesesProcess(str, j);
            if (order == -1)
            {
                return -1;
            }
            else
            {
                j = order;
            }
        }
        else if (str[j] == '[')
        {
            int order = squarebracketsProcess(str, j);
            if (order == -1)
            {
                return -1;
            }
            else
            {
                j = order;
            }
        }
    }
    if (str[j] == '\0')
    {
        return -1;
    }
}

int squarebracketsProcess(char *str, int i)
{
    int j = i;
    while (str[++j] != '\0')
    {
        if (str[j] == ']')
        {
            for (; i <= j; ++i)
            {
                str[i] = ' ';
            }
            return j;
        }
        else if (str[j] == '{' || str[j] == '}' || str[j] == ')')
        {
            return -1;
        }
        else if (str[j] == '(')
        {
            int order = parenthesesProcess(str, j);
            if (order == -1)
            {
                return -1;
            }
            else
            {
                j = order;
            }
        }
        else if (str[j] == '[')
        {
            int order = squarebracketsProcess(str, j);
            if (order == -1)
            {
                return -1;
            }
            else
            {
                j = order;
            }
        }
    }
    if (str[j] == '\0')
    {
        return -1;
    }
}

int curlybracesProcess(char *str, int i)
{
    int j = i;
    while (str[++j] != '\0')
    {
        if (str[j] == '}')
        {
            for (; i <= j; ++i)
            {
                str[i] = ' ';
            }
            return j;
        }
        else if (str[j] == '{')
        {
            int order = curlybracesProcess(str, j);
            if (order == -1)
            {
                return -1;
            }
            else
            {
                j = order;
            }
        }
    }
    if (str[j] == '\0')
    {
        return -1;
    }
}

void errorProcess(char str[], int lineNums[], int i)
{
    for (int j = 0; ; ++j)
    {
        if (i < lineNums[j])
        {
            char result[1024];
            strncpy(result, &str[lineNums[j-1]], lineNums[j] - lineNums[j-1] - 1);
            printf("error:line %d,\t%s", j, result);
            exit(0);
        }
    }
}

int main()
{
    char str[USHRT_MAX];
    char str2[USHRT_MAX];
    int lineNums[1024];
    for (unsigned i=0; i < 1024; ++i)
    {
        lineNums[i] = 0;
    }
    char line[1024];
    while (gets(line) != NULL)
    {
        strcat(str, line);
        strcat(str, "\n");
    }
    unsigned lineNum = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == '\n')
        {
            lineNums[lineNum++] = i + 1;
        }
    }
    strcpy(str2, str);
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == '\'')
        {
            int order = apostropheProcess(str, i);
            if (order == -1)
            {
                errorProcess(str2, lineNums, i);
            }
            else
            {
                i = order;
            }
        }
        else if (str[i] == '\"')
        {
            int order = doublequotesProcess(str, i);
            if (order == -1)
            {
                errorProcess(str2, lineNums, i);
            }
            else
            {
                i = order;
            }
        }
        else if (str[i] == '/')
        {
            int order = commentProcess(str, i);
            if (order == -1)
            {
                errorProcess(str2, lineNums, i);
            }
            else
            {
                i = order;
            }
        }
    }
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == ']' || str[i] == ')')
        {
            errorProcess(str2, lineNums, i);
        }
        else if (str[i] == '(')
        {
            int order = parenthesesProcess(str, i);
            if (order == -1)
            {
                errorProcess(str2, lineNums, i);
            }
            else
            {
                i = order;
            }
        }
        else if (str[i] == '[')
        {
            int order = squarebracketsProcess(str, i);
            if (order == -1)
            {
                errorProcess(str2, lineNums, i);
            }
            else
            {
                i = order;
            }
        }
    }
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == '}')
        {
            errorProcess(str2, lineNums, i);
        }
        else if (str[i] == '{')
        {
            int order = curlybracesProcess(str, i);
            if (order == -1)
            {
                errorProcess(str2, lineNums, i);
            }
            else
            {
                i = order;
            }
        }
    }
    return 0;
}
