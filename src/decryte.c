/*
** EPITECH PROJECT, 2018
** decrypte
** File description:
** decrypte
*/

#include "my.h"

void fill_encrypted(matrix *s, char *str)
{
    int x = 0;
    int y = 0;
    int j = 0;
    char *nb = malloc(sizeof(char) * 10);

    for (int i = 0; str[j] && i < 10; j++) {
        if (str[j] != ' ') {
            nb[i] = str[j];
            i++;
        }
        else if (str[j] == ' ') {
            i = 0;
            s->encrypted[y][x] = strtof(nb);
            x++;
            if (x == 3) {
                x = 0;
                y++;
            }
        }
    }
}
