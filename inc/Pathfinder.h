#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "Libmx/inc/libmx.h"

#define MX_INVALID_N_ISLANDS "invalid number of islands"
#define MX_MAX 21474836

typedef struct      s_main {
    char**          arr_v;
    int             arr_count;
    int             count;
    int**           m_dist;
}                   t_main;

int main(int argc, char *argv[]);
char **mx_split(const char *s, char c);
char *mx_file_to_str(const char *file);
char **mx_parser(char *s, int j);
int mx_atoi(const char *str);
void mx_rec_struct(t_main *stct,char *argv[]);
void mx_printerr(const char *c);
bool mx_isdigit(int c);
int mx_get_index(t_main *stct, char *c);
void mx_m_distance(t_main *stct);
void mx_floyd(t_main *stct);
void mx_printmatrix(t_main *stct);


#endif
