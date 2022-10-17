/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:18:29 by frafal            #+#    #+#             */
/*   Updated: 2022/10/17 17:11:01 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* DELETE BEFORE SUBMISSION */
#include <stdio.h>

void	read_from_fd();
void	get_line();
void	save_extra_char();

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	ssize_t	n;
	size_t	i;
	char	*line;
	size_t	line_len;	
	size_t	bufn;

	static char*	extra_chars;
	extra_chars = "";
	n = 0;
	while (
	n = read(fd, buf, BUFFER_SIZE);
	buf[n] = '\0';
	extra_chars = ft_strjoin(extra_chars, buf);
	return (extra_chars);	
}

#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argc;
	int		fd;
	char	*line;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	printf("%s", line);	
	free(line);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
