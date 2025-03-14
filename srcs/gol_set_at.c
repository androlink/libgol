/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_set_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:30:48 by gcros             #+#    #+#             */
/*   Updated: 2025/03/14 16:39:16 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

void	gol_set_at(t_gol *gol, size_t x, size_t y, int value)
{
	gol->data[y * gol->width + x] = value;
}

void	gol_set_at_s(t_gol *gol, size_t x, size_t y, int value)
{
	if (x < 0 || x >= gol->width || y < 0 || y >= gol->height)
		return ;
	return (gol_set_at(gol, x, y, value));
}
