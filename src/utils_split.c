# include "pipex.h"

char	**ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*pntr;
	int		len;
	int		i;

	len = ft_strlen(s1);
	pntr = (void *)malloc(len + 1);
	if (pntr == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		pntr[i] = s1[i];
		i++;
	}
	pntr[i] = '\0';
	return (pntr);
}
