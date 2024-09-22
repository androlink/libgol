/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:25:13 by gcros             #+#    #+#             */
/*   Updated: 2024/09/22 21:53:05 by gcros            ###   ########.fr       */
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
	gol->data = malloc(width * height * sizeof(*gol->data));
	if (gol->data == NULL)
		return (free(gol), NULL);
	utils_bzero(gol->data, width * height * sizeof(*gol->data));
	gol->width = width;
	gol->height = height;
	return (gol);
}
