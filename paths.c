#include "pipex.h"

char *ft_path(char **str)
{
    int i = 0;
    while (str[i])
    {
        if(str[i][0] == 'P' && str[i][1] == 'A' && str[i][2] == 'T')
            return(&str[i][5]);
        i++;
    }
    return(NULL);
}

char **errs(char **env)
{
    char **paths = ft_split(ft_path(env), ':');
    return paths;
}