#include "pathfinder.h"

void mx_file_does_not_exist(char *argv[]) {
    char *m_file = argv[1];
    int a = open(m_file, O_RDONLY);

    if (a < 0) {
        close(a);
        mx_printerr("error: file ");
        mx_printerr(m_file);
        mx_printerr(" does not exist\n");
        exit(1);
    }
    close(a);
}
