#include "scrapingc.h"

char *embedf(char *source, ...)
{
	char *str;
	char **s;
	int i;
	int j;
	int len_args;

	len_args = 0;
	i = 0;
	j = 0;
	va_list vl;

	va_start(vl, source);
	while(source[i])
		if(source[i++] == '%') j++;
	s = malloc(j * sizeof(char *));
	i = 0;
	while (i < j)
	{
		str = va_arg(vl, char *);
		len_args += strlen(str);
		s[i] = strdup(str);
		if(!s[i++]) 
			return (NULL);
	}
	va_end(vl);
	str = NULL;
	 str = calloc(strlen(source) - (j * 2) + len_args + 1, sizeof(char));
	str[0] = '\0';
	i = 0;
	j = 0;
	while(*source)
	{
		if (*source && *source != '%')
			str[i++] = *source++;
		if (*source == '%')
		{
			source++;
			source++;
			strcat(str, s[j++]);
			i = strlen(str);
		}
	}
	str[i] = '\0';
	while (j > 0) free(s[--j]);
	free(s);
	return (str);
}