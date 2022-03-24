# include "pipex.h"

static	char	*check_cmd(t_vars *vars, char *cmd)
{
	char	*cmd_tot;
	int		i;

	i = 0;
	while (vars->paths[i])
	{
		cmd_tot = ft_strjoin(vars->paths[i], cmd);
		if (access(cmd_tot, 0) == 0)
			return (cmd_tot);
		free(cmd_tot);
		i++;
	}
	perror("Could not retrieve path\n");
	exit (1);
}

static void	child_two(t_vars *vars, char **envp)
{
	char	*cmd_total;

	if (dup2(vars->fd[1], 0) < 0)
	{
		perror("Duplication failed\n");
		exit(1);
	}
	if (dup2(vars->pipe_end[0], 1) < 0)
	{
		perror("Duplication failed?\n");
		exit(1);
	}
	close(vars->pipe_end[1]);
	close(vars->fd[1]);
	cmd_total = check_cmd(vars, vars->cmd_two[0]);
	printf("This string: %s", cmd_total);
	execve(cmd_total, vars->paths, envp);
	// exit
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
	cmd_total = check_cmd(vars, vars->cmd_one[0]);
	printf("\nThis string finally: %s", cmd_total);
	execve(cmd_total, vars->paths, envp);
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
	vars.cmd[2] = NULL;
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
	ft_free(vars.paths);
	return (0);
}
