//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200

typedef struct {
    int vertex1;
    int vertex2;
    double weight;
} Edge;

typedef struct {
    int numVertices;
    int numEdges;
    Edge edges[MAX_EDGE];
} Graph;

int readGraph(Graph *graph) {
    FILE *fp = fopen("graph.txt", "r");
    int i = 0;
    char line[100];
    while (fgets(line, 100, fp)!= NULL) {
        char *token = strtok(line, " ");
        int vertex1 = atoi(token);
        token = strtok(NULL, " ");
        int vertex2 = atoi(token);
        token = strtok(NULL, " ");
        double weight = atof(token);
        graph->edges[i] = (Edge) {vertex1, vertex2, weight};
        i++;
    }
    fclose(fp);
    graph->numVertices = i;
    graph->numEdges = i;
    return 0;
}

int kruskal(Graph *graph, int parent[MAX_VERTEX], int rank[MAX_VERTEX]) {
    int i, j, u, v, w, count = 0;
    Edge edges[MAX_EDGE];
    for (i = 0; i < graph->numEdges; i++) {
        edges[i] = graph->edges[i];
    }
    for (i = 0; i < graph->numVertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    for (i = 0; i < graph->numEdges; i++) {
        u = findParent(parent, edges[i].vertex1);
        v = findParent(parent, edges[i].vertex2);
        if (u!= v) {
            parent[u] = v;
            rank[v]++;
            count++;
        }
    }
    return count;
}

int findParent(int parent[], int vertex) {
    if (parent[vertex] == vertex) {
        return vertex;
    } else {
        return findParent(parent, parent[vertex]);
    }
}

int main() {
    Graph graph;
    int parent[MAX_VERTEX], rank[MAX_VERTEX];
    int numMSTEdges = kruskal(&graph, parent, rank);
    printf("Number of edges in the minimum spanning tree: %d\n", numMSTEdges);
    return 0;
}