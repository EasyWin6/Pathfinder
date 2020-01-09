#include "pathfinder.h"

int main(int argc, char* argv[]) {
    (void)argc;
    t_main stct;

    mx_rec_struct(&stct, argv);
    mx_floyd(&stct);
    mx_printmatrix(&stct);
    /*
    for (int i = 0; stct.arr_v[i] != NULL; i++) {
        mx_printstr(stct.arr_v[i]);
        mx_printstr("\n");
    }
     */

    return 0;
}

void mx_printmatrix(t_main *stct) {
    int n = stct->count;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mx_printint(stct->m_dist[i][j]);
            mx_printstr("\t");
        }
        mx_printstr("\n");
    }
}
