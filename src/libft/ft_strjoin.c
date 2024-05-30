/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:41:05 by amylle            #+#    #+#             */
/*   Updated: 2023/10/22 16:55:46 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	int		i;
	char	*res;

	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char	*ft_strjoinfree(char *str, char const *buff)
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
