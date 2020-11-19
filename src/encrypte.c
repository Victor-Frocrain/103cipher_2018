/*
** EPITECH PROJECT, 2018
** encrypte
** File description:
** encrypte function
*/

#include "my.h"

void matrix_product(matrix *s, int x, int y, int coter)
{
    int a = 0;
    int b = 0;

    for (; a < coter - 1;) {
        s->encrypted[y][x] += s->phrase[y][a] * s->key[b][x];
        a++;
        b++;
    }
}    

int encrypte_message(int ac, char **av, matrix *s, int coter)
{
    int x = 0;
    int y = 0;
    int lenght = strlen(av[1]);
    int result = 0;

    printf("\nEncrypted message:\n");
    for (int i = 0; lenght > result; i++)
        result = (coter - 1) * i;
    s->encrypted = malloc(sizeof(float*) * result);
    s->encrypted[y] = malloc(sizeof(float) * result);
    s->encrypted[y] = memset(s->encrypted[y], 0, result);
    for (int i = 0; i < result; i++) {
        matrix_product(s, x, y, coter);
	printf("%.0f", s->encrypted[y][x]);
        x++;
        if (x == coter - 1) {
            x = 0;
            y++;
            s->encrypted[y] = malloc(sizeof(float) * result);
            s->encrypted[y] = memset(s->encrypted[y], 0, result);
        }
        if ((i + 1) < result)
            printf(" ");
        else
            printf("\n");
    }
}

int compute_message(int ac, char **av, matrix *s, int coter)
{
    int x = 0;
    int y = 0;
    int lenght = strlen(av[1]);
    int result = 0;

    for (int i = 0; lenght > result; i++)
        result = (coter - 1) * i;
    s->phrase = malloc(sizeof(float*) * result);
    s->phrase[y] = malloc(sizeof(float) * result);
    s->phrase[y] = memset(s->phrase[y], 0, result);
    for (int i = 0; i < result; i++) {
        if (i < lenght)
            s->phrase[y][x] = av[1][i];
        x++;
        if (x == coter - 1) {
            x = 0;
            y++;
            s->phrase[y] = malloc(sizeof(float) * result);
            s->phrase[y] = memset(s->phrase[y], 0, result);
        }
    }
    encrypte_message(ac, av, s, coter);
}

int encrypte(int ac, char **av, matrix *s)
{
    int x = 0;
    int y = 0;
    int lenght = strlen(av[2]);
    int result = 0;
    int coter = 0;

    printf("Key matrix:\n");
    for (coter; lenght > result; coter++)
        result = coter * coter;
    s->key = malloc(sizeof(float*) * result);
    s->key[y] = malloc(sizeof(float) * result);
    s->key[y] = memset(s->key[y], 0, result);
    for (int i = 0; i < result; i++) {
        if (i < lenght)
            s->key[y][x] = av[2][i];
        printf("%.0f", s->key[y][x]);
        x++;
        if (x == coter - 1) {
            printf("\n");
            x = 0;
            y++;
            s->key[y] = malloc(sizeof(float) * result);
            s->key[y] = memset(s->key[y], 0, result);
        }
        else if (i + 1 < result)
            printf("\t");
    }
    compute_message(ac, av, s, coter);
}

