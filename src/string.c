#include <stdio.h>
#include "string.h"

unsigned int
stk_strlen(char *string)
{
    char *size = string;

    while(*size++ != '\0');
    return size - string - 1;
}

void
stk_strcpy(char *dst, char *src)
{
	while(*src != '\0')
		*dst++ = *src++;

	*dst = '\0';
}

void
stk_strncpy(char *dst, char *src, unsigned int size)
{
    for(unsigned int i = 0; i < size; ++i)
        *dst++ = *src++;

    *dst = '\0';
}

void
stk_strcat(char *dst, char *src)
{
    while(*src++ != '\0');

    stk_strcpy(src, dst);
    return;
}

void
stk_strncat(char *dst, char *src, unsigned int size)
{
    while(*src++ != '\0');

    stk_strncpy(src, dst, size);
    return;
}

int
stk_strcmp(char *first, char *second)
{
    int ret = -1; // ERROR
    while(*first != '\0' && *second != '\0')
    {
        if(*first++ != *second++)
        {
            ret = 0; // FALSE
            break;
        }
        else
            ret = 1; // TRUE
    }

    return ret;
}

int
stk_strncmp(char *first, char *second, unsigned int size)
{
    int ret = -1; // ERROR

    for(unsigned int i = 0; i < size; ++i)
    {
        if(*first++ != *second++)
        {
            ret = 0; // FALSE
            break;
        }
        else
            ret = 1; // TRUE
    }
    return ret;
}

char *
stk_strchr(char *string, char target)
{
    while(*string++ != target);
    return string-1;
}

char *
stk_strrchr(char *string, char target)
{
    unsigned int i;

    for(i = stk_strlen(string); i >= 0; --i)
    {
        if(string[i] == target)
			break;
    }
    return string+i;
}
