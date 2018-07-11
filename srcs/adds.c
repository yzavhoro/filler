/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:38:30 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/11 14:38:31 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fill_map(char **map, int i, int mv)
{
	char	*line;
	int		a;

	a = 0;
	if (mv)
	{
		get_next_line(0, &line);
		free(line);
	}
	while (a < i)
	{
		get_next_line(0, &line);
		map[a] = ft_strcpy(map[a], line + mv);
		free(line);
		a++;
	}
}

void	set_to_zero(char **map, int i, int j, char me)
{
	int a;
	int b;

	a = 0;
	while (a < i)
	{
		b = 0;
		while (b < j)
		{
			if (map[a][b] == '.')
				map[a][b] = -2;
			else if (map[a][b] == me || map[a][b] == me + 32)
				map[a][b] = -1;
			else
				map[a][b] = 0;
			b++;
		}
		a++;
	}
}

void	create_map(int i, int j, char ***map)
{
	int a;

	a = 0;
	*map = (char**)malloc(sizeof(char*) * (i + 1));
	while (a < i)
		(*map)[a++] = (char*)malloc(sizeof(char) * j + 1);
	(*map)[a] = NULL;
}

void	clean_leaks(char **arr)
{
	int a;

	a = 0;
	while (arr[a])
		free(arr[a++]);
	free(arr[a]);
	free(arr);
}
