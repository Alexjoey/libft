/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 00:57:57 by amylle            #+#    #+#             */
/*   Updated: 2024/03/11 17:15:26 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
/*
char	*getskipline(char **buffer)
{
	char	*ret;
	char	*nxtline;
	char	*temp;

	nxtline = ft_strchr(*buffer, '\n');
	if (!nxtline)
	{
		temp = *buffer;
		free (*buffer);
		*buffer = NULL;
		return (temp);
	}
	ret = ft_substr(*buffer, 0, nxtline - *buffer + 1);
	temp = ft_substr(*buffer, nxtline - *buffer + 1, \
			*buffer + ft_strlen(*buffer) - nxtline);
	free (*buffer);
	*buffer = temp;
	return (ret);
}
*/
static char	*ft_strjoingnl(char *str, char const *buff)
{
	int		j;
	int		i;
	char	*res;

	if (!str)
		str = ft_calloc(1, 1);
	if (!str || !buff)
		return (NULL);
	res = (char *)malloc((ft_strlen(str) + ft_strlen(buff) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	if (str)
		while (str[++i])
			res[i] = str[i];
	j = -1;
	while (buff[++j])
		res[i + j] = buff[j];
	res[i + j] = '\0';
	free (str);
	return (res);
}

static char	*ft_getline(char *buffer)
{
	char	*nxtline;
	char	*line;

	if (!buffer[0])
		return (NULL);
	nxtline = ft_strchr(buffer, '\n');
	if (!nxtline)
	{
		line = ft_substr(buffer, 0, ft_strlen(buffer) + 1);
		return (line);
	}
	line = ft_substr(buffer, 0, nxtline - buffer + 1);
	return (line);
}

static char	*ft_getbuffer(char *buffer)
{
	char	*nxtline;
	char	*temp;

	nxtline = ft_strchr(buffer, '\n');
	if (!nxtline)
	{
		free (buffer);
		return (NULL);
	}
	temp = ft_substr(buffer, nxtline - buffer + 1, \
			buffer + ft_strlen(buffer) - nxtline);
	if (!temp)
	{
		free (buffer);
		return (NULL);
	}
	free (buffer);
	return (temp);
}

static char	*read_file(int fd, char *str)
{
	char	*buffer;
	int		readret;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	readret = 1;
	while (!ft_strchr(str, '\n') && readret > 0)
	{
		readret = read(fd, buffer, BUFFER_SIZE);
		if (readret == -1)
		{
			free (buffer);
			free (str);
			return (NULL);
		}
		buffer[readret] = 0;
		str = ft_strjoingnl(str, buffer);
	}
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_getline(buffer[fd]);
	buffer[fd] = ft_getbuffer(buffer[fd]);
	return (line);
}
