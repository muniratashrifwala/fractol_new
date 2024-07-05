/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtashrif <mtashrif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:40:25 by mtashrif          #+#    #+#             */
/*   Updated: 2024/03/02 16:51:52 by mtashrif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <ApplicationServices/ApplicationServices.h>

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	free(fractol->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractol->zoom *= 0.95;
	}
	else if (button == 5)
	{
		fractol->zoom *= 1.05;
	}
	fractol_render(fractol);
	return (0);
}

int	julia_track(int x, int y, t_fractol *fractol)
{
	t_mappingrange	range_x;
	t_mappingrange	range_y;

	if (!ft_strncmp(fractol->name, "julia", 5) && !fractol->is_locked)
	{
		range_x.n_min = -2;
		range_x.n_max = +2;
		range_x.o_min = 0;
		range_x.o_max = WIDTH;
		fractol->julia_x = map(x, range_x) * fractol->zoom;
		range_y.n_min = +2;
		range_y.n_max = -2;
		range_y.o_min = 0;
		range_y.o_max = HEIGHT;
		fractol->julia_y = map(y, range_y) * fractol->zoom;
		fractol_render(fractol);
	}
	return (0);
}
