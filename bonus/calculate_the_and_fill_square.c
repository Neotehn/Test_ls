/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** print an integer;
*/

#include <stdlib.h>

int my_getnbr(char const *str);
int my_strlen(char const *str);
void displaying_square(char **s, char *str, char *nbr, int len);

void find_the_minimum_number(char **s, int x, int i)
{
    int temp = 0;

    if (s[i][x] >= '1') {
        temp = s[i][x - 1];
        if (s[i - 1][x - 1] < temp) {
            temp = s[i - 1][x - 1];
        }
        if (s[i - 1][x] < temp) {
            temp = s[i - 1][x];
        }
        s[i][x] = s[i][x] + temp - 48;
    }
}

void calculate_highest_if(char **s, int x, int i)
{
    if (s[i][x] == '.') {
        s[i][x] = '1';
    } else {
        s[i][x] = '0';
    }
}

void calculate_highest_square(char **s, char *nbr, int len)
{
    int temp = 0;

    for (int i = 1; i <= my_getnbr(nbr); i++) {
        for (int x = 1; x <= len; x++) {
            calculate_highest_if(s, x, i);
        }
    }
    for (int i = 0; i <= my_getnbr(nbr); i++) {
        for (int x = 0; x <= len; x++) {
            find_the_minimum_number(s, x, i);
        }
    }
}

int filling_two_dimensional_help(char **s, char *str, char *nbr,\
int x, int len, int y)
{
    int temp = 0;

    for (int i = 0; i <= len; i++) {
        temp = i;
        if (x == 0 || i == 0) {
            s[x][i] = '0';
        }
        else if (str[y + my_strlen(nbr) + 1] == '\n') {
            y++;
            i--;
            continue;
        } else {
            s[x][i] = str[y + my_strlen(nbr) + 1];
            y++;
        }
    }
    s[x][temp + 1] = '\0';
    return y;
}

void filling_two_dimensional_arr(char *str, char *nbr,\
long long size, int len)
{
    char **s = malloc(sizeof(char*) * my_getnbr(nbr) + 2);
    int i = 0;
    int y = 0;
    int temp = 0;

    while (i <= my_getnbr(nbr)) {
        s[i] = malloc(sizeof(char) * len + 1);
        i++;
    }
    for (int x = 0; x <= my_getnbr(nbr); x++) {
        y = filling_two_dimensional_help(s, str,\
        nbr, x, len, y);
    }
    calculate_highest_square(s, nbr, len);
    displaying_square(s,str,nbr,len);
}