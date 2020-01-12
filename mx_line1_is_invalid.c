#include "pathfinder.h"

void mx_line1_is_invalid(char *str, char *line) {
    if (!(mx_isdigit(str[0]))) {
        mx_printerr(LINE1_IS_INVALID);
        exit(1);
    }
    for (int i = 0; i < mx_strlen(line); i++) {
        if (!(mx_isdigit(line[i]))) {
            mx_printerr(LINE1_IS_INVALID);
            exit(1);
        }
    }
    if (mx_atoi(line) < 2 || mx_atoi(line) > 10000) {
        mx_printerr(INVALID_NUMBER_ISLANDS);
        exit(1);
    }
}
