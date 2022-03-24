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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;

	if (s1 == 0 || s2 == 0)
		return (0);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	a = 0;
	b = 0;
	while (s1[a])
	{
		str[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		str[a] = s2[b];
		a++;
		b++;
	}
	str[a] = '\0';
	return (str);
}

void	envp_paths(t_vars *vars, char **envp)
{
	int		i;
	char	*start;
	int		len;

	i = 0;
	start = NULL;
	while (envp[i] && start == NULL)
	{
		len = ft_strlen(envp[i]);
		start = ft_strnstr_last(envp[i], "PATH=", len);
		i++;
	}
	vars->paths = ft_split_add_slash(start, ':');
}
