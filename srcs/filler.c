/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:09:53 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/13 20:34:37 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_figure(char ***f)
{
	char	*line;
	char	*temp;
	int		i;
	int		j;

	get_next_line(0, &line);
	temp = line;
	line += 6;
	i = ft_atoi(line);
	line += base_size_sg(i, 10);
	j = ft_atoi(line);
	free(temp);
	create_map(i, j, f);
	fill_map(*f, i, 0);
}

void	check_distance(char **map, int a, int b, int j)
{
	int dis;
	int flag;

	dis = 0;
	flag = 0;
	if (b && map[a][b - 1] >= 0 && ++flag)
		dis = (map[a][b - 1] < dis || flag < 2) ? map[a][b - 1] : dis;
	if (b + 1 < j && map[a][b + 1] >= 0 && ++flag)
		dis = (map[a][b + 1] < dis || flag < 2) ? map[a][b + 1] : dis;
	if (a && map[a - 1][b] >= 0 && ++flag)
		dis = (map[a - 1][b] < dis || flag < 2) ? map[a - 1][b] : dis;
	if (map[a + 1] && map[a + 1][b] >= 0 && ++flag)
		dis = (map[a + 1][b] < dis || flag < 2) ? map[a + 1][b] : dis;
	if (map[a + 1] && b + 1 < j && map[a + 1][b + 1] >= 0 && ++flag)
		dis = (map[a + 1][b + 1] < dis || flag < 2) ? map[a + 1][b + 1] : dis;
	if (map[a + 1] && b && map[a + 1][b - 1] >= 0 && ++flag)
		dis = (map[a + 1][b - 1] < dis || flag < 2) ? map[a + 1][b - 1] : dis;
	if (a && b + 1 < j && map[a - 1][b + 1] >= 0 && ++flag)
		dis = (map[a - 1][b + 1] < dis || flag < 2) ? map[a - 1][b + 1] : dis;
	if (a && b && map[a - 1][b - 1] >= 0 && ++flag)
		dis = (map[a - 1][b - 1] < dis || flag < 2) ? map[a - 1][b - 1] : dis;
	if (flag)
		map[a][b] = dis + 1;
}

void	heatmap(char **map, int i, int j)
{
	int a;
	int b;
	int max_len;

	max_len = i > j ? i : j;
	while (max_len--)
	{
		a = -1;
		while (map[++a])
		{
			b = -1;
			while (++b < j)
				if (map[a][b] == -2)
					check_distance(map, a, b, j);
		}
	}
}

void	filler(t_helper *help)
{
	int		dist;
	int		flag;

	create_map(help->i, help->j, &help->map);
	dist = 1;
	flag = 0;
	while (dist)
	{
		if (flag++)
		{
			get_next_line(0, &help->line);
			free(help->line);
		}
		fill_map(help->map, help->i, 4);
		get_figure(&help->figure);
		set_to_zero(help->map, help->i, help->j, help->me);
		heatmap(help->map, help->i, help->j);
		count_vector(help);
		dist = 0;
		help->a = 0;
		dist = search_min_dis(help, dist);
	}
}

/*
**     -\-
**     \-- \-
**      \  - -\
**       \      \\
**        \       \
**         \       \\
**          \        \\
**          \          \\
**          \           \\\
**           \            \\
**            \            \\
**            \. .          \\
**             \    .       \\
**              \      .    \\
**               \       .  \\
**               \         . \\
**               \            <=)
**               \            <==)
**               \            <=)
**                \           .\\                                           _-
**                \         .   \\                                        _-//
**                \       .     \\                                     _-_/ /
**                \ . . .        \\                                 _--_/ _/
**                 \              \\                              _- _/ _/
**                 \               \\                      ___-(O) _/ _/
**                 \                \                  __--  __   /_ /
**                 \                 \\          ____--__----  /    \_ YPIKUL 💞
**                  \                  \\       -------       /   \_  \_
**                   \                   \                  //   // \__ \_
**                    \                   \\              //   //      \_ \_
**                     \                   \\          ///   //          \__-
**                     \                -   \\/////////    //
**                     \            -         \_         //
**                     /        -                      //
**                    /     -                       ///
**                   /   -                       //
**              __--/                         ///
**   __________/                            // |
** //-_________      ___                ////  |
**         ____\__--/                /////    |
**    -----______    -/---________////        |
**      _______/  --/    \                   |
**    /_________-/       \                   |
**   //                  \                   /
**                        \.                 /
**                        \     .            /
**                         \       .        /
**                        \\           .    /
**                         \                /
**                         \              __|
**                         \              ==/
**                         /              //
**                         /          .  //
**                         /   .  .    //
**                        /.           /
**                       /            //
**                       /           /
**                      /          //
**                     /         //
**                  --/         /
**                 /          //
**             ////         //
**          ///_________////
*/

int		main(void)
{
	t_helper	help;
	char		*temp;

	get_next_line(0, &help.line);
	help.me = help.line[10] == '1' ? 'O' : 'X';
	free(help.line);
	get_next_line(0, &help.line);
	temp = help.line;
	help.line += 8;
	help.i = ft_atoi(help.line);
	help.line += base_size_sg(help.i, 10);
	help.j = ft_atoi(help.line);
	free(temp);
	filler(&help);
	return (0);
}
