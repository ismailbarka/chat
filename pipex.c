
#include "pipex.h"

int main(int ac, char **av, char **env)
{
    int i = 0;
    int status;
    int check = 0;
    int fd[2];
    if(ac >= 5)
    {
        pipe(fd);
        check_error(check, "piping error");
        int id = fork();
        check_error(check, "fork error");
        if(id == 0)
        {
            ft_first_cmnd(fd, av, env);  
        }
        waitpid(-1, &status, 0);
        while(i < ac - 5)
        {
            int test = fork();
            if(test == 0)
            {
                write(2, "test", 4);
                ft_middle_cmnd(fd, av, env, i);
            }
            waitpid(-1, &status, 0);
            i++;
        }
        id = fork();
        if(id == 0)
        {
            ft_last_cmnd(ac, fd, av, env, i);
        }
        waitpid(-1, &status, 0);
    }
    else
        return (write(2, "Wrong number of arguments", 26), 1);
}