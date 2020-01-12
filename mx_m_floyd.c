#include "pathfinder.h"

void mx_m_floyd(t_main *stct) {
    int m = stct->count;

    stct->m_floyd = NULL;
    stct->m_floyd = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++) {
        stct->m_floyd[i] = (int *)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            stct->m_floyd[i][j] = stct->m_dist[i][j];
        }
    }
}
