/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtashrif <mtashrif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:40:15 by mtashrif          #+#    #+#             */
/*   Updated: 2024/03/02 16:51:21 by mtashrif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_julia_parameters(t_fractol *fractal, char **av)
{
	if (av[2] == NULL || av[3] == NULL)
	{
		ft_putstr_fd("Please provide both Julia parameters.\n", STDERR_FILENO);
		return (0);
	}
	if (!is_valid_julia_parameter(av[2]) || !is_valid_julia_parameter(av[3]))
	{
		ft_putstr_fd("Invalid Julia parameters",
			STDERR_FILENO);
		return (0);
	}
	fractal->julia_x = atodbl(av[2]);
	fractal->julia_y = atodbl(av[3]);
	if (fractal->julia_x < -2 || fractal->julia_x > 2 || fractal->julia_y < -2
		|| fractal->julia_y > 2)
	{
		ft_putstr_fd("Julia parameters should be between -2 and 2.\n",
			STDERR_FILENO);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fractol	fractal;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)))
	{
		fractal.name = av[1];
		fractal_init(&fractal);
		fractol_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else if (4 == ac && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.name = av[1];
		if (!check_julia_parameters(&fractal, av))
		{
			exit(EXIT_FAILURE);
		}
		fractal_init(&fractal);
		fractol_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
