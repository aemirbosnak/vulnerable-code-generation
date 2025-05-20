//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    char name[32];
    struct node *next;
    struct node *prev;
} node_t;

typedef struct graph {
    node_t *head;
    node_t *tail;
    int size;
} graph_t;

node_t *create_node(char *name) {
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL) {
        return NULL;
    }
    strcpy(node->name, name);
    node->next = NULL;
    node->prev = NULL;
    return node;
}

graph_t *create_graph() {
    graph_t *graph = malloc(sizeof(graph_t));
    if (graph == NULL) {
        return NULL;
    }
    graph->head = NULL;
    graph->tail = NULL;
    graph->size = 0;
    return graph;
}

bool add_node(graph_t *graph, char *name) {
    node_t *node = create_node(name);
    if (node == NULL) {
        return false;
    }
    if (graph->head == NULL) {
        graph->head = node;
        graph->tail = node;
    } else {
        node->next = graph->head;
        graph->head->prev = node;
        graph->head = node;
    }
    graph->size++;
    return true;
}

bool add_edge(graph_t *graph, char *node1, char *node2) {
    node_t *node1_ptr = NULL;
    node_t *node2_ptr = NULL;
    node_t *curr = graph->head;
    while (curr != NULL) {
        if (strcmp(curr->name, node1) == 0) {
            node1_ptr = curr;
        }
        if (strcmp(curr->name, node2) == 0) {
            node2_ptr = curr;
        }
        curr = curr->next;
    }
    if (node1_ptr == NULL || node2_ptr == NULL) {
        return false;
    }
    node1_ptr->next = node2_ptr;
    node2_ptr->prev = node1_ptr;
    return true;
}

void print_graph(graph_t *graph) {
    node_t *curr = graph->head;
    while (curr != NULL) {
        printf("%s -> ", curr->name);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    graph_t *graph = create_graph();
    add_node(graph, "A");
    add_node(graph, "B");
    add_node(graph, "C");
    add_node(graph, "D");
    add_node(graph, "E");
    add_edge(graph, "A", "B");
    add_edge(graph, "A", "C");
    add_edge(graph, "B", "D");
    add_edge(graph, "C", "E");
    add_edge(graph, "D", "E");
    print_graph(graph);
    return 0;
}