#include "pathfinder.h"

int main(int argc, char* argv[]) {
    (void)argc;
    t_main stct;

    mx_rec_struct(&stct, argv);
    for (int i = 0; stct.arr_v[i] != NULL; i++) {
        mx_printstr(stct.arr_v[i]);
        mx_printstr("\n");
    }
    int b = mx_get_index(&stct, "b");
    printf("%d", b);
    return 0;
}
