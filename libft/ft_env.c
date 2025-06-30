#include "libft.h"

extern char	**environ;

char	**ft_env(char *name)
{
	char	**env;
	size_t	i;

	env = environ;
	while (env && *env)
	{
		i = 0;
		while (*(*env + i) == name[i])
			i++;
		if (*(*env + i) == '=')
			return (ft_split(*env + i + 1, ':'));
		env++;
	}
	return (NULL);
}
