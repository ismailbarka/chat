#include "pipex.h"

char *ft_valid_path(char **paths, char *str)
{
    int i = 0;
    if (access(str, X_OK) == 0)
        return (str);
    while (paths[i])
    {
        if(access(ft_strjoin(paths[i], str), X_OK) == 0)
            return (ft_strjoin(paths[i], str));
        i++;
    }
    return (NULL);
}

void check_error(int x,  char *str)
{
    if(x < 0)
    {
        perror(str);
        exit(0);
    }
}