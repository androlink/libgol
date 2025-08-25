/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_set_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:30:48 by gcros             #+#    #+#             */
/*   Updated: 2025/08/17 22:00:56 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

void	gol_set_at(t_gol *gol, size_t x, size_t y, int value)
{
	gol->cells[y * gol->width + x].value = value;
}

void	gol_set_at_s(t_gol *gol, ssize_t x, ssize_t y, int value)
{
	if (x < 0 || (size_t)x >= gol->width || y < 0 || (size_t)y >= gol->height)
		return ;
	return (gol_set_at(gol, x, y, value));
}
