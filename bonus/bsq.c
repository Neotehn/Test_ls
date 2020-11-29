/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** print an integer;
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int err_handling(char *str, char *nbr);
int my_strlen(char const *str);
void filling_two_dimensional_arr(char *str, char *nbr,\
long long size, int len);

int storing_prepared_str(char *str, char *nbr, int len)
{
    int x = 0;
    int i = 0;
    int check = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            check += 1;
        }
        if (check == 0) {
            nbr[x] = str[i];
            x++;
        }
        if (check == 1 && str[i] != '\n') {
            len++;
        }
        i++;
    }
    nbr[x] = '\0';
    return len;
}

int check_if_one_line_exist(char *str, char *nbr)
{
    int len = my_strlen(nbr) + 1;

    if (str[len] == '\0') {
        return 84;
    }
    return 0;
}

int displaying_input(int fd, long long size)
{
    char *str = malloc(sizeof(char) * size + 1);
    char *nbr = malloc(sizeof(char) * size + 1);
    int check = 0;
    int len = 0;

    read(fd,str,size);
    len = storing_prepared_str(str, nbr, len);
    if (err_handling(str, nbr) == 84) {
        return 84;
    }
    filling_two_dimensional_arr(str, nbr, size, len);
    return 0;
}

int main(int ac, char *av[])
{
    char *filename = av[1];
    struct stat sb;
    int fd = open(filename,O_RDONLY);

    if (stat(filename,&sb) == 84) {
        return 84;
    }
    if (displaying_input(fd, sb.st_size) == 84) {
        return 84;
    }
    return 0;
}
