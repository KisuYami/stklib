#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include "stklib.h"

char **stk_list_files(char *dir_path)
{
    size_t i = 0;
	size_t dir_size = 0;
	char **dest = NULL, **tmp_ptr = NULL;

    DIR *d = NULL;
    struct dirent *dir = NULL;

	dir_size = 10;
	d = opendir(dir_path);
	dir = readdir(d);

	dest = malloc(sizeof(char **) * 50 * dir_size);

	while((dir = readdir(d)) != NULL) {
		if(i >= dir_size) {

			dir_size += 10;
			tmp_ptr = realloc(dest, sizeof(char **) * 50 * dir_size);

			if(tmp_ptr) {
				dest = tmp_ptr;
			} else {
				free(dest);
				return NULL;
			}
		}
		dest[i] = dir->d_name;
		i++;
	}

	dest[i] = "\0";
    closedir(d);

    return dest;
}
