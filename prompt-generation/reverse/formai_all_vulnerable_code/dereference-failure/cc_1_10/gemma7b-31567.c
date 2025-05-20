//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Vertex {
    char name;
    struct Vertex* neighbors;
} Vertex;

void map_topology(Vertex* v) {
    printf("%c:", v->name);
    for (Vertex* neighbor = v->neighbors; neighbor; neighbor = neighbor->neighbors) {
        printf(" - %c", neighbor->name);
    }
    printf("\n");
}

int main() {
    Vertex* vertices[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        vertices[i] = NULL;
    }

    vertices[0] = malloc(sizeof(Vertex));
    vertices[0]->name = 'A';
    vertices[0]->neighbors = NULL;

    vertices[1] = malloc(sizeof(Vertex));
    vertices[1]->name = 'B';
    vertices[1]->neighbors = NULL;

    vertices[2] = malloc(sizeof(Vertex));
    vertices[2]->name = 'C';
    vertices[2]->neighbors = NULL;

    vertices[3] = malloc(sizeof(Vertex));
    vertices[3]->name = 'D';
    vertices[3]->neighbors = NULL;

    vertices[4] = malloc(sizeof(Vertex));
    vertices[4]->name = 'E';
    vertices[4]->neighbors = NULL;

    vertices[0]->neighbors = vertices[1];
    vertices[0]->neighbors = vertices[2];
    vertices[1]->neighbors = vertices[3];
    vertices[2]->neighbors = vertices[4];

    map_topology(vertices[0]);
    map_topology(vertices[1]);
    map_topology(vertices[2]);

    return 0;
}