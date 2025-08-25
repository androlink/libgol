/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:25:13 by gcros             #+#    #+#             */
/*   Updated: 2025/08/17 20:05:48 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"
#include <malloc.h>

void	utils_bzero(void *ptr, size_t n);

t_gol	*gol_init(size_t width, size_t height)
{
	t_gol	*gol;

	gol = malloc(sizeof(*gol));
	if (gol == NULL)
		return (NULL);
	gol->cells = malloc(width * height * sizeof(*gol->cells));
	if (gol->cells == NULL)
		return (free(gol), NULL);
	utils_bzero(gol->cells, width * height * sizeof(*gol->cells));
	gol->width = width;
	gol->height = height;
	gol->rule = gol_default_rule;
	return (gol);
}
