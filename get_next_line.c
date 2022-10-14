/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:18:29 by frafal            #+#    #+#             */
/*   Updated: 2022/10/14 10:55:00 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	void	*buf[BUFFER_SIZE];
	ssize_t	n;
	char	*line;

	n = 0;
	n = read(fd, buf + n, 1); 
	line = (char *)malloc((n + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	line[0] = ((char *)buf)[0];
	line[1] = '\0';
	if (n > 0)
		return (line); 
	return (NULL);	
}

#include <stdio.h>

int	main(void)
{
	char *line = get_next_line(0);
	printf("%s", line);	
	return (0);
}
