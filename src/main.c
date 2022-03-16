# include "pipex.h"

// int child_one(t_vars vars)
// {
	// close(pipe_end[0]);
	// if (dup2(fd1, STDIN_FILENO) < 0)
	//	 return (1);
	// if (dup2(pipe_end[1], STDOUT_FILENO) < 0)
	//	 return (1);
	// close(fd1);
	//execve
	//exit
// }

// int child_two(t_vars vars)
// {
	// int status;

	// waitpid(-1, &status, 0);
	// if (dup2(fd2, STDIN_FILENO) < 0)
	//	 return (1);
	// if (dup2(pipe_end[0], STDOUT_FILENO) < 0)
	//	 return (1);
	// close(pipe_end[1]);
	// close(fd2);
	//execve
	//exit
// }

static void	ft_pipes(t_vars *vars)
{
	int	status;

	if (pipe(vars->pipe_end) < 0)
	{
		perror("Pipe did not succeed\n");
		exit(1);
	}
	vars->child[0] = fork();
	if (vars->child[0] < 0)
		fork_error(void);
	if (child[0] == 0)
		 return(child_one(vars);
	child[1] = fork();
	if (child[1] < 0)
		fork_error(void);
	if (child[1] == 0)
		 return(child_two(vars));
	// close(vars->pipe_end[0]);
	// close(vars->pipe_end[1]);
	// waitpid(child[0], &status, 0);
	// waitpid(child[1], &status, 0);
}

static void	ft_envp_paths(t_vars *vars, char **envp)
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
	vars->paths = ft_split(start, ':');
}

int	main(int argc, char *argv[], char *envp[])
{
	t_vars	vars;

	if (argc != 5)
	{
		perror("Not enough arguments\n");
		exit(1);
	}
	vars.fd[0] = open(argv[1], O_RDONLY);
	vars.fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (vars.fd[0] < 0 || vars.fd[1] < 0)
	{
		perror("Failed to open file\n");
		exit(1);
	}
	ft_envp_paths(&vars, envp);
	ft_pipes(&vars);
	// cmd1 = argv[2];
	// cmd2 = argv[3];
	// pipex(fd1, fd2, cmd1, cmd2, envp);
	return(0);
}
