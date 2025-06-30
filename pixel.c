#include "fdf.h"

void	draw_pixel(t_image image, t_vector2 pos, int color)
{
	char	*pixel;

	if (pos.x < 0 || pos.y < 0 || pos.x >= image.width || pos.y >= image.height)
		return ;
	pixel = image.data + (pos.y * image.size_line
			+ pos.x * (image.bits_per_pixel / 8));
	*(int *)pixel = color;
}
