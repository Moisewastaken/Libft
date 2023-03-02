/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:29:07 by mcochin           #+#    #+#             */
/*   Updated: 2022/10/06 15:05:22 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*readnsave(char *save, int fd)
{
	char	*buffer;
	int		i;

	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	i = read(fd, buffer, BUFFER_SIZE);
	if (i < 0)
	{
		free(save);
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	if (i > 0)
		save = join_free(save, buffer);
	free(buffer);
	return (save);
}

char	*clean_save(char *save)
{
	char		*tmp;
	size_t		y;
	int			i;

	i = 0;
	y = is_end_of_line(save);
	if (y == ft_strlen(save) || y == 0)
	{
		free(save);
		return (NULL);
	}
	tmp = ft_calloc(sizeof(char), (ft_strlen(save) - y) + 1);
	while (save[y + i])
	{
		tmp[i] = save[y + i];
		i++;
	}
	free(save);
	return (tmp);
}

char	*fill_str(char *save)
{
	int		y;
	int		i;
	char	*str;

	i = 0;
	y = is_end_of_line(save);
	if (y == 0)
		y = ft_strlen(save);
	if (save[0] == '\0')
		return (NULL);
	str = ft_calloc(sizeof(char), y + 1);
	while (i < y)
	{
		str[i] = save[i];
		i++;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*save[1024];
	size_t		slen;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_calloc(sizeof(char), 1);
	while (is_end_of_line(save[fd]) == 0)
	{
		slen = ft_strlen(save[fd]);
		save[fd] = readnsave(save[fd], fd);
		if (!save[fd])
			return (NULL);
		if ((slen + BUFFER_SIZE) != ft_strlen(save[fd]))
			break ;
	}
	str = fill_str(save[fd]);
	if (!str)
	{
		save[fd] = clean_save(save[fd]);
		return (NULL);
	}
	save[fd] = clean_save(save[fd]);
	return (str);
}
