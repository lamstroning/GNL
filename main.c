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

int		get_next_line(const int fd, char **line)
{
	char static		*arr;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*copy;

	if (fd < 0 || line == NULL)
		return (-1);
	arr = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n'))
			break ;
		printf("buf = %s\n",buf);
		if (arr == NULL)
			arr = ft_strnew(ret);
		copy = ft_strjoin(arr, buf);
		free(arr);
		arr = copy;
	}
	if (arr == NULL)
		return (0);
	*line = ft_strnew(ft_strlen(arr));
	*line = ft_strcpy(*line,arr);
	return (1);
}

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "file";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567890abcde") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 1)
			printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567890abcde\" instead of \"%s\"\n", line);
		if (count_lines == 1 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}
