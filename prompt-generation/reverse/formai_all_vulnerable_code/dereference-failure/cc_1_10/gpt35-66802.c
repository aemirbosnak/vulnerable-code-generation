//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4 // number of vertices

typedef struct vertex {
    int vNum;
    int color;
    struct vertex* next;
} Vertex;

Vertex* createVertex(int vNum) {
    Vertex* vertex = (Vertex*) malloc(sizeof(Vertex));
    vertex->vNum = vNum;
    vertex->color = -1;
    vertex->next = NULL;
    
    return vertex;
}

void addEdge(Vertex* adjList[], int u, int v) {
    Vertex* vertex = createVertex(v);
    vertex->next = adjList[u]->next;
    adjList[u]->next = vertex;
    
    vertex = createVertex(u);
    vertex->next = adjList[v]->next;
    adjList[v]->next = vertex;
}

bool isSafe(Vertex* adjList[], int v, int color, int result[]) {
    Vertex* current = adjList[v]->next;
    while (current != NULL) {
        if (result[current->vNum] == color) {
            return false;
        }
        current = current->next;
    }
    return true;
}

bool graphColor(Vertex* adjList[], int v, int numColors, int result[]) {
    if (v == V) {
        return true;
    }
    
    for (int c = 0; c < numColors; c++) {
        if (isSafe(adjList, v, c, result)) {
            result[v] = c;
            if (graphColor(adjList, v+1, numColors, result)) {
                return true;
            }
            result[v] = -1;
        }
    }
    return false;
}

void printResult(int result[]) {
    printf("The minimum number of colors required: %d\n", result[V-1]+1);
    printf("Vertex colors: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", result[i]+1);
    }
    printf("\n");
}

int main() {
    Vertex* adjList[V];
    int result[V];
    
    for (int i = 0; i < V; i++) {
        adjList[i] = createVertex(i);
        result[i] = -1;
    }
    
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 3);
    
    int numColors = 3;
    
    if (graphColor(adjList, 0, numColors, result)) {
        printResult(result);
    } else {
        printf("Coloring is not possible with %d colors.", numColors);
    }
    
    return 0;
}