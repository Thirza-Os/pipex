# include "pipex.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pntr;
	int		a;
	size_t	s_len;

	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len > len)
		s_len = len;
	pntr = (char *)malloc(s_len + 1);
	if (pntr == 0)
		return (0);
	a = 0;
	while (s_len > 0)
	{
		pntr[a] = s[start];
		a++;
		start++;
		s_len--;
	}
	pntr[a] = '\0';
	return (pntr);
}

static int	ft_count_length(char const *s, char c)
{
	int	a;

	a = 0;
	while (s[a] && s[a] != c)
		a++;
	return (a);
}

static int	ft_count_splits(char const *s, char c)
{
	int	count;
	int	a;

	count = 0;
	while (*s)
	{
		a = ft_count_length(s, c);
		if (a > 0)
		{
			count++;
			s += a;
		}
		else
			(s++);
	}
	return (count);
}

static char	**ft_make_splits(char const *s, char **arr, char c)
{
	int	sub;
	int	sub_count;

	sub_count = 0;
	while (*s)
	{
		sub = ft_count_length(s, c);
		if (sub > 0)
		{
			arr[sub_count] = ft_substr(s, 0, sub);
			if (arr[sub_count] == 0)
				return (ft_free(arr));
			sub_count++;
			s += sub;
		}
		else
			(s++);
	}
	arr[sub_count] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{	
	int		count;
	char	**arr;

	if (s == 0)
		return (0);
	count = ft_count_splits(s, c);
	arr = (char **)malloc((count + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr = ft_make_splits(s, arr, c);
	return (arr);
}
