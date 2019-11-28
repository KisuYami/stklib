#include "string.h"
#include "sort.h"
int stk_sort_alphanum(const void *p1, const void *p2)
{
    return stk_strcmp(*(char *const *)p1, *(char *const *)p2);
}
