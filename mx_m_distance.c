#include "pathfinder.h"

void mx_m_distance(t_main *stct) {
    int m = stct->count;

    stct->m_dist = NULL;
    stct->m_dist = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++) {
        stct->m_dist[i] = (int *)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            stct->m_dist[i][j] = 0;
        }
    }
}
