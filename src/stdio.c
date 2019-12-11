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
			// TODO: %c, %b, %h
			switch (fmt[++i]) {
			case 's': {

				char *tmp = va_arg(phrase_list, char *);
				write(STDOUT_FILENO, tmp, stk_strlen(tmp));

				break;
			}

			case 'c': {

				char tmp = va_arg(phrase_list, int);
				write(STDOUT_FILENO, &tmp, sizeof(char));

				break;
			}

			case 'd': {

				//int num = va_arg(phrase_list, int);
				write(STDOUT_FILENO, "STUB", 4);

				break;
			}

			case 'b': {

				int n = va_arg(phrase_list, int);

				if(n <= 0) write(STDOUT_FILENO, "0000000", 8);

				int i = 7;
				char buf[8];

				while(i >= 0)
				{
					if(n & 1) buf[i--] = '1';
					else	  buf[i--] = '0';

					n >>= 1;
				}

				write(STDOUT_FILENO, buf, 8);
				break;
			}

			case '%':
				write(STDERR_FILENO, "%", 1);
				break;

			default:
				write(STDOUT_FILENO, fmt+i, 1);
				break;
			}
		}
		else
			write(STDOUT_FILENO, fmt+i, 1);
	}

	va_end(phrase_list);
}
