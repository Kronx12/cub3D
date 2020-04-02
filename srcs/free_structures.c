/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 06:51:49 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/08 02:07:25 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	free_data_structure(t_data *data)
{
	free(data->keys);
	if (data->map)
		free(data->map);
	free(data->no_texture);
	free(data->so_texture);
	free(data->we_texture);
	free(data->ea_texture);
	free(data->s_texture);
	return (1);
}
