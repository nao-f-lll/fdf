#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

int	mouse_hooks(int key_code, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (key_code == 5)
	{
		fdf->map->tile_width -= 1;
		fdf->map->tile_height = fdf->map->tile_width / 2;
	}
	if (key_code == 4)
	{
		fdf->map->tile_width += 1;
		fdf->map->tile_height = fdf->map->tile_width / 2;
	}
	return (0);
}

int	key_hook(int key_code, t_fdf *fdf)
{
	if (key_code == 65307)
		mlx_loop_end(fdf->mlx);
	return (0);
}

int	close_hook(t_fdf *fdf)
{
	mlx_loop_end(fdf->mlx);
	return (0);
}
