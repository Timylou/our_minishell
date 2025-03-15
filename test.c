#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	char	pwd[PATH_MAX];

	getcwd(pwd, PATH_MAX);
	printf("%s\n", pwd);
}
