/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtashrif <mtashrif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:39:54 by mtashrif          #+#    #+#             */
/*   Updated: 2024/03/03 11:59:20 by mtashrif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MESSAGE "Enter\n\t\" Mandelbrot\" or\n\t\" Julia <v1> <v2>\""

# define WIDTH 1000
# define HEIGHT 1000

# define BLACK 0x000000 // RGB(0, 0, 0)
# define WHITE 0xFFFFFF // RGB(255, 255, 255)
# define RED 0xFF0000   // RGB(255, 0, 0)
# define GREEN 0x00FF00 // RGB(0, 255, 0)
# define BLUE 0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
# define MAGENTA_BURST 0xFF00FF      // A vibrant magenta
# define LIME_SHOCK 0xCCFF00         // A blinding lime
# define NEON_ORANGE 0xFF6600        // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066 // A deep purple
# define AQUA_DREAM 0x33CCCC         // A bright turquoise
# define HOT_PINK 0xFF66B2           // As the name suggests!
# define ELECTRIC_BLUE 0x0066FF      // A radiant blue
# define LAVA_RED 0xFF3300           // A bright, molten red
# define NUDE_PINK 0xF2DADF
# define DARK_BLUE 0x0e1565

typedef struct s_complex
{
	long double	x;
	long double	y;
}				t_complex;

typedef struct s_img
{
	void		*img_ptr;
	char		*pixels_ptr;
	int			bpp;
	int			endian;
	int			line_len;
	double		scale;
}				t_img;

typedef struct s_fractol
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_img		img;
	double		escape_value;
	int			iterations_defintion;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
	int			is_locked;
}				t_fractol;

typedef struct s_mappingrange
{
	double		n_min;
	double		n_max;
	double		o_min;
	double		o_max;
}				t_mappingrange;

int				ft_strncmp(char *str1, char *str2, unsigned int n);
void			ft_putstr_fd(char *s, int fd);
double			atodbl(char *s);
int				ft_strlen(char *str);
int				is_valid_julia_parameter(const char *param);
int				check_julia_parameters(t_fractol *fractal, char **av);
void			fractal_init(t_fractol *fractal);
void			fractol_render(t_fractol *fractol);
double			map(double uns_num, t_mappingrange range);
t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		square_complex(t_complex z);
int				key_handler(int keycode, t_fractol *fractol);
void			handle_arrow_keys(t_fractol *fractol, int keycode);
void			handle_up_down_keys(t_fractol *fractol, int keycode);
void			handle_plus_minus_keys(t_fractol *fractol, int keycode);
int				close_handler(t_fractol *fractol);
int				mouse_handler(int button, int x, int y, t_fractol *fractol);
int				julia_track(int x, int y, t_fractol *fractal);
int				check_julia_parameters(t_fractol *fractal, char **av);
t_complex		get_mapped_coordinates(int x, int y, t_fractol *fractal);
int				get_color_for_pixel(t_complex z, t_complex c,
					t_fractol *fractal);
void			handle_pixel(int x, int y, t_fractol *fractal);

extern int		key_handler(int keysym, t_fractol *fractal);
extern int		mouse_handler(int button, int x, int y, t_fractol *fractol);
extern int		close_handler(t_fractol *fractal);
extern int		julia_track(int x, int y, t_fractol *fractal);

#endif