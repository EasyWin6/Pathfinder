#include "pathfinder.h"

static void print_err_line(int t);

char **mx_parser(char *s, int j) {
    int a = mx_get_char_index(s, '-');
    int b = mx_get_char_index(s, ',');
    int len_s = mx_strlen(s);
    char **n_str = (char **)malloc(4 * sizeof(char *));

    if (a < 0 || b < 0 || len_s < 5)
        print_err_line(j + 1);
    n_str[0] = mx_strndup(s, a);
    n_str[1] = mx_strndup((s + a + 1), (b - a - 1));
    n_str[2] = mx_strndup((s + b + 1), (len_s - b));
    n_str[3] = NULL;
    return n_str;
}

static void print_err_line(int t) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(t));
    mx_printerr(" is not valid\n");
    exit(1);
}
