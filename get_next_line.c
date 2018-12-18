/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:23:42 by tdontos-          #+#    #+#             */
/*   Updated: 2018/12/11 16:57:52 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char static		*arr;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*copy;

	if ((fd < 0 || read(fd, buf, 0) < 0))
		return (-1);
	arr = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (arr == NULL)
			arr = ft_strnew(ret);
		if (ft_strchr(buf, '\n'))
			break ;
		copy = ft_strjoin(arr, buf);
		free(arr);
		arr = copy;
	}
	if (arr == NULL)
		return (0);
	*line = ft_strnew(ft_strlen(arr));
	*line = ft_strcpy(*line, arr);
	return (1);
}
