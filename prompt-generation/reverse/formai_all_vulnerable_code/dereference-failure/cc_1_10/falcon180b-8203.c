//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

typedef struct {
    char *name;
    int value;
    struct node_t *next;
} node_t;

typedef struct {
    node_t *head;
} graph_t;

graph_t *create_graph(void)
{
    graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
    if (graph == NULL) {
        printf("Error: Failed to allocate memory for graph.\n");
        exit(EXIT_FAILURE);
    }
    graph->head = NULL;
    return graph;
}

void destroy_graph(graph_t *graph)
{
    node_t *current = graph->head;
    while (current!= NULL) {
        node_t *next = current->next;
        free(current->name);
        free(current);
        current = next;
    }
    free(graph);
}

void add_node(graph_t *graph, char *name, int value)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: Failed to allocate memory for node.\n");
        exit(EXIT_FAILURE);
    }
    new_node->name = strdup(name);
    new_node->value = value;
    new_node->next = graph->head;
    graph->head = new_node;
}

void print_graph(graph_t *graph)
{
    node_t *current = graph->head;
    while (current!= NULL) {
        printf("%s (%d)\n", current->name, current->value);
        current = current->next;
    }
}

int main(int argc, char *argv[])
{
    graph_t *graph = create_graph();

    add_node(graph, "Alice", 1);
    add_node(graph, "Bob", 2);
    add_node(graph, "Charlie", 3);
    add_node(graph, "David", 4);

    print_graph(graph);

    destroy_graph(graph);

    return 0;
}