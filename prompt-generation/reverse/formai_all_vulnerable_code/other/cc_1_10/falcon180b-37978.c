//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF INT_MAX

typedef struct {
    int u, v;
    int w;
} Edge;

int n, m;
int dist[MAX_NODES];
int prev[MAX_NODES];
Edge edges[MAX_EDGES];

void dijkstra(int start) {
    memset(dist, 0x3f, sizeof(dist));
    memset(prev, -1, sizeof(prev));

    dist[start] = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u = -1;
        int min_dist = INF;
        for (int j = 0; j < n; ++j) {
            if (dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        assert(u!= -1);

        for (int j = 0; j < m; ++j) {
            int v = edges[j].u;
            if (v!= u && dist[v] > dist[u] + edges[j].w) {
                dist[v] = dist[u] + edges[j].w;
                prev[v] = u;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges[i] = (Edge){.u = u,.v = v,.w = w};
    }

    int start;
    scanf("%d", &start);

    dijkstra(start);

    for (int i = 0; i < n; ++i) {
        if (prev[i]!= -1) {
            printf("%d -> %d (%d)\n", i, prev[i], dist[i]);
        }
    }

    return 0;
}