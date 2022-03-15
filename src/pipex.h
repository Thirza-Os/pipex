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
    pid_t   child[2];
    int     pipe_end[2];
    int     fd[2];
    char    *paths;
}  t_vars;


#endif