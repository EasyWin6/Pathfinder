#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count;

    if (!str || !sub)
        return -1;
    count = 0;
    while (str) {
        str = mx_strstr(str, sub);
            if (str) {
                count++;
                str++;
            }
    }
    return count;
}

