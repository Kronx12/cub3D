/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 06:47:50 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/04 04:32:09 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		count_player(t_data *data)
{
	int count;
	int x;

	x = -1;
	count = 0;
	while (data->map[++x])
		if (data->map[x] == 'N' ||
			data->map[x] == 'S' ||
			data->map[x] == 'W' ||
			data->map[x] == 'E')
			count++;
	return (count);
}

void	check_char(t_data *data)
{
	int count;
	int x;

	x = -1;
	count = 0;
	while (data->map[++x])
		if (data->map[x] != 'N' &&
			data->map[x] != 'S' &&
			data->map[x] != 'W' &&
			data->map[x] != 'E' &&
			data->map[x] != '0' &&
			data->map[x] != '1' &&
			data->map[x] != '2')
			error(data, "Charactere non valide", -1);
}

int		check_side(t_data *data, char *map, int x, int y)
{
	int count;

	count = 0;
	if ((map[(x - 1) + data->mapw * y] == '0' || map[(x - 1) +
		data->mapw * y] == '2') && ++count)
		map[(x - 1) + data->mapw * y] = '9';
	if ((map[(x) + data->mapw * (y - 1)] == '0' || map[(x) +
		data->mapw * (y - 1)] == '2') && ++count)
		map[(x) + data->mapw * (y - 1)] = '9';
	if ((map[(x + 1) + data->mapw * y] == '0' || map[(x + 1) +
		data->mapw * y] == '2') && ++count)
		map[(x + 1) + data->mapw * y] = '9';
	if ((map[(x) + data->mapw * (y + 1)] == '0' || map[(x) +
		data->mapw * (y + 1)] == '2') && ++count)
		map[(x) + data->mapw * (y + 1)] = '9';
	return (count);
}

char	*copy_and_modif_map(t_data *data)
{
	int		x;
	char	*map;

	if (!(map = ft_strdup(data->map)))
		error_base(EXIT_FAILURE, "malloc error", data);
	x = -1;
	while (map[++x])
		if (map[x] == 'N' || map[x] == 'S' || map[x] == 'W' || map[x] == 'E')
			map[x] = '9';
	return (map);
}

void	check_map(t_data *data)
{
	int		x;
	int		y;
	int		v;
	char	*map;

	if (!(v = 0) && !data->map)
		error_base(EXIT_FAILURE, "malloc error", data);
	map = copy_and_modif_map(data);
	while (!v && (v = 1))
	{
		y = -1;
		while (++y < data->maph && (x = -1))
			while (++x < data->mapw)
				if (map[x + y * data->mapw] == '9' &&
					check_side(data, map, x, y) != 0)
					v = 0;
	}
	y = -1;
	while (++y < data->maph && (x = -1) < 0)
		while (++x < data->mapw)
			if (map[x + y * data->mapw] == '9')
				if (map[x + y * data->mapw] == '9' && (x == 0 ||
					x == data->mapw - 1 || y == 0 || y == data->maph - 1))
					error(data, "Map ouverte", -1);
	free(map);
}
