/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** print an integer;
*/

#include <unistd.h>

int my_getnbr(char const *str);

void my_putchar(char c)
{
    write(1,&c,1);
}

void store_the_first_square(char **s, int x, int i, int max)
{
    for (int y = max - 1; y >= 0; y--) {
        for (int z = max - 1; z >= 0; z--) {
            s[x-y][i-z] = 'x';
        }
    }
}

int displaying_square_loop(char **s, int max, int flag, int x)
{
    int i = 1;

    while (s[x][i] != '\0') {
        if ((s[x][i] == max + 48) && flag == 0 && max != 0) {
                store_the_first_square(s, x, i, max);
                flag = 1;
        }
        else if (s[x][i] > '0') {
            s[x][i] = '.';
        } else {
            s[x][i] = 'o';
        }
        i++;
    }
    return flag;
}

int displaying_square_help(char **s, char *nbr, int max, int x)
{
    int i = 1;

    while (s[x][i] != '\0') {
        if (s[x][i] > (max + 48)) {
            max = s[x][i] - 48;
        }
        i++;
    }
    return max;
}

void displaying_square(char **s, char *str, char *nbr, int len)
{
    int max = 0;
    int flag = 0;
    int i = 1;

    for (int x = 1; x <= my_getnbr(nbr); x++) {
        max = displaying_square_help(s, nbr, max, x);
    }
    for (int x = 1; x <= my_getnbr(nbr); x++) {
        flag = displaying_square_loop(s, max, flag, x);
    }
    for (int x = 1; x <= my_getnbr(nbr); x++) {
        i = 1;
        while (s[x][i] != '\0') {
            my_putchar(s[x][i]);
            i++;
        }
        my_putchar('\n');
    }
}