/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:18:29 by frafal            #+#    #+#             */
/*   Updated: 2022/10/20 14:13:16 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* DELETE BEFORE SUBMISSION */
#include <stdio.h>

ssize_t	read_from_fd(int fd, char *extra_chars, char *tmp)
{
	ssize_t		n;
	ssize_t		i;
	char		buf[BUFFER_SIZE];

	n = 1;
	while (n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (-1);
		buf[n] = '\0';
		tmp = ft_strdup(extra_chars);
		extra_chars = ft_strjoin(tmp, buf);
		free(tmp);
		i = 0;
		while (extra_chars[i] != '\0')
		{
			if (extra_chars[i] == '\n')
			{
				i = -1;
				break ;
			}
			i++;	
		}
		if (i == -1)
			break ;
	}
	return (n);
}

void	get_line();
void	save_extra_char();

char	*get_next_line(int fd)
{
	ssize_t		i;
	ssize_t		len;
	static char	*extra_chars = "";
	char		*tmp;
	char		*line;

	line = NULL;
	tmp = NULL;
	if (read_from_fd(fd, extra_chars, tmp) == -1)
		return (NULL);
	if (extra_chars[0] == '\0')
		return (NULL);
	i = 0;
	while (extra_chars[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));	
	if (!line)
		return (NULL);
	len = 0;
	while (len < i)
	{
		line[len] = extra_chars[len];
		len++;
	}	
	line[len] = '\n';
	line[len + 1] = '\0';
	tmp = ft_strdup(extra_chars + i + 1);
	free(extra_chars);
	extra_chars = ft_strdup(tmp);
	free(tmp);		
	return (line);	
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
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
			printf("%s", line);	
	}
	free(line);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
