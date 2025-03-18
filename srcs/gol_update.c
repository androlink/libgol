/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:53:14 by gcros             #+#    #+#             */
/*   Updated: 2025/03/18 17:05:05 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"
#include <stdlib.h>

static void	get_value(t_gol *gol);
static void	apply_value(t_gol *gol);
long	util_min(long n1, long n2);
long	util_max(long n1, long n2);

int	gol_update(t_gol *gol)
{
	get_value(gol);
	apply_value(gol);
	return (0);
}

static void	get_value(t_gol *gol)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < gol->height)
	{
		i = 0;
		while (i < gol->width)
		{
			gol->cells[j * gol->width + i].count = gol_weight(gol, i, j);
			i++;
		}
		j++;
	}
}

static void	apply_value(t_gol *gol)
{
	size_t	i;
	size_t	j;
	t_cell	*cell_ptr;

	j = 0;
	while (j < gol->height)
	{
		i = 0;
		while (i < gol->width)
		{
			cell_ptr = gol->cells + j * gol->width + i;
			if (cell_ptr->value != 0)
			{
				if (cell_ptr->count < 2 || cell_ptr->count > 3)
					cell_ptr->value = 0;
			}
			else
			{
				if (cell_ptr->count == 3)
					cell_ptr->value = 1;
			}
			i++;
		}
		j++;
	}
}

int	gol_weight(t_gol *gol, size_t x, size_t y)
{
	int	n;
	int	i;
	int	j;
	int	mi;
	int	mj;

	n = 0;
	j = -1;
	mj = 2;
	while (j < mj)
	{
		i = -1;
		mi = 2;
		while (i < mi)
		{
			if (!(i == 0 && j == 0))
				n += gol_get_at_s(gol, x + i, y + j);
			i++;
		}
		j++;
	}
	return (n);
}
