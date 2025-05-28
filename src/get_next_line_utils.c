#include "../include/get_next_line.h"

/**
 * @brief Joins two strings into a new string and frees the first string
 * 
 * This function concatenates s1 and s2 into a new string. If s1 is NULL,
 * it's treated as an empty string. The function frees s1 regardless of
 * success or failure.
 * 
 * @param s1 First string (will be freed)
 * @param s2 Second string
 * @return Newly allocated string with s1+s2, or NULL on failure
 */
char	*ft_strjoiner(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	ft_free(&s1);
	return (str);
}

/**
 * @brief Calculates the length of a string
 * 
 * This function counts the number of characters in a string until
 * the null terminator is found.
 * 
 * @param str String to measure
 * @return Length of the string
 */
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/**
 * @brief Locates the first occurrence of a character in a string
 * 
 * This function searches for the first occurrence of the character
 * 'needle' in the string 'stack'.
 *
 * @param stack String to search in
 * @param needle Character to find (converted to char)
 * @return Pointer to the found character, or NULL if not found
 */
char	*ft_strchr(const char *stack, int needle)
{
	while (*stack && *stack != (char)needle)
		stack++;
	if (*stack == (char)needle)
		return ((char *)stack);
	return (NULL);
}

/**
 * @brief Extracts a substring from a given string
 * 
 * Creates a new string that is a substring of 's', starting at index 'start'
 * and with a maximum length of 'len'. Handles boundary conditions and
 * allocates appropriate memory.
 *
 * @param s Original string
 * @param start Starting index
 * @param len Maximum length of substring
 * @return New substring, or NULL on failure
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	slen;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		len = 0;
	if ((slen - start) < len)
		len = slen - start;
	subs = (char *)malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	while ((start + i) < slen && i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

/**
 * @brief Frees memory allocated for a string and sets pointer to NULL
 * 
 * This utility function safely frees memory pointed to by a string
 * pointer and sets the pointer to NULL to prevent use after free.
 * 
 * @param str Pointer to the string to be freed
 * @return NULL pointer for convenience in return statements
 */
char	*ft_free(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	return (NULL);
}
