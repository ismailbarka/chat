#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

typedef struct s_vars
{
    char **paths;
    char *file1;
    char *cmd1;
    char *cmd2;
    char *file2;
}   t_vars;

    
    char	**ft_split(const char *s, char c);
    char	**ft_split_two(const char *s, char c);
    char **errs(char **env);
    char	*ft_strjoin(char const *s1, char const *s2);
    char	*ft_strdup(const char *s);
    size_t	ft_strlen(const char *s);
    static char	**str_count(char **str, const char *s, char c);
    static int	word_len(const char *s, char c);
    size_t	ft_strlen(const char *s);
    void	*ft_memcpy(void *dest, const void *src, size_t n);
    static char	*ft_word(const char *s, char c);
    static char	**ft_free_all(char **str);
    int ft_count_pipes(int ac);
    void check_error(int x,  char *str);
    void ft_check_file_access(char *str);
    void ft_first_cmnd(int *fd, char **av, char **env);
    void ft_middle_cmnd(int *fd, char **av,char **env, int i);
    void ft_last_cmnd(int ac, int *fd, char **av, char **env, int i);
    char *ft_valid_path(char **paths, char *str);
    static char	**ft_free_all_two(char **str);
#endif
