//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct {
    int color;
    int vertex;
} VertexColor;

int colorGraph(int numVertices, int numEdges, int *edges, int *colors, int *numColors) {
    int color = 1;
    int i, j;
    VertexColor *vertices = (VertexColor*)malloc(numVertices * sizeof(VertexColor));
    for (i = 0; i < numVertices; i++) {
        vertices[i].color = -1;
        vertices[i].vertex = -1;
    }
    int *visited = (int*)malloc(numVertices * sizeof(int));
    for (i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }
    int *adj = (int*)malloc(numVertices * sizeof(int));
    for (i = 0; i < numVertices; i++) {
        adj[i] = -1;
    }
    for (i = 0; i < numEdges; i++) {
        int v1 = edges[i * 2];
        int v2 = edges[i * 2 + 1];
        if (visited[v1] == 0 && visited[v2] == 0) {
            if (adj[v1] == -1 && adj[v2] == -1) {
                adj[v1] = v2;
                adj[v2] = v1;
                visited[v1] = 1;
                visited[v2] = 1;
            } else if (adj[v1] == -1 && adj[v2]!= -1) {
                adj[v1] = v2;
                visited[v1] = 1;
            } else if (adj[v1]!= -1 && adj[v2] == -1) {
                adj[v2] = v1;
                visited[v2] = 1;
            } else {
                printf("Error: Adjacent vertices already exist\n");
                return -1;
            }
        }
    }
    int colorCount = 0;
    for (i = 0; i < numVertices; i++) {
        if (visited[i] == 0) {
            colorCount++;
            vertices[colorCount].color = color;
            vertices[colorCount].vertex = i;
            color += 1;
        }
    }
    for (i = 0; i < numVertices; i++) {
        colors[i] = vertices[i].color;
    }
    *numColors = colorCount;
    free(adj);
    free(visited);
    free(vertices);
    return 0;
}

int main() {
    int numVertices = 5;
    int numEdges = 6;
    int edges[] = {0, 1, 2, 3, 4, 5};
    int colors[5];
    int numColors;
    int result = colorGraph(numVertices, numEdges, edges, colors, &numColors);
    if (result == 0) {
        printf("Graph coloring successful!\n");
        for (int i = 0; i < numVertices; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("Graph coloring failed!\n");
    }
    return 0;
}