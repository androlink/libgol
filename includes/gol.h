/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:19:36 by gcros             #+#    #+#             */
/*   Updated: 2025/03/14 16:54:11 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOL_H
# define GOL_H

# include <stddef.h>

typedef struct s_gol	t_gol;

struct s_gol
{
	int		*data;
	size_t	width;
	size_t	height;
};

void	gol_set_at(t_gol *gol, size_t x, size_t y, int value);
int		gol_get_at(t_gol *gol, size_t x, size_t y);
int		gol_get_at_s(t_gol *gol, size_t x, size_t y);
void	gol_set_at_s(t_gol *gol, size_t x, size_t y, int value);

t_gol	*gol_init(size_t width, size_t height);
int		gol_update(t_gol *gol);
int		gol_expend(t_gol *gol, size_t wsize[2], size_t hsize[2]);
void	gol_print(t_gol *gol);
void	gol_destruct(t_gol *gol);
int		gol_weight(t_gol *gol, size_t x, size_t y);

#endif