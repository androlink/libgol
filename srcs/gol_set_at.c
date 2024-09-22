/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_set_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:30:48 by gcros             #+#    #+#             */
/*   Updated: 2024/09/22 23:46:20 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

void	gol_set_at(t_gol *gol, size_t x, size_t y, int value)
{
	gol->data[y * gol->width + x] = value;
}
