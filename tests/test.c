#include "../include/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/**
 * @brief Test program for get_next_line
 * 
 * This program demonstrates how to use the get_next_line function
 * to read a file line by line. Pass a filename as a command line 
 * argument to read that file.
 */

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		line_count;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file %s\n", argv[1]);
		return (1);
	}
	line_count = 0;
	printf("Reading file: %s\n", argv[1]);
	printf("------------------------------\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s", ++line_count, line);
		if (line[ft_strlen(line) - 1] != '\n')
			printf("\n");
		free(line);
	}
	printf("------------------------------\n");
	printf("Total lines: %d\n", line_count);
	close(fd);
	return (0);
}
