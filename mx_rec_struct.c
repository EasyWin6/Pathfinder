#include "pathfinder.h"

static void stct_entry(t_main *stct, char **str1);
static void add_to_arr(t_main *stct, char *temp);
static void writing_to_mat(t_main *stct, char **temp);
static void check_point(t_main *stct);

void mx_rec_struct(t_main *stct, char *argv[]) {
    char *str = mx_file_to_str(argv[1]);
    char **str1 = mx_split(str, '\n');

    mx_line1_is_invalid(&str[0], str1[0]);
    stct->count = mx_atoi(str1[0]);
    mx_m_distance(stct);
    stct->arr_v = (char **)malloc((stct->count + 1) * sizeof(char *));
    stct->arr_count = 0;
    stct_entry(stct, str1);
    if (stct->arr_count != stct->count) {
        mx_printerr(INVALID_NUMBER_ISLANDS);
        mx_strdel(&str);
        mx_del_strarr(&str1);
        exit(1);
    }
    mx_m_floyd(stct);
    mx_strdel(&str);
    mx_del_strarr(&str1);
}

static void stct_entry(t_main *stct, char **str1) {
    char **temp;

    for (int i = 0; i < stct->count; i++)
        stct->arr_v[i] = NULL;
    for (int j = 1; str1[j]; j++) {
        temp = mx_parser(str1[j], j);
        add_to_arr(stct, temp[0]);
        add_to_arr(stct, temp[1]);
        writing_to_mat(stct, temp);
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
        mx_printerr(INVALID_NUMBER_ISLANDS);
        exit(1);
    }
}

static void writing_to_mat(t_main *stct, char **temp) {
    int s = mx_atoi(temp[2]);
    int a = stct->count;

    stct->m_dist[mx_get_index(stct, temp[0])][mx_get_index(stct, temp[1])] = s;
    stct->m_dist[mx_get_index(stct, temp[1])][mx_get_index(stct, temp[0])] = s;
    mx_del_strarr(&temp);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if ((i != j) && (stct->m_dist[i][j] == 0))
                stct->m_dist[i][j] = MAX;
        }
    }
}
