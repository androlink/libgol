/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_set_rule.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:53:20 by gcros             #+#    #+#             */
/*   Updated: 2025/08/17 20:09:10 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

void	gol_set_rule(t_gol *gol, t_rule_function frule)
{
	gol->rule = frule;
}

// B3/S23
void	gol_default_rule(t_cell *cell_ptr)
{
	static const unsigned int	b = 0b000001000;
	static const unsigned int	s = 0b000001100;

	if (cell_ptr->value != 0)
	{
		cell_ptr->value = (s >> cell_ptr->count) & 1;
	}
	else
	{
		cell_ptr->value = (b >> cell_ptr->count) & 1;
	}
}
