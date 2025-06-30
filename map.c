#include "fdf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static void	fill_map(t_map *map, char *line)
{
	t_vector3	pos;
	int			color;

	map->width = 0;
	while (*line)
	{
		while (*line && *line == ' ')
			line++;
		if (!*line)
			break ;
		pos = (t_vector3){map->width, map->height, ft_atoi(line)};
		while (*line == '-' || ft_isdigit(*line))
			line++;
		color = rgb_color(255, 255, 255);
		if (*line == ',' && *(line + 1) == '0' && *(line + 2) == 'x')
		{
			color = hexa_color(line + 3);
			line += 3;
		}
		insert_node(&map->nodes, new_node(map->nodes, pos, color));
		map->width++;
		while (*line && *line != ' ')
			line++;
	}
	map->height++;
}

t_map	*load_map(char *path)
{
	int			fd;
	t_map		*map;
	char		*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->nodes = NULL;
	map->height = 0;
	map->width = 0;
	line = ft_gnl(fd);
	while (line != NULL)
	{
		fill_map(map, line);
		free(line);
		line = ft_gnl(fd);
	}
	close(fd);
	map->tile_width = 100;
	map->tile_height = 50;
	map->image.ptr = NULL;
	return (map);
}
