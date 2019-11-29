#include <stdarg.h>
#include <unistd.h>
#include "string.h"
#include "stdio.h"

void
stk_printf(char *fmt, ...)
{
    va_list phrase_list;

    va_start(phrase_list, fmt);

    for(int i = 0; fmt[i] != '\0'; ++i)
	{
		if(fmt[i] == '%')
		{
			switch (fmt[++i]) {
			case 's': {

				char *tmp = va_arg(phrase_list, char *);
				write(STDOUT_FILENO, &tmp, stk_strlen(tmp));

				break;
			}
			case 'd': {

				int tmp = va_arg(phrase_list, int);
				write(STDOUT_FILENO, &tmp, 1);

				break;
				
			}
				
			}
		}
		else
			write(STDOUT_FILENO, fmt+i, 1);
	}

    va_end(phrase_list);
}
