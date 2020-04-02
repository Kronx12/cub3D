/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 00:20:18 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/05 01:15:06 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	start(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, press_key, data);
	mlx_hook(data->mlx_win, 3, 0, release_key, data);
	mlx_hook(data->mlx_win, 17, 0, close_game, data);
	mlx_loop_hook(data->mlx_ptr, show_image, data);
	mlx_loop(data->mlx_ptr);
}

int		check_config_name(char *name)
{
	int len;

	len = ft_strlen(name) - 4;
	if (len > 0 && name[len] == '.' && name[len + 1] == 'c' &&
		name[len + 2] == 'u' && name[len + 3] == 'b')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
