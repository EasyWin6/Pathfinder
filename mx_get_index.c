#include "pathfinder.h"

int mx_get_index(t_main *stct, char *c) {
    for (int i = 0; stct->arr_v[i]; i++) {
        if (mx_strcmp(stct->arr_v[i], c) == 0)
            return i;
    }
    return -1;
}
