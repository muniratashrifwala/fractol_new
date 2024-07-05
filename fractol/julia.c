/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtashrif <mtashrif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:40:10 by mtashrif          #+#    #+#             */
/*   Updated: 2024/03/02 16:50:51 by mtashrif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <ctype.h>
#include <string.h>

int	is_valid_julia_parameter(const char *param)
{
	int	decimal_point_count;
	int	length;
	int	valid;
	int	i;

	decimal_point_count = 0;
	length = (int)strlen(param);
	valid = 1;
	i = 0;
	while (i < length)
	{
		if (param[i] == '.')
		{
			decimal_point_count++;
		}
		else if (!isdigit(param[i]) && (param[i] != '-' || i != 0))
		{
			valid = 0;
			break ;
		}
		i++;
	}
	if (decimal_point_count > 1)
		valid = 0;
	return (valid);
}
