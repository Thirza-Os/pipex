# include "pipex.h"

static void child_two(t_vars *vars, char **envp)
{
	char	*cmd_total;
	int		i;

	i = 0;
	if (dup2(vars->pipe_end[0], STDOUT_FILENO) < 0)
	{
		perror("Duplication failed\n");
		exit(1);
	}
	close(vars->pipe_end[1]);
	if (dup2(vars->fd[1], STDIN_FILENO) < 0)
	{
		perror("Duplication failed\n");
		exit(1);
	}
	close(vars->fd[1]);
	while (vars->paths[i])
	{
		cmd_total = ft_strjoin(vars->paths[i], vars->cmd[1]);
		if (cmd_total == NULL)
			exit (1);
		if (execve(cmd_total, vars->paths, envp) < 0)
		{
			perror("Invalid command\n");
			exit(1);
		}
		free(cmd_total);
	i++;
	}
	//exit
}

static void	child_one(t_vars *vars, char **envp)
{
	char	*cmd_total;
	int		i;

	i = 0;
	if (dup2(vars->pipe_end[1], 1) < 0)
	{
		perror("Duplication failed\n");
		exit(1);
	}
	close(vars->pipe_end[0]);
	if (dup2(vars->fd[0], 0) < 0)
	{
		perror("Duplication failed\n");
		exit(1);
	}
	close(vars->fd[0]);
	printf("\nThis string\n");
	while (vars->paths[i])
	{
		cmd_total = ft_strjoin(vars->paths[i], vars->cmd[0]);
		if (cmd_total == NULL)
			exit (1);
		if (execve(cmd_total, vars->paths, envp) < 0)
		{
			perror("Invalid command\n");
			exit(1);
		}
		free(cmd_total);
	i++;
	}
}

static int	pipex(t_vars *vars, char **envp)
{
	if (pipe(vars->pipe_end) < 0)
	{
		perror("Pipe did not succeed\n");
		exit(1);
	}
	vars->child[0] = fork();
	if (vars->child[0] < 0)
		fork_error();
	if (vars->child[0] == 0)
		child_one(vars, envp);
	vars->child[1] = fork();
	if (vars->child[1] < 0)
		fork_error();
	if (vars->child[1] == 0)
		child_two(vars, envp);
	close(vars->pipe_end[0]);
	close(vars->pipe_end[1]);
	waitpid(vars->child[0], NULL, 0);
	waitpid(vars->child[1], NULL, 0);
	return (0);
}

static void	envp_paths(t_vars *vars, char **envp)
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
	vars.cmd[0] = argv[2];
	vars.cmd[1] = argv[3];
	vars.cmd_one = ft_split(argv[2], ' ');
	vars.cmd_two = ft_split(argv[3], ' ');
	vars.fd[0] = open(argv[1], O_RDONLY);
	if (vars.fd[0] < 0)
	{
		perror("Failed to open file\n");
		exit(1);
	}
	vars.fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (vars.fd[1] < 0)
	{
		perror("Failed to open file\n");
		exit(1);
	}
	envp_paths(&vars, envp);
	pipex(&vars, envp);
	// cmd1 = argv[2];
	// cmd2 = argv[3];
	// pipex(fd1, fd2, cmd1, cmd2, envp);
	return (0);
}
