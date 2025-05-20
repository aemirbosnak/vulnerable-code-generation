//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Node {
    int index;
    struct Node* next;
} Node;

void create_topology(int num_vertices, Node** graph) {
    *graph = malloc(num_vertices * sizeof(Node));
    for (int i = 0; i < num_vertices; i++) {
        graph[i] = NULL;
    }
}

void add_edge(Node** graph, int src, int dest) {
    Node* node = malloc(sizeof(Node));
    node->index = dest;
    node->next = NULL;

    if (graph[src] == NULL) {
        graph[src] = node;
    } else {
        graph[src]->next = node;
    }
}

void print_topology(Node** graph) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        Node* current = graph[i];
        while (current) {
            printf("%d ", current->index);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Node** graph = NULL;
    create_topology(10, &graph);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 5);
    add_edge(graph, 4, 6);

    print_topology(graph);

    return 0;
}