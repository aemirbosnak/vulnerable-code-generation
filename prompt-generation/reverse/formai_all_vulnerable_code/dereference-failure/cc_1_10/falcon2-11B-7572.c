//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define INF INT_MAX
#define MAX_N 100000

typedef struct node {
    int vertex;
    int color;
    struct node *next;
} node;

node *head, *tail;

int main() {
    // Create the head and tail nodes
    head = (node *)malloc(sizeof(node));
    tail = (node *)malloc(sizeof(node));
    head->next = tail;
    tail->next = NULL;

    // Initialize the nodes with random colors
    for (int i = 0; i < MAX_N; i++) {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->vertex = i;
        new_node->color = rand() % 5;
        new_node->next = NULL;
        tail->next = new_node;
        tail = new_node;
    }

    // Perform DFS to color the graph
    int color_count[5] = {0};
    node *current = head->next;
    while (current!= tail) {
        if (color_count[current->color] > 0) {
            printf("Error: Adjacent nodes have the same color\n");
            return 1;
        }
        color_count[current->color]++;
        current = current->next;
    }

    // Print the colored graph
    printf("Colored graph: \n");
    current = head->next;
    while (current!= tail) {
        printf("%d %d\n", current->vertex, current->color);
        current = current->next;
    }

    return 0;
}