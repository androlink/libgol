/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:53:14 by gcros             #+#    #+#             */
/*   Updated: 2025/03/14 17:49:15 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"
#include <stdlib.h>

static void	get_value(t_gol *gol ,int *count);
static void	apply_value(t_gol *gol, int *count);
long	util_min(long n1, long n2);
long	util_max(long n1, long n2);

int	gol_update(t_gol *gol)
{
	int *const	count = malloc(sizeof(int) * gol->height * gol->width);

	if (count == NULL)
		return (1);
	get_value(gol, count);
	apply_value(gol, count);
	free(count);
	return (0);
}

static void	get_value(t_gol *gol, int *count)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < gol->height)
	{
		i = 0;
		while (i < gol->width)
		{
			count[j * gol->width + i] = gol_weight(gol, i, j);
			i++;
		}
		j++;
	}
}

static void	apply_value(t_gol *gol, int *count)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < gol->height)
	{
		i = 0;
		while (i < gol->width)
		{
			if (gol_get_at(gol, i, j) != 0)
			{
				if (count[j * gol->width + i] < 2
					|| count[j * gol->width + i] > 3)
					gol_set_at(gol, i, j, 0);
			}
			else
			{
				if (count[j * gol->width + i] == 3)
					gol_set_at(gol, i, j, 1);
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
				n += gol_get_at(gol, x + i, y + j);
			i++;
		}
		j++;
	}
	return (n);
}
