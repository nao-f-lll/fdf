#include "libft.h"

int	ft_lerp(int a, int b, int t)
{
	return (a + (b - a) * (float)(t / 255.0f));
}
