#include "header.h"

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
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
