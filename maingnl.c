/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:31:54 by narrospi          #+#    #+#             */
/*   Updated: 2024/10/07 15:31:57 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error opening file\n", 19);
		return (-1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}*/

int main (int argc, char **argv)
{
	int		fd;
	int		i;
	char 	*line;

	if (argc < 2)
	{
		write(2, "introduce algun texto\n", 22);
		return (-1);		
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			write(2, "Error opening file\n", 19);
			return (-1);
		}
		printf("\n-------%s------\n", argv[i]);
		line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}	
		close(fd);
		i++;
	}
	return (0);
}
