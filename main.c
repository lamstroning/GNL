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

#include "get_next_line.h" 
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int		save_next_line(char **line,char *arr)
{	
	char static **tmp;
	if (line == NULL)
		line = ft_memalloc(1);

	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char		*arr;
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char 		*tmp;

	arr = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (arr == NULL)
			arr = ft_strnew(1);
		tmp = ft_strjoin(arr, buf);
		free(arr);
		arr = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	} 
	return (save_next_line(line, arr));
}

int main(int argc, char **argv)
{
	char **line;
	int fd = open("file", O_RDONLY);

	get_next_line(fd,line);
	printf("%s\n", *line);
	close(fd);

	return 0;
}
