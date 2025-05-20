//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 10
#define MAX_Edges 20

typedef struct Vertex {
    int index;
    struct Vertex *next;
} Vertex;

typedef struct Edge {
    int src, dest;
    struct Edge *next;
} Edge;

void insertVertex(Vertex **head, int index) {
    Vertex *newNode = (Vertex *)malloc(sizeof(Vertex));
    newNode->index = index;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void insertEdge(Edge **head, int src, int dest) {
    Edge *newNode = (Edge *)malloc(sizeof(Edge));
    newNode->src = src;
    newNode->dest = dest;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ((*head)->next = newNode);
    }
}

int main() {
    Vertex **graph = NULL;
    Edge **edges = NULL;

    insertVertex(&graph, 0);
    insertVertex(&graph, 1);
    insertVertex(&graph, 2);
    insertVertex(&graph, 3);

    insertEdge(&edges, 0, 1);
    insertEdge(&edges, 1, 2);
    insertEdge(&edges, 2, 3);

    printf("Graph vertices:");
    for (Vertex *vertex = graph; vertex; vertex = vertex->next) {
        printf(" %d", vertex->index);
    }

    printf("\nGraph edges:");
    for (Edge *edge = edges; edge; edge = edge->next) {
        printf(" %d-%d", edge->src, edge->dest);
    }

    return 0;
}