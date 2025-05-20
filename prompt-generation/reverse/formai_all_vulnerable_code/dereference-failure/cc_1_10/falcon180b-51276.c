//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 500

typedef struct {
    int node;
    int weight;
    struct node* next;
} node;

typedef struct {
    int start;
    int end;
    int distance;
    node* path;
} path;

void createGraph(int nodes, int edges) {
    int i, j;
    node* graph[MAX_NODES];
    for (i = 0; i < nodes; i++) {
        graph[i] = NULL;
    }
    for (i = 0; i < edges; i++) {
        int start, end, weight;
        scanf("%d %d %d", &start, &end, &weight);
        node* newNode = (node*)malloc(sizeof(node));
        newNode->node = end;
        newNode->weight = weight;
        newNode->next = graph[start]->next;
        graph[start]->next = newNode;
    }
}

void dijkstra(int start, int end) {
    int i, j;
    path* paths[MAX_NODES];
    for (i = 0; i < MAX_NODES; i++) {
        paths[i] = NULL;
    }
    path* currentPath = (path*)malloc(sizeof(path));
    currentPath->start = start;
    currentPath->end = end;
    currentPath->distance = 0;
    currentPath->path = NULL;
    paths[start] = currentPath;

    for (i = 1; i < MAX_NODES; i++) {
        for (j = 0; j < i; j++) {
            if (paths[j]!= NULL && paths[j]->distance + 1 < paths[i]->distance) {
                paths[i]->distance = paths[j]->distance + 1;
                paths[i]->path = paths[j]->path;
            }
        }
    }

    printf("Shortest Path: ");
    node* pathNode = paths[end]->path;
    while (pathNode!= NULL) {
        printf("%d ", pathNode->node);
        pathNode = pathNode->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int nodes, edges;
    scanf("%d %d", &nodes, &edges);
    node* graph[MAX_NODES];
    createGraph(nodes, edges);

    int start, end;
    scanf("%d %d", &start, &end);
    dijkstra(start, end);

    return 0;
}