#include "../include/get_next_line.h"

/**
 * @brief Reads and returns the next line from a file descriptor
 * 
 * This function reads from a file descriptor and returns one line at a time.
 * It uses a static variable to keep track of any remaining text between
 * function calls. The line returned will include the newline character if
 * present in the file.
 * 
 * @param fd The file descriptor to read from
 * @return The next line from the file, or NULL if there's an error or EOF
 */
char	*get_next_line(int fd)
{
	static char	*holder;
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((holder && !ft_strchr(holder, '\n')) || !holder)
		holder = ft_read_till_n(fd, holder);
	if (!holder)
		return (NULL);
	line = ft_get_line(holder);
	if (!line)
		return (ft_free(&holder));
	holder = ft_subs_line_from_holder(holder);
	return (line);
}

/**
 * @brief Reads from file descriptor until newline character is found
 * 
 * This function reads data from a file descriptor in chunks of BUFFER_SIZE
 * until a newline character is encountered or EOF is reached. It appends
 * the read data to the holder string.
 * 
 * @param fd The file descriptor to read from
 * @param holder String that stores leftover text between calls
 * @return Updated holder string with newly read content
 */
char	*ft_read_till_n(int fd, char *holder)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&holder));
	buffer[0] = '\0';
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			holder = ft_strjoiner(holder, buffer);
		}
	}
	free(buffer);
	if (bytes_read == -1)
		return (ft_free(&holder));
	return (holder);
}

/**
 * @brief Extracts a complete line (up to newline) from holder
 * 
 * This function finds the position of the first newline character
 * in the holder string and extracts everything up to and including
 * that newline into a new string.
 * 
 * @param holder String containing text read from file
 * @return A newly allocated string with the current line
 */
char	*ft_get_line(char *holder)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(holder, '\n');
	len = (ptr - holder) + 1;
	line = ft_substr(holder, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

/**
 * @brief Updates holder by removing the line that was just returned
 * 
 * After extracting a line with ft_get_line, this function updates the
 * holder to contain only the remaining text (after the newline). This
 * ensures that subsequent calls to get_next_line continue from the
 * correct position.
 * 
 * @param holder String containing text read from file
 * @return Updated holder without the line that was returned
 */
char	*ft_subs_line_from_holder(char *holder)
{
	char	*new_holder;
	char	*ptr;
	int		len;

	ptr = ft_strchr(holder, '\n');
	if (!ptr)
	{
		new_holder = NULL;
		return (ft_free(&holder));
	}
	else
		len = (ptr - holder) + 1;
	if (!holder[len])
		return (ft_free(&holder));
	new_holder = ft_substr(holder, len, ft_strlen(holder) - len);
	ft_free(&holder);
	if (!new_holder)
		return (NULL);
	return (new_holder);
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/