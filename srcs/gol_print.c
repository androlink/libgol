/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:08:52 by gcros             #+#    #+#             */
/*   Updated: 2025/08/25 23:10:52 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"
#include <unistd.h>
#include <stdlib.h>

void	gol_print(t_gol *gol)
{
	static const char	charset[] = ".#";
	size_t				i;
	size_t				j;
	char				*buffer;

	buffer = malloc((gol->height + 1) * gol->width);
	if (buffer == NULL)
		return ;
	j = 0;
	while (j < gol->height)
	{
		i = 0;
		while (i < gol->width)
		{
			buffer[j * gol->width + i + j] = charset[
				gol->cells[j * gol->width + i].value];
			i++;
		}
		buffer[j * gol->width + i + j] = '\n';
		j++;
	}
	write(1, buffer, (gol->height + 1) * gol->width);
	free(buffer);
}
