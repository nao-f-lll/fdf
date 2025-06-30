#include "libft.h"

void	ft_memrep(void **a, void *b)
{
	free(*a);
	*a = b;
}
