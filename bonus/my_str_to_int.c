/*
** EPITECH PROJECT, 2020
** rush-1-4.c
** File description:
** rush 1 - 4 copy pasta code from 2
*/

int give_right_output(char const *str, int max, int beginning)
{
    if (str[beginning - 1] == '-') {
        return max * (-1);
    } else {
        return max;
    }
}

int checking_max(int array[], int counter, int beginning, char const *str)
{
    int max = 0;
    int temp = counter;
    int thing;
    long int compare = 0;

    for (int x = 0; x < counter; x++) {
        thing = 1;
        for (int potenz = temp; potenz > 1; potenz--) {
            thing = thing * 10;
        }
        max = max + (thing * (array[x] - 48));
        compare = compare + (thing * (array[x] - 48));
        if (max < compare || max > compare || max < 0) {
            return 0;
        }
        temp--;
    }
    return give_right_output(str, max, beginning);
}

int checking_valid(int counter,  char const *str, int beginning)
{
    int array[counter];
    int temp = beginning;

    if (counter > 10) {
        return 0;
    }
    for (int x = 0; x < counter; x++) {
        array[x] = str[beginning];
        beginning++;
    }
    return checking_max(array, counter, temp, str);
}

int my_getnbr_looping(char const *str, int i, int counter)
{
    while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0') {
        counter++,
        i++;
    }
    return counter;
}

int my_getnbr(char const *str)
{
    int counter = 0;
    int beginning = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 48 && str[i] <= 57) {
            beginning = i;
            counter = my_getnbr_looping(str, i, counter);
            break;
        }
    }
    return checking_valid(counter, str, beginning);
}