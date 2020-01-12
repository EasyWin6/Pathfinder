#include "pathfinder.h"

static void print_err_line(int t);
static bool check_name(char *s);
static bool check_dist(char *s);

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
    if (!(check_name(n_str[0])) || !(check_name(n_str[1])) ||
        !(check_dist(n_str[2])) || (mx_strcmp(n_str[0], n_str[1]) == 0) ||
        ((mx_strcmp(n_str[0], n_str[1]) != 0) && mx_atoi(n_str[2]) == 0))
    {
        mx_del_strarr(&n_str);
        print_err_line_n(j + 1);
    }
    return n_str;
}

static void print_err_line(int t) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(t));
    mx_printerr(" is not valid\n");
    exit(1);
}

static bool check_name(char *s) {
    int len_s = mx_strlen(s);

    if (len_s == 0)
        return 0;
    for (int i = 0; i < len_s - 1; i++) {
        if (!mx_isalpha(s[i]))
            return 0;
    }
    return 1;
}

static bool check_dist(char *s) {
    int len_s = mx_strlen(s);

    if (len_s == 0)
        return 0;
    for (int i = 0; i < len_s; i++) {
        if (!mx_isdigit(s[i]))
            return 0;
    }
    if (mx_atoi(s) > MAX - 1)
        return 0;
    return 1;
}
