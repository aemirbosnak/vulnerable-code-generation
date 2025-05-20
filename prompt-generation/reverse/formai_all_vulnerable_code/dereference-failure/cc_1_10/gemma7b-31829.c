//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct graph {
    struct node** adjacency_list;
    int num_vertices;
};

void create_graph(struct graph* graph, int num_vertices) {
    graph->num_vertices = num_vertices;
    graph->adjacency_list = (struct node**)malloc(num_vertices * sizeof(struct node*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_list[i] = NULL;
    }
}

void add_edge(struct graph* graph, int src, int dest) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = dest;
    new_node->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = new_node;
}

void traverse_graph(struct graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        struct node* current = graph->adjacency_list[i];
        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));
    create_graph(graph, 5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    traverse_graph(graph);

    return 0;
}