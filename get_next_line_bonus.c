/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:15:54 by rcaillie          #+#    #+#             */
/*   Updated: 2024/10/24 11:15:54 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*handle_read_error(char *buff, char *left_str)
{
	free(buff);
	free(left_str);
	return (NULL);
}

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (handle_read_error(buff, left_str));
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
		if (!left_str)
			return (handle_read_error(buff, left_str));
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*left_str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str[fd] = ft_read_to_left_str(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_new_left_str(left_str[fd]);
	return (line);
}
