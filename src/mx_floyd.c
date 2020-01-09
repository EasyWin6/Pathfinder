#include "pathfinder.h"

void mx_floyd(t_main *stct) {
    int n = stct->count;
    int new_dist;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                new_dist = stct->m_dist[i][k] + stct->m_dist[k][j];
                if (new_dist < stct->m_dist[i][j])
                    stct->m_dist[i][j] = new_dist;
            }
        }
    }
}
