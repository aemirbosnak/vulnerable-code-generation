//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int to;
    int weight;
    struct Edge *next;
} Edge;

typedef struct Vertex {
    int value;
    Edge *edges;
} Vertex;

Vertex towns[2];  // Our two towns, Bridgeville and Riverstone

void add_edge(Vertex *town, int to, int weight) {
    Edge *edge = malloc(sizeof(Edge));
    edge->to = to;
    edge->weight = weight;
    edge->next = town->edges;
    town->edges = edge;
}

void print_town(Vertex *town) {
    printf("Town: %d\n", town->value);
    Edge *edge = town->edges;
    while (edge) {
        printf("Edge to %d (weight: %d)\n", edge->to, edge->weight);
        edge = edge->next;
    }
    printf("\n");
}

int main() {
    // Create our towns
    towns[0].value = 1;  // Bridgeville
    towns[1].value = 2;  // Riverstone

    // Add roads between them
    add_edge(&towns[0], 1, 10);
    add_edge(&towns[0], 2, 20);
    add_edge(&towns[1], 0, 10);
    add_edge(&towns[1], 1, 30);
    add_edge(&towns[1], 2, 40);

    // Visit and explore each town
    printf("Bridgeville:\n");
    print_town(&towns[0]);
    printf("\nRiverstone:\n");
    print_town(&towns[1]);

    return 0;
}