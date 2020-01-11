#include "pathfinder.h"

int main(int argc, char* argv[]) {
    t_main stct;

    mx_usage(argc);
    mx_file_does_not_exist(argv);
    mx_file_is_empty(argv);
    mx_rec_struct(&stct, argv);

    mx_floyd(&stct);
    mx_printmatrix(&stct);
    return 0;
}
