//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Vertex {
    char name;
    struct Vertex* neighbors;
} Vertex;

void mapNetworkTopology(Vertex* vertex) {
    printf("Vertex: %c\n", vertex->name);
    printf("Neighbors:");
    for (Vertex* neighbor = vertex->neighbors; neighbor; neighbor = neighbor->neighbors) {
        printf(", %c", neighbor->name);
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
    vertices[1]->neighbors = vertices[0];

    vertices[2] = malloc(sizeof(Vertex));
    vertices[2]->name = 'C';
    vertices[2]->neighbors = vertices[0];

    vertices[3] = malloc(sizeof(Vertex));
    vertices[3]->name = 'D';
    vertices[3]->neighbors = vertices[1];

    vertices[4] = malloc(sizeof(Vertex));
    vertices[4]->name = 'E';
    vertices[4]->neighbors = vertices[2];

    mapNetworkTopology(vertices[0]);
    mapNetworkTopology(vertices[1]);
    mapNetworkTopology(vertices[2]);
    mapNetworkTopology(vertices[3]);
    mapNetworkTopology(vertices[4]);

    return 0;
}