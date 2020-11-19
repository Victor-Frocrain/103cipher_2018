/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <math.h>

#ifndef MY_H_
#define MY_H_
#define MY_EXIT_ERROR (84)
#define MY_EXIT_SUCCESS (0)

struct base_coordinates_t {
    float a;
    float b;
};

struct matrix_t {
    float **key;
    float **phrase;
    float **encrypted;
};

typedef struct base_coordinates_t base;
typedef struct matrix_t matrix;
int parser(int ac, char **av);
int read_README(char *filepath);
bool str_is_num(char *str);
int encrypte(int ac, char **av, matrix *s);

#endif /* MY_H_ */
