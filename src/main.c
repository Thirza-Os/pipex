# include "pipex.h"

// int ft_child1(int fd1, char *cmd1, int *pipe_end)
// {
    // close(pipe_end[0]);
    // if (dup2(fd1, STDIN_FILENO) < 0)
    //     return (1);
    // if (dup2(pipe_end[1], STDOUT_FILENO) < 0)
    //     return (1);
    // close(fd1);
    //execve
    //exit
// }

// void ft_child2(int fd2, char *cmd2, int *pipe_end)
// {
    // int status;

    // waitpid(-1, &status, 0);
    // if (dup2(fd2, STDIN_FILENO) < 0)
    //     return (1);
    // if (dup2(pipe_end[0], STDOUT_FILENO) < 0)
    //     return (1);
    // close(pipe_end[1]);
    // close(fd2);
    //execve
    //exit
// }

void    ft_pipes(t_vars *vars)
{
    int     status;

    pipe(vars->pipe_end);
    vars->child[0] = fork();
    if (vars->child[0] < 0)
    {
        perror("Fork did not succeed\n");
        exit(1);
    }
    // if (parent1 == 0)
    //     return(ft_child1(fd1, cmd1, pipe_end));
    // parent2 = fork();
    // if (parent2 < 0)
    //     return(perror("Fork: "));
    // if (parent2 == 0)
    //     return(ft_child1(fd1, cmd1, pipe_end));
    // close(pipe_end[0]);
    // close(pipe_end[1]);
    // waitpid(parent1, &status, 0);
    // waitpid(parent2, &status, 0);
}

void    ft_envp_paths(char *envp)
{
    //splitten op = of substr
    //vind de PATH
    //split op :
}

int	main(int argc, char *argv[], char *envp[])
{
    t_vars vars;

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
    ft_envp_paths(envp);
    ft_pipes(&vars);
    
    // cmd1 = argv[2];
    // cmd2 = argv[3];
	// pipex(fd1, fd2, cmd1, cmd2, envp);
    return(0);
}
