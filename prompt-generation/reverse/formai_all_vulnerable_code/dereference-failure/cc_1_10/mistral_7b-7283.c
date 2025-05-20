//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Edge {
    int dest;
    struct Edge* next;
} Edge;

typedef struct Vertex {
    int id;
    char name[50];
    bool visited;
    Edge* adj;
} Vertex;

void add_edge(Vertex* v1, Vertex* v2) {
    Edge* new_edge = (Edge*) malloc(sizeof(Edge));
    new_edge->dest = v2->id;
    new_edge->next = v1->adj;
    v1->adj = new_edge;
}

Vertex* create_vertex(int id, char* name) {
    Vertex* new_vertex = (Vertex*) malloc(sizeof(Vertex));
    new_vertex->id = id;
    strcpy(new_vertex->name, name);
    new_vertex->visited = false;
    new_vertex->adj = NULL;
    return new_vertex;
}

void print_graph(Vertex** vertices, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        printf("%s: ", vertices[i]->name);
        Edge* edge = vertices[i]->adj;
        while (edge != NULL) {
            printf("->%s ", vertices[edge->dest]->name);
            edge = edge->next;
        }
        printf("\n");
    }
}

int main() {
    int num_vertices = 5;
    Vertex** vertices = (Vertex**) calloc(num_vertices, sizeof(Vertex*));

    vertices[0] = create_vertex(1, "A");
    vertices[1] = create_vertex(2, "B");
    vertices[2] = create_vertex(3, "C");
    vertices[3] = create_vertex(4, "D");
    vertices[4] = create_vertex(5, "E");

    add_edge(vertices[0], vertices[1]);
    add_edge(vertices[0], vertices[2]);
    add_edge(vertices[1], vertices[3]);
    add_edge(vertices[1], vertices[4]);
    add_edge(vertices[2], vertices[3]);
    add_edge(vertices[3], vertices[4]);

    print_graph(vertices, num_vertices);

    free(vertices);

    // Surprise! Let's add some self-loops
    for (int i = 0; i < num_vertices; i++) {
        add_edge(vertices[i], vertices[i]);
    }

    printf("\nAfter adding self-loops:\n");
    print_graph(vertices, num_vertices);

    return 0;
}