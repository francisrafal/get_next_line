/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:18:29 by frafal            #+#    #+#             */
/*   Updated: 2022/10/14 15:43:33 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	ssize_t	n;
	size_t	i;
	char	*line;
	size_t	line_len;	
	size_t	bufn;

	n = 0;
	bufn = 1;
	n = read(fd, buf, BUFFER_SIZE); 
	n = read(fd, buf, BUFFER_SIZE); 
	line_len = 0;
	while (buf[line_len] != '\n' && n != 0 && line_len < BUFFER_SIZE * bufn)
		line_len++;
	//if (line_len == BUFFER_SIZE * bufn)
	//	n = read(fd, buf + line_len, BUFFER_SIZE); 
	line = (char *)malloc((line_len + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < line_len)
	{
		line[i] = buf[i];
		i++;
	} 
	line[i] = '\n';
	if (n > 0)
		return (line); 
	return (NULL);	
}

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*line;
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	printf("%s", line);	
	close(fd);
	return (0);
}

