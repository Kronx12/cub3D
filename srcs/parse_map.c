/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 06:50:36 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/05 04:18:35 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	setup_camera_twice(t_data *data)
{
	int i;

	i = -1;
	while (data->map[++i])
		if (data->map[i] != '0' && data->map[i] != '1' && data->map[i] != '2')
		{
			if (data->map[i] == 'N')
			{
				data->dir_y = -1;
				data->dir_x = 0;
				data->planex = 0.66;
				data->planey = 0;
				data->p_x = i % data->mapw + 0.5;
				data->p_y = i / data->mapw + 0.5;
			}
			else if (data->map[i] == 'W')
			{
				data->dir_x = -1;
				data->dir_y = 0;
				data->planex = 0;
				data->planey = -0.66;
				data->p_x = i % data->mapw + 0.5;
				data->p_y = i / data->mapw + 0.5;
			}
		}
}

void	setup_camera_first(t_data *data)
{
	int i;

	i = -1;
	while (data->map[++i])
		if (data->map[i] != '0' && data->map[i] != '1' && data->map[i] != '2')
		{
			if (data->map[i] == 'S' && (data->dir_y = 1.001))
			{
				data->dir_x = 0;
				data->planex = -0.66;
				data->planey = 0;
				data->p_x = i % data->mapw + 0.5;
				data->p_y = i / data->mapw + 0.5;
			}
			else if (data->map[i] == 'E')
			{
				data->dir_x = 1.001;
				data->dir_y = 0;
				data->planex = 0;
				data->planey = 0.66;
				data->p_x = i % data->mapw + 0.5;
				data->p_y = i / data->mapw + 0.5;
			}
		}
	setup_camera_twice(data);
}

void	parse_map_end(t_data *data, int fd)
{
	data->map = remove_space(data->map);
	check_char(data);
	if (count_player(data) != 1)
		error(data, "Il y a trop ou pas de joueurs sur la map", -1);
	check_map(data);
	setup_camera_first(data);
	close(fd);
}

void	parse_map(t_data *data, char **line, int fd)
{
	int		r;
	int		len;
	char	*tmp;

	*line = remove_space(*line);
	data->mapw = ft_strlen(*line);
	if (++data->maph && !(data->map = ft_strdup(*line)))
		error_base(EXIT_FAILURE, "malloc error", data);
	free(*line);
	while ((r = get_next_line(fd, line)) >= 0)
	{
		tmp = remove_space(ft_strdup(*line));
		len = ft_strlen(tmp);
		free(tmp);
		if (len != data->mapw)
			error(data, "Largeur de ligne inegales", -1);
		if (!(data->map = ft_strfjoin(data->map, *line, 2)))
			error_base(EXIT_FAILURE, "malloc error", data);
		data->maph++;
		if (r == 0)
		{
			parse_map_end(data, fd);
			return ;
		}
	}
}
