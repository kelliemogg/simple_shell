#include "header.h"


int _strcmp(char *s1, char *s2)
{
        for (; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
        {
                if (*s1 != *s2)
                {
                        return (*s1 - *s2);
                }
        }
	return (0);
}


int stringlength(char *s)
{
        int i;

        for (i = 0; s[i] != '\0'; i++)
        {}
	return (i);
}


char *_strdup(char *str)
{
        char *duplicate;
        int i;
        int len = 0;

        if (str == NULL)
                return (NULL);

        for (len = 0; str[len] != '\0'; len++)
                ;
        duplicate = malloc((len + 1) * sizeof(char));

        if (duplicate == NULL)
                return (NULL);

        for (i = 0; str[i] != '\0'; i++)
                duplicate[i] = str[i];


        return (duplicate);
}

int _putchar(char c)
{
        return (write(1, &c, 1));
}
