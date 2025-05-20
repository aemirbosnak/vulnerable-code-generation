//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 9999

typedef struct vertex {
    int id;
    int x, y;
    struct vertex *parent;
    int g, h, f;
} Vertex;

Vertex *create_vertex(int id, int x, int y) {
    Vertex *vertex = (Vertex *)malloc(sizeof(Vertex));
    vertex->id = id;
    vertex->x = x;
    vertex->y = y;
    vertex->parent = NULL;
    vertex->g = 0;
    vertex->h = 0;
    vertex->f = 0;
    return vertex;
}

bool compare(const void *a, const void *b) {
    Vertex *v1 = (Vertex *)a;
    Vertex *v2 = (Vertex *)b;
    return v1->f < v2->f;
}

void dijkstra(Vertex *start, Vertex *end) {
    int n = 1;
    Vertex **vertices = (Vertex **)malloc(MAX_VERTICES * sizeof(Vertex *));
    vertices[0] = start;
    start->g = 0;
    start->h = heuristic(start, end);
    start->f = start->g + start->h;

    while (n < MAX_VERTICES - 1) {
        int min_f = INF;
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (vertices[i]->f < min_f) {
                min_f = vertices[i]->f;
                u = i;
            }
        }
        if (u == -1)
            break;
        for (int v = 0; v < n; v++) {
            if (v!= u && vertices[v]->parent!= NULL) {
                int new_g = vertices[u]->g + 1;
                if (new_g < vertices[v]->g) {
                    vertices[v]->g = new_g;
                    vertices[v]->parent = vertices[u];
                    vertices[v]->h = heuristic(vertices[v], end);
                    vertices[v]->f = vertices[v]->g + vertices[v]->h;
                }
            }
        }
        n++;
    }

    qsort(vertices, n, sizeof(Vertex *), compare);

    Vertex *current = end;
    while (current->parent!= NULL) {
        current = current->parent;
    }

    printf("Path: ");
    while (current!= start) {
        printf("%d ", current->id);
        current = current->parent;
    }
    printf("%d\n", start->id);
}

int heuristic(Vertex *v1, Vertex *v2) {
    return abs(v1->x - v2->x) + abs(v1->y - v2->y);
}

int main() {
    Vertex *start = create_vertex(1, 0, 0);
    Vertex *end = create_vertex(2, 10, 10);
    dijkstra(start, end);
    return 0;
}