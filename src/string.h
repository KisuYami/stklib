#ifndef STK_LIB_SORT
#define STK_LIB_SORT

unsigned int
stk_strlen(char *string);

int
stk_strcmp(char *first, char *second);

int
stk_strncmp(char *first, char *second, unsigned int size);

void
stk_strcpy(char *dst, char *src);

void
stk_strncpy(char *dst, char *src, unsigned int size);

void
stk_strcat(char *dst, char *src);

void
stk_strncat(char *dst, char *src, unsigned int size);

char *
stk_strchr(char *string, char target);

char *
stk_strrchr(char *string, char target);

int
stk_stoi(char *value);
#endif
