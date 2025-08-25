/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_expend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:21:56 by gcros             #+#    #+#             */
/*   Updated: 2025/08/25 22:46:56 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"
#include <malloc.h>

void		utils_bzero(void *ptr, size_t n);
static void	copy(t_gol *gol, t_cell *ndata, ssize_t off[2], ssize_t nsize[2]);

int	gol_resize(t_gol *gol, size_t new_x, size_t new_y)
{
	const ssize_t	diffx = new_x - gol->width;
	const ssize_t	diffy = new_y - gol->height;

	return (gol_expend(gol,
			(ssize_t[]){diffx / 2, diffx / 2},
		(ssize_t[]){diffy / 2, diffy / 2}));
}

int	gol_expend(t_gol *gol, ssize_t wsize[2], ssize_t hsize[2])
{
	t_cell			*ndata;
	const ssize_t	nwidth = gol->width + wsize[0] + wsize[1];
	const ssize_t	nheight = gol->height + hsize[0] + hsize[1];

	ndata = malloc(nwidth * nheight * sizeof(*gol->cells));
	if (ndata == NULL)
		return (1);
	utils_bzero(ndata, nwidth * nheight * sizeof(*gol->cells));
	copy(gol, ndata, (ssize_t []){wsize[0], hsize[0]},
		(ssize_t[]){nwidth, nheight});
	free(gol->cells);
	gol->cells = ndata;
	gol->width = nwidth;
	gol->height = nheight;
	return (0);
}

static void	copy(t_gol *gol, t_cell *ndata, ssize_t off[2], ssize_t nsize[2])
{
	const size_t	mj = util_min(gol->height, nsize[1] - off[1]);
	const size_t	mi = util_min(gol->width, nsize[0] - off[0]);
	size_t			i;
	size_t			j;

	j = util_max(0, -off[1]);
	while (j < mj)
	{
		i = util_max(0, -off[0]);
		while (i < mi)
		{
			ndata[(j + off[1]) * nsize[0] + (i + off[0])].value
				= gol_get_at(gol, i, j);
			i++;
		}
		j++;
	}
}
