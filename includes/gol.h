/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:19:36 by gcros             #+#    #+#             */
/*   Updated: 2025/08/25 23:10:09 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOL_H
# define GOL_H

# include <stddef.h>
# include <sys/types.h>

typedef struct s_gol		t_gol;
typedef struct s_cell		t_cell;

struct s_cell
{
	int	value;
	int	count;
};

typedef void				((*t_rule_function)(t_cell*));

struct s_gol
{
	t_cell			*cells;
	size_t			width;
	size_t			height;
	t_rule_function	rule;
};

void	gol_set_at(t_gol *gol, size_t x, size_t y, int value);
int		gol_get_at(t_gol *gol, size_t x, size_t y);
int		gol_get_at_s(t_gol *gol, ssize_t x, ssize_t y);
void	gol_set_at_s(t_gol *gol, ssize_t x, ssize_t y, int value);

t_gol	*gol_init(size_t width, size_t height);
int		gol_update(t_gol *gol);
int		gol_expend(t_gol *gol, ssize_t wsize[2], ssize_t hsize[2]);
int		gol_resize(t_gol *gol, size_t new_x, size_t new_y);
void	gol_print(t_gol *gol);
void	gol_destruct(t_gol *gol);
int		gol_weight(t_gol *gol, size_t x, size_t y);
void	gol_set_rule(t_gol *gol, t_rule_function frule);
void	gol_default_rule(t_cell *cell_ptr);

long	util_max(long n1, long n2);
long	util_min(long n1, long n2);

#endif
