#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc/malloc.h>

#include "Libmx/inc/libmx.h"

#define INVALID_USAGE "usage: ./pathfinder [filename]\n"
#define LINE1_IS_INVALID "error: line 1 is not valid\n"
#define INVALID_NUMBER_ISLANDS "error: invalid number of islands\n"
#define MAX 214748

typedef struct      s_main {
    char**          arr_v;
    int             arr_count;
    int             count;
    int**           m_dist;
    int**           m_floyd;
}                   t_main;

typedef struct s_retpath {
    int        size;
    int*       path;
    int        c;
}              t_retpath;

//Struct
void mx_rec_struct(t_main *stct,char *argv[]);
void mx_m_distance(t_main *stct);
void mx_m_floyd(t_main *stct);

//Other function
int main(int argc, char *argv[]);
char **mx_split(const char *s, char c);
char *mx_file_to_str(const char *file);
char **mx_parser(char *s, int j);
int mx_atoi(const char *str);
bool mx_isdigit(int c);
int mx_get_index(t_main *stct, char *c);
void mx_floyd(t_main *stct);
void mx_printmatrix(t_main *stct);
void mx_back_path(t_main *stct, t_retpath *stack);
void mx_int_print(int n);
void mx_ret_trip_output(t_main *stct, t_retpath *stack);
void mx_find_all_paths(t_main *stct, int st, int end);
bool mx_isalpha(int c);

//Error function
void mx_usage(int argc);
void mx_printerr(const char *c);
void mx_line1_is_invalid(char *str, char *line);
void mx_file_does_not_exist(char *argv[]);
void mx_file_is_empty(char *argv[]);

#endif
