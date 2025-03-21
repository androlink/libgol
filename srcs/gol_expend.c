/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_expend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:21:56 by gcros             #+#    #+#             */
/*   Updated: 2025/03/18 16:58:30 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"
#include <malloc.h>

void		utils_bzero(void *ptr, size_t n);
static void	copy(t_gol *gol, t_cell *ndata, size_t off[2], size_t nwidth);

int	gol_expend(t_gol *gol, size_t wsize[2], size_t hsize[2])
{
	t_cell		*ndata;
	const int	nwidth = gol->width + wsize[0] + wsize[1];
	const int	nheight = gol->height + hsize[0] + hsize[1];

	ndata = malloc(nwidth * nheight * sizeof(*gol->cells));
	if (ndata == NULL)
		return (1);
	utils_bzero(ndata, nwidth * nheight * sizeof(*gol->cells));
	copy(gol, ndata, (size_t []){wsize[0], hsize[0]}, nwidth);
	free(gol->cells);
	gol->cells = ndata;
	gol->width = nwidth;
	gol->height = nheight;
	return (0);
}

static void	copy(t_gol *gol, t_cell *ndata, size_t off[2], size_t nwidth)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < gol->height)
	{
		i = 0;
		while (i < gol->width)
		{
			ndata[(j + off[1]) * nwidth + (i + off[0])].value
				= gol_get_at(gol, i, j);
			i++;
		}
		j++;
	}
}
