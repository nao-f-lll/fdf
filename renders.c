#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

int	renders_map(t_fdf *fdf)
{
	t_node	*node;

	if (fdf->map->image.ptr != NULL)
		mlx_destroy_image(fdf->mlx, fdf->map->image.ptr);
	fdf->map->image.width = WINDOW_WIDTH;
	fdf->map->image.height = WINDOW_HEIGHT;
	fdf->map->image.ptr = mlx_new_image(
			fdf->mlx,
			fdf->map->image.width,
			fdf->map->image.height);
	fdf->map->image.data = mlx_get_data_addr(
			fdf->map->image.ptr,
			&fdf->map->image.bits_per_pixel,
			&fdf->map->image.size_line,
			&fdf->map->image.endian);
	node = fdf->map->nodes;
	while (node != NULL)
	{
		draw_node(fdf->map, node);
		node = node->next;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->map->image.ptr, 0, 0);
	return (0);
}
