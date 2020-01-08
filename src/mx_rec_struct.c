#include "pathfinder.h"

static void stct_entry(t_main *stct, char **str1);
static void add_to_arr(t_main *stct, char *temp);
static void check_point(t_main *stct);

void mx_rec_struct(t_main *stct, char *argv[]) {
    char *str = mx_file_to_str(argv[1]);
    char **str1 = mx_split(str, '\n');

    stct->count = mx_atoi(str1[0]);
    stct->arr_v = (char **)malloc((stct->count + 1) * sizeof(char *));
    stct->arr_count = 0;
    stct_entry(stct, str1);
}

static void stct_entry(t_main *stct, char **str1) {
    char **temp;

    for (int i = 0; i < stct->count; i++)
        stct->arr_v[i] = NULL;
    for (int j = 1; str1[j]; j++) {
        temp = mx_parser(str1[j]);
        add_to_arr(stct, temp[0]);
        add_to_arr(stct, temp[1]);
    }
}

static void add_to_arr(t_main *stct, char *temp) {
    int sup = 0;

    for (int i = 0; stct->arr_v[i] && i < stct->arr_count; i++) {
        if (mx_strcmp(stct->arr_v[i], temp) == 0)
            sup = -1;
    }
    if (sup == 0) {
        check_point(stct);
        stct->arr_v[stct->arr_count] = mx_strdup(temp);
        stct->arr_count += 1;
    }
}

static void check_point(t_main *stct) {
    if (stct->arr_count >= stct->count) {
        mx_printerr(MX_INVALID_N_ISLANDS);
        exit(1);
    }
}
