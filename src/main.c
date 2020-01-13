#include "pathfinder.h"

int main(int argc, char *argv[]) {
    t_main stct;
    int b;

    mx_usage(argc);
    mx_file_does_not_exist(argv);
    mx_file_is_empty(argv);
    mx_rec_struct(&stct, argv);
    b = stct.count;
    mx_floyd(&stct);
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b; j++) {
            if (i < j)
               mx_find_all_paths(&stct, i, j);
                //mx_printmatrix(&stct);
        }
    }
    system ("leaks -q pathfinder");
    return 0;
}
