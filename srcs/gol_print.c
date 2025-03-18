/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:08:52 by gcros             #+#    #+#             */
/*   Updated: 2025/03/18 16:58:51 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"
#include <unistd.h>

void	gol_print(t_gol *gol)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < gol->height)
	{
		i = 0;
		while (i < gol->width)
		{
			if (gol->cells[j * gol->width + i].value == 1)
				write(1, "#", 1);
			else
				write(1, ".", 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}
