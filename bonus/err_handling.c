/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** print an integer;
*/

#include <stdlib.h>

int check_if_one_line_exist(char *str, char *nbr);
int my_getnbr(char const *str);
int my_strlen(char const *str);

int rows_handling(char *str, char *nbr)
{
    int rows = my_getnbr(nbr);
    int i = 0;

    while (str[i] != '\0') {
        if (str[i + 1] == '\0') {
            break;
        }
        if (str[i] == '\n') {
            rows--;
        }
        i++;
    }
    if (rows != 0) {
        return 84;
    }
    return 0;
}

int diff_char(char *str, char *nbr)
{
    int len = my_strlen(nbr) + 1;

    while (str[len] != '\0') {
        if (str[len] != '.' && str[len] != 'o' && str[len] != '\n') {
            return 84;
        }
        len++;
    }
    return 0;
}

int first_something_else_num(char *str)
{
    int i = 0;

    while (str[i] != '\n') {
        if (str[i] < '0' || str[i] > '9') {
            return 84;
        }
        i++;
    }
    return 0;
}

int wrong_lenght_rows(char *str, int len)
{
    int counter = 0;
    int check = 0;
    int flag = 0;

    while (str[len] != '\0') {
        if (str[len + 1] == '\n' || str[len + 1] == '\0') {
            if (str[len + 1] == '\0')
                break;
            if (check != counter && flag != 0)
                return 84;
            check = counter;
            flag = 1;
            counter = 0;
            len += 2;
        }
        else {
            len++;
            counter++;
        }
    }
    return 0;
}

int err_handling(char *str, char *nbr)
{
    char *s = malloc(sizeof(char) * my_strlen(str) + 1);

    if (first_something_else_num(str) == 84) {
        return 84;
    }
    else if (diff_char(str, nbr) == 84 || rows_handling(str, nbr) == 84) {
        return 84;
    }
    else if (wrong_lenght_rows(str, my_strlen(nbr) + 1) == 84 ||\
    check_if_one_line_exist(str, nbr) == 84) {
        return 84;
    }
    return 0;
}