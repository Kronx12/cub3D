/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 07:53:27 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/08 02:35:28 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		error_base(int error, char *err, t_data *data)
{
	ft_printf("Error\n%s\n", err);
	if (data)
	{
		if (data->mlx_win != NULL)
			mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		if (data->img->img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->img->img);
		if (data->no_img->img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->no_img->img);
		if (data->so_img->img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->so_img->img);
		if (data->we_img->img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->we_img->img);
		if (data->ea_img->img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->ea_img->img);
		if (data->s_img->img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->s_img->img);
		free_data_structure(data);
	}
	exit(error);
}

int		close_game(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_image(data->mlx_ptr, data->img->img);
	mlx_destroy_image(data->mlx_ptr, data->no_img->img);
	mlx_destroy_image(data->mlx_ptr, data->so_img->img);
	mlx_destroy_image(data->mlx_ptr, data->we_img->img);
	mlx_destroy_image(data->mlx_ptr, data->ea_img->img);
	mlx_destroy_image(data->mlx_ptr, data->s_img->img);
	exit(EXIT_SUCCESS);
	return (0);
}

void	check_max_display(t_data *data)
{
	if (data->screenw > 2560 || data->screenw < 0)
		data->screenw = 2560;
	if (data->screenh > 1395 || data->screenh < 0)
		data->screenh = 1395;
	else if (data->screenw < 500 || data->screenh < 500)
	{
		ft_printf("Resolution actuelle %dx%d\n", data->screenw, data->screenh);
		ft_printf("Resolution recommande superieure a 500x500\n");
	}
}

void	check_parameters(t_data *data)
{
	if (!data->screenw || !data->screenh || !data->no_texture ||
		!data->so_texture || !data->we_texture || !data->ea_texture ||
		!data->s_texture || data->floor_c == -1 || data->top_c == -1 ||
		!data->map)
	{
		ft_printf("Error\nParameter NULL or no valid ID (Too hight res)\n");
		exit(EXIT_FAILURE);
	}
	check_max_display(data);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	if (argc < 2)
		error_base(EXIT_FAILURE, "Config file is missing !", NULL);
	if (check_config_name(argv[1]) == EXIT_FAILURE)
		error_base(EXIT_FAILURE, "Config file invalid !", NULL);
	if (init_structure_data(&data) == EXIT_FAILURE)
		error_base(EXIT_FAILURE, "Main structure initialisation error", NULL);
	fd = open(argv[1], O_RDONLY);
	parse_config(fd, &data);
	check_parameters(&data);
	if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
		data.save = 1;
	else if (argc > 2)
		error_base(EXIT_FAILURE, "Invalid args or too many args", &data);
	if (!(data.mlx_ptr = mlx_init()))
		error_base(EXIT_FAILURE, "Mlx initialisation error", &data);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, data.screenw,
		data.screenh, "CUB3D")) == NULL)
		error_base(EXIT_FAILURE, "Window creation error", &data);
	if (load_textures(&data) == EXIT_FAILURE)
		error_base(EXIT_FAILURE, "Invalid texture path", &data);
	start(&data);
	return (EXIT_SUCCESS);
}
