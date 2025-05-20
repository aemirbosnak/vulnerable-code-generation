//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Vertex {
    char name[MAX_VERTICES];
    struct Vertex* adjacentVertices[MAX_VERTICES];
} Vertex;

void draw_topology(Vertex* vertex) {
    printf("%s:", vertex->name);
    for (Vertex* adjacentVertex = vertex->adjacentVertices; adjacentVertex; adjacentVertex = adjacentVertex->adjacentVertices) {
        printf(" - %s", adjacentVertex->name);
    }
    printf("\n");
}

int main() {
    Vertex* vertices[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        vertices[i] = NULL;
    }

    vertices[0] = malloc(sizeof(Vertex));
    vertices[0]->name[0] = 'A';
    vertices[0]->adjacentVertices[0] = vertices[2];
    vertices[0]->adjacentVertices[1] = vertices[3];

    vertices[1] = malloc(sizeof(Vertex));
    vertices[1]->name[0] = 'B';
    vertices[1]->adjacentVertices[0] = vertices[0];

    vertices[2] = malloc(sizeof(Vertex));
    vertices[2]->name[0] = 'C';
    vertices[2]->adjacentVertices[0] = vertices[0];

    vertices[3] = malloc(sizeof(Vertex));
    vertices[3]->name[0] = 'D';
    vertices[3]->adjacentVertices[0] = vertices[0];
    vertices[3]->adjacentVertices[1] = vertices[2];

    draw_topology(vertices[0]);
    draw_topology(vertices[1]);
    draw_topology(vertices[2]);
    draw_topology(vertices[3]);

    return 0;
}