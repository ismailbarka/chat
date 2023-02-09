
#include "pipex.h"

void ft_check_file_access(char *str)
{
    int check = access(str, R_OK);
    check_error(check, "access error");

}