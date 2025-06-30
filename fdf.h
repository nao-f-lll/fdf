#ifndef FDF_H
# define FDF_H

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1000
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 750
# endif

typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

typedef struct s_vector3
{
	int	x;
	int	y;
	int	z;
}	t_vector3;

typedef struct s_image
{
	void	*ptr;
	char	*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_node
{
	t_vector3		pos;
	int				color;
	struct s_node	*under;
	struct s_node	*next;
}	t_node;

typedef struct s_map
{
	t_node	*nodes;
	int		width;
	int		height;
	t_image	image;
	int		tile_width;
	int		tile_height;
}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_fdf;

typedef struct s_gradient
{
	int	from;
	int	to;
}	t_gradient;

t_node	*new_node(t_node *nodes, t_vector3 pos, int color);
t_node	*last_node(t_node *node);
void	insert_node(t_node **to, t_node *node);
void	empty_node(t_node *node);
t_map	*load_map(char *path);
int		rgb_color(int r, int g, int b);
int		hexa_color(char *hexa);
int		lerp_color(int color1, int color2, int time);
t_fdf	*init_fdf(char *path);
void	draw_pixel(t_image image, t_vector2 pos, int color);
void	draw_line(t_image img, t_vector2 st, t_vector2 ed, t_gradient grdt);
void	draw_node(t_map *map, t_node *node);
int		render_map(t_map *map);
int		mouse_hook(int key_code, t_fdf *fdf);
int		key_hook(int key_code, t_fdf *fdf);
int		close_hook(t_fdf *fdf);
int		renders_map(t_fdf *fdf);
int		mouse_hooks(int key_code, int x, int y, t_fdf *fdf);
#endif
