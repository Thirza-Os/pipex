# include "pipex.h"

unsigned long	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnstr_last(const char *haystack, const char *needle, size_t len)
{
	unsigned long	a;
	unsigned long	b;

	a = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[a] && len > a)
	{
		if (haystack[a] == needle[0])
		{
			b = 0;
			while (haystack[a + b] == needle[b] && needle[b] && (a + b) < len)
			{
				if (needle[b + 1] == '\0')
					return ((char *)&haystack[b + 1]);
				b++;
			}
		}
		a++;
	}
	return (0);
}

void	fork_error(void)
{
	perror("Fork did not succeed\n");
	exit (1);
}
