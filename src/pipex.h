#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>

typedef struct s_vars
{
	int		fd[2];
	char	*cmd[2];
	pid_t	child[2];
	int		pipe_end[2];
	char	**paths;
}	t_vars;

unsigned long	ft_strlen(const char *s);
char			*ft_strnstr_last(const char *haystack, \
				const char *needle, size_t len);
void			fork_error(void);
char			**ft_split(char const *s, char c);
char			**ft_free(char **arr);
char			*ft_strdup(const char *s1);

#endif