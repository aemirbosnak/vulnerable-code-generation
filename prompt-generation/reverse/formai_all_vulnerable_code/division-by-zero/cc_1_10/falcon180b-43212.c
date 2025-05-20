//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 10000
#define INF 1000000000

typedef struct {
    int id;
    int parent;
    int distance;
} Vertex;

typedef struct {
    int u, v;
    int weight;
} Edge;

int n, m;
Edge edges[MAX_EDGES];
Vertex vertices[MAX_VERTICES];

void dijkstra(int start) {
    int i, j, k, u, v;
    for (i = 0; i <= n; i++) {
        vertices[i].distance = INF;
        vertices[i].parent = -1;
    }
    vertices[start].distance = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m; j++) {
            u = edges[j].u;
            v = edges[j].v;
            if (vertices[u].distance!= INF && vertices[u].distance + edges[j].weight < vertices[v].distance) {
                vertices[v].distance = vertices[u].distance + edges[j].weight;
                vertices[v].parent = u;
            }
        }
    }
}

int main() {
    int i, j, k, u, v, w;
    char filename[50];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the filename: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    for (i = 0; i < m; i++) {
        fscanf(fp, "%d %d %d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].weight = w;
    }
    fclose(fp);
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        vertices[i].id = i;
        vertices[i].distance = INF;
        vertices[i].parent = -1;
    }
    int start = rand() % n;
    dijkstra(start);
    printf("Vertex\tDistance\tPath\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t", i, vertices[i].distance);
        if (vertices[i].parent == -1) {
            printf("-\n");
        } else {
            printf("%d\n", vertices[i].parent);
        }
    }
    return 0;
}