//FormAI DATASET v1.0 Category: Graph representation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// struct for a vertex
struct Vertex {
    int id;
    char label;
    bool visited;
};

// graph matrix
int graph[MAX_VERTICES][MAX_VERTICES];

// vertices array
struct Vertex* vertices[MAX_VERTICES];

// vertex count
int vertexCount = 0;

// function to add vertex to the graph
void addVertex(char label) {
    struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
    vertex->id = vertexCount;
    vertex->label = label;
    vertex->visited = false;
    vertices[vertexCount++] = vertex;
}

// function to add edge to the graph
void addEdge(int start, int end) {
    graph[start][end] = 1;
    graph[end][start] = 1;
}

// function to display vertex
void displayVertex(struct Vertex* vertex) {
    printf("%c ", vertex->label);
}

// function for depth first search traversal
void depthFirstSearch(int start) {
    vertices[start]->visited = true;
    displayVertex(vertices[start]);

    // recursion
    for (int i = 0; i < vertexCount; i++) {
        if (graph[start][i] == 1 && vertices[i]->visited == false) {
            depthFirstSearch(i);
        }
    }
}

int main() {
    // add vertices
    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');
    addVertex('E');

    // add edges
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    printf("Depth First Search Traversal: ");
    depthFirstSearch(0);

    return 0;
}