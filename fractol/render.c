/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtashrif <mtashrif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:41:56 by mtashrif          #+#    #+#             */
/*   Updated: 2024/03/02 17:14:12 by mtashrif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

int	get_color_for_pixel(t_complex z, t_complex c, t_fractol *fractal)
{
	int				i;
	t_mappingrange	range_color;

	i = 0;
	while (i < fractal->iterations_defintion)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			range_color.n_min = DARK_BLUE;
			range_color.n_max = NUDE_PINK;
			range_color.o_min = 0;
			range_color.o_max = fractal->iterations_defintion;
			return (map(i, range_color));
		}
		i++;
	}
	return (BLACK);
}

void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractol *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

t_complex	get_mapped_coordinates(int x, int y, t_fractol *fractal)
{
	t_complex		z;
	t_mappingrange	range_x;
	t_mappingrange	range_y;

	range_x.n_min = -2;
	range_x.n_max = +2;
	range_x.o_min = 0;
	range_x.o_max = WIDTH;
	z.x = map(x, range_x) * fractal->zoom + fractal->shift_x;
	range_y.n_min = +2;
	range_y.n_max = -2;
	range_y.o_min = 0;
	range_y.o_max = HEIGHT;
	z.y = map(y, range_y) * fractal->zoom + fractal->shift_y;
	return (z);
}

void	handle_pixel(int x, int y, t_fractol *fractal)
{
	int			color;
	t_complex	z;
	t_complex	c;

	z = get_mapped_coordinates(x, y, fractal);
	mandel_vs_julia(&z, &c, fractal);
	color = get_color_for_pixel(z, c, fractal);
	my_pixel_put(x, y, &fractal->img, color);
}
