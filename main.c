#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (EXIT_FAILURE);
	fdf = init_fdf(argv[1]);
	if (!fdf)
		return (EXIT_FAILURE);
	mlx_loop_hook(fdf->mlx, renders_map, fdf);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_mouse_hook(fdf->win, mouse_hooks, fdf);
	mlx_hook(fdf->win, 33, 1L << 17, close_hook, fdf);
	mlx_loop(fdf->mlx);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_image(fdf->mlx, fdf->map->image.ptr);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	empty_node(fdf->map->nodes);
	free(fdf->map);
	free(fdf);
	return (EXIT_SUCCESS);
}
