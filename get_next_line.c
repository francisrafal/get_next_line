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

ssize_t	read_from_fd(int fd, char **extra_chars)
{
	ssize_t		n;
	ssize_t		i;
	char		*buf;
	char		*tmp;

	n = 1;
	while (n > 0)
	{
		buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buf == NULL)
			return (-1);
		tmp = NULL;
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			free(buf);
			return (-1);
		}
		buf[n] = '\0';
		tmp = ft_strdup(*extra_chars);
		if (*extra_chars != NULL)
			free(*extra_chars);
		*extra_chars = ft_strjoin(tmp, buf);
		free(tmp);
		free(buf);
		i = 0;
		while ((*extra_chars)[i] != '\0')
		{
			if ((*extra_chars)[i] == '\n')
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

char	*get_current_line(char **extra_chars, ssize_t *i)
{
	ssize_t		len;
	char		*line;

	*i = 0;
	while ((*extra_chars)[*i] != '\n' && (*extra_chars)[*i] != '\0')
		(*i)++;
	if ((*extra_chars)[*i] == '\n')
		(*i)++;
	line = (char *)malloc((*i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	len = 0;
	while (len < *i)
	{
		line[len] = (*extra_chars)[len];
		len++;
	}	
	line[len] = '\0';
	return (line);
}

void	save_extra_char(char **extra_chars, ssize_t *i)
{
	char		*tmp;

	if ((*extra_chars)[*i - 1] == '\0')
		tmp = ft_strdup(*extra_chars + *i - 1);
	else
		tmp = ft_strdup(*extra_chars + *i);
	free(*extra_chars);
	*extra_chars = ft_strdup(tmp);
	free(tmp);
}

char	*get_next_line(int fd)
{
	ssize_t		i;
	static char	*extra_chars = NULL;
	char		*line;

	line = NULL;
	if (read_from_fd(fd, &extra_chars) == -1)
		return (NULL);
	if (extra_chars[0] == '\0')
		return (NULL);
	line = get_current_line(&extra_chars, &i);
	save_extra_char(&extra_chars, &i);
	return (line);
}