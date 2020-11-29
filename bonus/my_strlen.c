/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** print an integer;
*/

int my_strlen(char const *str)
{
    int index = 0;

    while (str[index] != '\0') {
        index++;
    }
    return index;
}