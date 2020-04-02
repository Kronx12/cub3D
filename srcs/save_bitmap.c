/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bitmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 07:46:25 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/08 02:35:41 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*get_bmp_header(int size)
{
	static char res[14];

	res[0] = 'B';
	res[1] = 'M';
	res[2] = size >> 0;
	res[3] = size >> 8;
	res[4] = size >> 16;
	res[5] = size >> 24;
	res[10] = 54;
	return (res);
}

char	*get_dib_header(t_data *data, int size)
{
	static char res[40];

	res[0] = 0x28;
	res[4] = data->screenw >> 0;
	res[5] = data->screenw >> 8;
	res[6] = data->screenw >> 16;
	res[7] = data->screenw >> 24;
	res[8] = data->screenh >> 0;
	res[9] = data->screenh >> 8;
	res[10] = data->screenh >> 16;
	res[11] = data->screenh >> 24;
	res[12] = 0x1;
	res[14] = 0x18;
	res[20] = (size - 54) >> 0;
	res[21] = (size - 54) >> 8;
	res[22] = (size - 54) >> 16;
	res[23] = (size - 54) >> 24;
	return (res);
}

int		write_map(t_data *data, int fd, int y)
{
	int		x;
	int		x_line;
	char	*img_line;

	while (--y >= 0)
	{
		if (!(img_line = malloc(data->screenw * 3 + data->screenw % 4)))
			return (EXIT_FAILURE);
		x = -1;
		x_line = 0;
		while (++x < data->screenw)
		{
			img_line[x_line] = data->img->img_data[x + y * data->screenw] %
				(int)pow(16, 2);
			img_line[x_line + 1] = ((data->img->img_data[x + y * data->screenw]
				% (int)pow(16, 4)) - img_line[x_line]) >> 8;
			img_line[x_line + 2] = ((data->img->img_data[x + y * data->screenw]
				% (int)pow(16, 6)) - img_line[x_line + 1]) >> 16;
			x_line += 3;
		}
		write(fd, img_line, data->screenw * 3 + data->screenw % 4);
		free(img_line);
		img_line = NULL;
	}
	return (EXIT_SUCCESS);
}

int		save_to_bpm(t_data *data)
{
	int		fd;
	int		size;

	size = data->screenw * data->screenh * 3 + 54;
	if (data->screenw % 4 != 0)
		size += data->screenw % 4 * data->screenh;
	close(open("save.bmp", O_RDONLY | O_CREAT, S_IRWXU));
	fd = open("save.bmp", O_RDWR);
	write(fd, get_bmp_header(size), 14);
	write(fd, get_dib_header(data, size), 40);
	if (write_map(data, fd, data->screenh) == EXIT_FAILURE)
		error_base(EXIT_FAILURE, "Erreur de malloc", data);
	close(fd);
	ft_printf("Saved");
	close_game(data);
	exit(EXIT_SUCCESS);
}
