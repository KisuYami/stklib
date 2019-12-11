#include <unistd.h>
#include <sys/wait.h>

int
exec_fork(char **command)
{
	int ret = 0;

	switch (fork()) {
	case -1:
		ret = -1;
		break;
	case 0:
		execvp(command[0], command);
		break;
	default:
		wait(NULL);
	}
	return ret;
}
