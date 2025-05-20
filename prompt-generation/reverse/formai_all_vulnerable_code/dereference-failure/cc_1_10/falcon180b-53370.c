//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int x, y;
} Point;

void dijkstra(int start, int end, Point** points, int n) {
    int i, j;
    int dist[n];
    int prev[n];
    int u, v;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        u = -1;
        for (j = 0; j < n; j++) {
            if (dist[j] < dist[u]) {
                u = j;
            }
        }

        if (u == -1) {
            break;
        }

        for (j = 0; j < n; j++) {
            v = j;
            if (j == u) {
                continue;
            }

            if (dist[u] + points[u]->x - points[v]->x < dist[v]) {
                dist[v] = dist[u] + points[u]->x - points[v]->x;
                prev[v] = u;
            }
        }
    }

    printf("Shortest path from %d to %d:\n", start, end);
    if (dist[end] == INF) {
        printf("No path found.\n");
    } else {
        int path[n];
        int k = end;
        int l = 0;

        while (k!= -1) {
            path[l++] = k;
            k = prev[k];
        }

        printf("Path: ");
        for (i = l - 1; i >= 0; i--) {
            printf("%d ", path[i]);
        }
        printf("\n");
    }
}

int main() {
    Point* points = malloc(sizeof(Point) * 5);
    points[0] = (Point) {.x = 0,.y = 0};
    points[1] = (Point) {.x = 1,.y = 0};
    points[2] = (Point) {.x = 2,.y = 0};
    points[3] = (Point) {.x = 1,.y = 1};
    points[4] = (Point) {.x = 2,.y = 1};

    int n = 5;
    int start = 0;
    int end = 4;

    dijkstra(start, end, points, n);

    free(points);

    return 0;
}