/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:39:44 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/11 14:39:46 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "get_next_line.h"
# include "ft_printf.h"

typedef struct	s_helper
{
	char		**map;
	char		**figure;
	int			i;
	int			j;
	int			a;
	int			b;
	int			mv_a;
	int			mv_b;
	char		me;
	char		*line;
}				t_helper;

# define A help->a + y - help->mv_a
# define B help->b + x - help->mv_b

void			filler(t_helper *help);
void			heatmap(char **map, int i, int j);
void			check_distance(char **map, int a, int b, int j);
void			fill_map(char **map, int i, int mv);
void			create_map(int i, int j, char ***map);
void			set_to_zero(char **map, int i, int j, char me);
void			create_matrix(int i, int j, int ***matrix);
int				put_figure(t_helper *help);
void			count_vector(t_helper *help);
int				search_min_dis(t_helper *help, int dist);
void			clean_leaks(char **arr);

#endif
