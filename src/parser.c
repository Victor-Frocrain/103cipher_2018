/*
** EPITECH PROJECT, 2018
** parser
** File description:
** parser function
*/

#include "my.h"

int read_README(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buff = malloc(sizeof(char) * 500);

    read(fd, buff, 500);
    printf("%s", buff);
    free(buff);
    close(fd);
}

bool str_is_num(char *str)
{
    for (int i = 0; str[i]; i++)
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
            return (false);
    return (true);
}

int parser(int ac, char **av)
{
    matrix *s = malloc(sizeof(matrix));

    if (ac == 4) {
        if ((strcmp(av[3], "1") == 0) && str_is_num(av[1]) == true) {
            return MY_EXIT_SUCCESS;
        }
        else if (strcmp(av[3], "0") == 0) {
            encrypte(ac, av, s);
            return MY_EXIT_SUCCESS;
        }
    }
    else if (ac == 2) {
        if (strcmp(av[1], "-h") == 0) {
            read_README("README");
            return MY_EXIT_SUCCESS;
        }
    }
    return MY_EXIT_ERROR;
}
