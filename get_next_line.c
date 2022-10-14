/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:18:29 by frafal            #+#    #+#             */
/*   Updated: 2022/10/14 11:25:18 by frafal           ###   ########.fr       */
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

	n = 0;
	n = read(fd, buf, BUFFER_SIZE); 
	line_len = 0;
	while (buf[line_len] != '\n' && n != 0 && line_len < BUFFER_SIZE)
		line_len++;
	
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

int	main(void)
{
	char	*line = get_next_line(0);
	printf("%s", line);	
	return (0);
}
