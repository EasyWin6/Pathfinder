#include "pathfinder.h"

char **mx_parser(char *s) {
    int a = mx_get_char_index(s, '-');
    int b = mx_get_char_index(s, ',');
    int len_s = mx_strlen(s);
    char **n_str = (char **)malloc(4 * sizeof(char *));

    n_str[0] = mx_strndup(s, a);
    n_str[1] = mx_strndup((s + a + 1), (b - a - 1));
    n_str[2] = mx_strndup((s + b + 1), (len_s - b));
    n_str[3] = NULL;
    return n_str;
}
