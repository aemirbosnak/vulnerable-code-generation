//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200

typedef struct {
    int vertex;
    int weight;
    struct adj_list *next;
} adj_list;

typedef struct {
    int vertex;
    int degree;
    adj_list *head;
} vertex;

vertex *create_graph(int num_vertices) {
    vertex *graph = (vertex *)malloc(num_vertices * sizeof(vertex));

    for (int i = 0; i < num_vertices; i++) {
        graph[i].vertex = i;
        graph[i].degree = 0;
        graph[i].head = NULL;
    }

    return graph;
}

void add_edge(vertex *graph, int u, int v, int weight) {
    adj_list *new_node = (adj_list *)malloc(sizeof(adj_list));
    new_node->vertex = v;
    new_node->weight = weight;
    new_node->next = graph[u].head;
    graph[u].head = new_node;
    graph[u].degree++;
    graph[v].degree++;
}

void print_graph(vertex *graph, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: ", i);
        adj_list *temp = graph[i].head;
        while (temp!= NULL) {
            printf("(%d, %d) ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int num_vertices = 5;
    vertex *graph = create_graph(num_vertices);

    add_edge(graph, 0, 1, 5);
    add_edge(graph, 0, 2, 10);
    add_edge(graph, 1, 2, 2);
    add_edge(graph, 1, 3, 3);
    add_edge(graph, 2, 3, 5);
    add_edge(graph, 2, 4, 8);
    add_edge(graph, 3, 4, 4);

    printf("Adjacency List Representation of Graph:\n");
    print_graph(graph, num_vertices);

    return 0;
}