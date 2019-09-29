#include <stdlib.h>
#include "string.h"

size_t stk_strlen(char *string)
{
	size_t i = 0;
	for(i = 0; string[i] != '\0'; ++i);
	return i;
}
