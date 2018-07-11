/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:40:05 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/12 16:40:15 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	count_vector(t_helper *help)
{
	help->mv_a = -1;
	while (help->figure[++help->mv_a])
	{
		help->mv_b = -1;
		while (help->figure[help->mv_a][++help->mv_b])
		{
			if (help->figure[help->mv_a][help->mv_b] == '*')
				return ;
		}
	}
}

int		put_figure(t_helper *help)
{
	int dist;
	int y;
	int x;
	int flag;

	dist = 0;
	y = -1;
	flag = 0;
	while (help->figure[++y])
	{
		x = -1;
		while (help->figure[y][++x])
			if (help->figure[y][x] == '*')
			{
				if (!(A >= 0 && A < help->i && B >= 0
					&& B < help->j && help->map[A][B]))
					return (0);
				if (help->map[A][B] == -1)
					flag++;
				if (flag > 1)
					return (0);
				dist += help->map[A][B];
			}
	}
	return (flag ? dist : 0);
}

int		search_min_dis(t_helper *help, int dist)
{
	int row;
	int col;
	int tmp;

	while (++(help->a) < help->i)
	{
		help->b = -1;
		while (++(help->b) < help->j)
			if ((tmp = put_figure(help)) && (!dist || tmp < dist))
			{
				row = help->a - help->mv_a;
				col = help->b - help->mv_b;
				dist = tmp;
			}
	}
	if (!dist)
	{
		clean_leaks(help->map);
		exit(0);
	}
	clean_leaks(help->figure);
	ft_printf("%d %d\n", row, col);
	return (dist);
}
