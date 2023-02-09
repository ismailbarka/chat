#include "pipex.h"

void ft_first_cmnd_one(char **env, char **av)
{
    char **paths;
    paths = errs(env);
    char **temp = ft_split_two(av[2], ' ');
    char *valid_path = ft_valid_path(paths, temp[0]);
    if(valid_path == NULL)
    {
        write(2, "command not found", 17);
        exit(1);
    }
    execve(valid_path, temp, NULL);
    exit(1);
}

void ft_first_cmnd(int *fd, char **av, char **env)
{
    ft_check_file_access(av[1]);
    int check = open(av[1], O_RDONLY);
    check_error(check, "open error");
    dup2(check, 0);
    dup2(fd[1], 1);
    close(fd[0]);
    close(fd[1]);
    close(check);
    ft_first_cmnd_one(env, av);
}

void ft_middle_cmnd_one(char **av, char **env, int i)
{
    char **paths;
    paths = errs(env);
    char **temp = ft_split_two(av[i + 3], ' ');
    char *valid_path = ft_valid_path(paths, temp[0]);

    if(valid_path == NULL)
    {
        write(2, "command not found", 17);
        exit(1);
    }
    execve(valid_path, temp, NULL);
    exit(1);
}

void ft_middle_cmnd(int *fd, char **av,char **env, int i)
{
    dup2(fd[0], 0);
    dup2(fd[1], 1);
    close(fd[0]);
    close(fd[1]);
    ft_middle_cmnd_one(av, env, i);
}

void ft_last_cmnd_one(char **env, char **av, int i)
{

    char **paths;
    paths = errs(env);
    char **temp = ft_split_two(av[i + 3], ' ');
    char *valid_path = ft_valid_path(paths, temp[0]);

    if(valid_path == NULL)
    {
        write(2, "command not found", 17);
        exit(1);
    }
    execve(valid_path, temp, NULL);
    exit(1);
}

void ft_last_cmnd(int ac, int *fd, char **av, char **env, int i)
{
    int check = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
    if(check == -1)
    {
        write(2, "open err", 9);
    }
    check_error(check, "open error");
    dup2(check, 1);
    dup2(fd[0], 0);
    close(check);
    close(fd[0]);
    close(fd[1]);
    ft_last_cmnd_one(env, av, i);
}