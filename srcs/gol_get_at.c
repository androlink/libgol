/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_get_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:40:16 by gcros             #+#    #+#             */
/*   Updated: 2025/08/17 22:00:42 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

int	gol_get_at(t_gol *gol, size_t x, size_t y)
{
	return (gol->cells[y * gol->width + x].value);
}

int	gol_get_at_s(t_gol *gol, ssize_t x, ssize_t y)
{
	if (x < 0 || (size_t)x >= gol->width || y < 0 || (size_t)y >= gol->height)
		return (0);
	return (gol_get_at(gol, x, y));
}
