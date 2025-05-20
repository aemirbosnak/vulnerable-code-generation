//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

struct graph {
    int num_vertices;
    struct node* nodes;
};

void add_edge(struct graph* graph, int u, int v) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->vertex = v;
    new_node->next = graph->nodes[u].next;
    graph->nodes[u].next = new_node;
}

int main() {
    struct graph graph;
    graph.num_vertices = 5;
    graph.nodes = (struct node*)malloc(graph.num_vertices * sizeof(struct node));

    graph.nodes[0].next = NULL;
    graph.nodes[1].next = NULL;
    graph.nodes[2].next = NULL;
    graph.nodes[3].next = NULL;
    graph.nodes[4].next = NULL;

    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 2);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 1, 3);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 3, 4);

    for (int i = 0; i < graph.num_vertices; i++) {
        printf("Vertex %d: ", i);
        struct node* current = graph.nodes[i].next;
        while (current!= NULL) {
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }

    free(graph.nodes);
    return 0;
}