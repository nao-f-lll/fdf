#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		imatching;

	i = 0;
	imatching = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			imatching = i;
		i++;
	}
	if (s[i] == (char)c)
		imatching = i;
	if (imatching < 0)
		return (NULL);
	return ((char *)s + imatching);
}
