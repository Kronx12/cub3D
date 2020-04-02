/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 06:52:24 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/08 02:35:31 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error(t_data *data, char *error, int line)
{
	ft_printf("Error\n%s : line %d\n", error, line);
	free_data_structure(data);
	exit(EXIT_FAILURE);
}

int		rgb_to_int(int r, int g, int b, t_data *data)
{
	int rgb;

	if (r > 255 || g > 255 || b > 255)
		error(data, "Couleur superieur a 255", -1);
	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}

char	*remove_space(char *str)
{
	int		i;
	int		count;
	char	*res;

	i = -1;
	count = 0;
	if (!str)
		return (NULL);
	while (str[++i])
		if (str[i] != ' ')
			count++;
	if (!(res = malloc(count + 1)))
		return (NULL);
	res[count] = '\0';
	while (i--)
		if (str[i] != ' ')
			res[--count] = str[i];
	free(str);
	return (res);
}
