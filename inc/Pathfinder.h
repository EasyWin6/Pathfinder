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

int main(int argc, char *argv[]);
char **mx_split(const char *s, char c);
char *mx_file_to_str(const char *file);





#endif
