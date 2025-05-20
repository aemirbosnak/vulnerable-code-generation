//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int n = 10;
    int k = 3;

    int *v = (int*)malloc(n * sizeof(int));
    int *w = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100;
        w[i] = rand() % 100;
    }

    int *h = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        h[i] = rand() % n;
    }

    int *p = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        p[i] = i;
    }

    int *dist = (int*)malloc(n * sizeof(int));
    int *p_dist = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < n; i++) {
        dist[i] = 1000;
        p_dist[i] = 1000;
    }

    int *p_prev = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        p_prev[i] = -1;
    }

    int *p_flag = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        p_flag[i] = 0;
    }

    int *h_prev = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        h_prev[i] = -1;
    }

    int *visited = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int *visited_count = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        visited_count[i] = 0;
    }

    int *visited_min_count = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        visited_min_count[i] = 1000;
    }

    int *visited_min_count_index = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        visited_min_count_index[i] = -1;
    }

    int *visited_min_distance = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        visited_min_distance[i] = 1000;
    }

    int *visited_min_distance_index = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        visited_min_distance_index[i] = -1;
    }

    for (int i = 0; i < k; i++) {
        if (p[i] == -1) {
            continue;
        }

        visited_count[p[i]]++;
        visited_min_count[p[i]] = visited_count[p[i]];
        visited_min_count_index[p[i]] = i;
        dist[p[i]] = 0;

        for (int j = 0; j < n; j++) {
            if (v[j] == h[i] || w[j] == h[i]) {
                continue;
            }

            if (dist[j] == 1000) {
                continue;
            }

            if (visited_count[j] > visited_min_count[j]) {
                continue;
            }

            if (dist[j] + 1 < dist[p[i]]) {
                dist[p[i]] = dist[j] + 1;
                p_prev[i] = j;
                p_dist[i] = dist[j] + 1;
            }
        }
    }

    int *min_count_index = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        if (p_prev[i] == -1) {
            continue;
        }

        if (visited_min_count[p_prev[i]] < visited_min_count[p[i]]) {
            min_count_index[i] = p_prev[i];
        } else {
            min_count_index[i] = p[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (visited_min_count[i] < visited_min_count_index[i]) {
            visited_min_distance[i] = dist[i];
            visited_min_distance_index[i] = i;
        }
    }

    for (int i = 0; i < k; i++) {
        printf("Node %d has %d neighbors:\n", i, p_dist[i]);
        printf("Node %d has %d neighbors:\n", i, min_count_index[i]);
    }

    printf("Minimum distance is %d and node %d has minimum distance.\n", visited_min_distance[visited_min_distance_index[0]], visited_min_distance_index[0]);

    free(v);
    free(w);
    free(h);
    free(p);
    free(dist);
    free(p_dist);
    free(p_prev);
    free(p_flag);
    free(h_prev);
    free(visited);
    free(visited_count);
    free(visited_min_count);
    free(visited_min_count_index);
    free(visited_min_distance);
    free(visited_min_distance_index);

    return 0;
}