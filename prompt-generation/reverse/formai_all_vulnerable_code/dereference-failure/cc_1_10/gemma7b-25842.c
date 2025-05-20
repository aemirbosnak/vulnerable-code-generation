//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Vertex {
    int index;
    struct Vertex* next;
} Vertex;

Vertex* createVertex(int index) {
    Vertex* vertex = malloc(sizeof(Vertex));
    vertex->index = index;
    vertex->next = NULL;
    return vertex;
}

void addEdge(Vertex* vertex1, Vertex* vertex2) {
    vertex1->next = vertex2;
}

void drawNetwork(Vertex* vertex) {
    printf("Drawing network...\n");
    while (vertex) {
        printf("Vertex %d: ", vertex->index);
        Vertex* neighbor = vertex->next;
        while (neighbor) {
            printf("-> Vertex %d", neighbor->index);
            neighbor = neighbor->next;
        }
        printf("\n");
        vertex = vertex->next;
    }
}

int main() {
    Vertex* head = createVertex(0);
    Vertex* second = createVertex(1);
    Vertex* third = createVertex(2);
    Vertex* fourth = createVertex(3);
    Vertex* fifth = createVertex(4);

    addEdge(head, second);
    addEdge(head, third);
    addEdge(second, fourth);
    addEdge(third, fifth);

    drawNetwork(head);

    return 0;
}