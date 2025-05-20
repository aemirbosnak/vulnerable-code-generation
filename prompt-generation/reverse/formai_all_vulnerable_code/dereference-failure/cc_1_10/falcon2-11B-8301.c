//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX_NODES 1000

typedef struct {
    int color;
    int index;
    struct node *next;
} Node;

typedef struct {
    int num_nodes;
    Node *head;
} Graph;

void insert_node(Graph *graph, int color, int index) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->color = color;
    new_node->index = index;
    new_node->next = graph->head;
    graph->head = new_node;
    graph->num_nodes++;
}

int find_min_color(Node *head, int color) {
    Node *current = head;
    while (current!= NULL && current->color!= color) {
        current = current->next;
    }
    return current!= NULL? current->color : -1;
}

int main() {
    srand(time(NULL));
    Graph graph;
    graph.num_nodes = 0;
    graph.head = NULL;

    int num_nodes = MAX_NODES;
    for (int i = 0; i < num_nodes; i++) {
        int color = rand() % 3;
        insert_node(&graph, color, i);
    }

    int num_colors = rand() % 3 + 1;
    int *colors = (int *)malloc(num_colors * sizeof(int));
    int *indices = (int *)malloc(num_nodes * sizeof(int));
    for (int i = 0; i < num_colors; i++) {
        colors[i] = -1;
    }
    for (int i = 0; i < num_nodes; i++) {
        indices[i] = i;
    }

    int num_iterations = 0;
    int num_changes = 0;
    int max_iterations = 1000000;
    int max_changes = 1000000;
    while (num_iterations < max_iterations) {
        num_changes = 0;
        for (int i = 0; i < num_nodes; i++) {
            int color = find_min_color(graph.head, colors[i]);
            if (color!= -1) {
                colors[i] = color;
                indices[i] = graph.head->index;
                insert_node(&graph, color, i);
                num_changes++;
            }
        }
        num_iterations++;
        if (num_changes == 0) {
            break;
        }
    }

    if (num_iterations >= max_iterations) {
        printf("Maximum number of iterations reached.\n");
    } else {
        printf("Number of iterations: %d\n", num_iterations);
        printf("Number of changes: %d\n", num_changes);
    }

    free(colors);
    free(indices);
    return 0;
}