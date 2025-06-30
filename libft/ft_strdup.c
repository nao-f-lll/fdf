#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*copy;
	size_t		i;

	copy = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
