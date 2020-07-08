#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
size_t strlen(char *s)
{
	if (s == NULL)
	{
		return 0;
	}
	size_t i = 0;
	while (s[i] != '\0')
	{
		++i;
	}
	return i;
}
char *getline()
{
	unsigned length = 1;
	char *s = (char*)calloc(length, sizeof(char));
	int c, i;
	for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i )
	{
		if(i == length)
		{
			length = length * 2;
			s = (char*)realloc(s, length);
		}
		s[i] = c;
	}
	if(c == '\n')
	{
		if(i == length)
		{
			length = length * 2;
			s = (char*)realloc(s, length);
		}
		s[i] = c;
		++i;
	}
	if(i == length)
	{
		length = length * 2;
		s = (char*)realloc(s, length);
	}
	s[i] = '\0';
	if(c == EOF && s[0] == '\0')
	{
		return NULL;
	}
	return s;
}
int main()
{
    int len, max = 0;
    char *line;
	char *longest = NULL;
    while ((line = getline()) != NULL)
    {
		if (strlen(line) > strlen(longest))
		{
			free(longest);
			longest = line;
		}
		else
		{
			free(line);
		}
    }
    printf("%s", longest);
    return 0;
}