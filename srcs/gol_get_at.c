/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_get_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:40:16 by gcros             #+#    #+#             */
/*   Updated: 2025/03/14 16:41:34 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

int	gol_get_at(t_gol *gol, size_t x, size_t y)
{
	return (gol->data[y * gol->width + x]);
}

int	gol_get_at_s(t_gol *gol, size_t x, size_t y)
{
	if (x < 0 || x >= gol->width || y < 0 || y >= gol->height)
		return (0);
	return (gol_get_at(gol, x, y));
}
