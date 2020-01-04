#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Libmx/inc/libmx.h"

typedef struct      s_main
{
    char**          arr_v;
    int             arr_v_count;
    int**           matr_d;
    int**           matr_a;
    int             v_count;
}                   t_main;

int main(int argc, char *argv[]);
char **mx_split(const char *s, char c);
char *mx_file_to_str(const char *file);
char **mx_parser(char *s);
int mx_atoi(const char *str);
void mx_rec_struct(t_main *stct,char *argv[]);



#endif
