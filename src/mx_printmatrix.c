#include "pathfinder.h"

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
