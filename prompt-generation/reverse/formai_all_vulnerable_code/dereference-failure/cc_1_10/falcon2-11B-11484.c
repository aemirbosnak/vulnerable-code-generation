//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
    int id;
    int x;
    int y;
    int weight;
    struct node *next;
} node;

int main() {
    // Create a new graph
    node *head = NULL;

    // Add nodes to the graph
    node *node1 = malloc(sizeof(node));
    node1->id = 1;
    node1->x = 10;
    node1->y = 10;
    node1->weight = 10;
    node1->next = NULL;

    node *node2 = malloc(sizeof(node));
    node2->id = 2;
    node2->x = 20;
    node2->y = 20;
    node2->weight = 20;
    node2->next = NULL;

    node *node3 = malloc(sizeof(node));
    node3->id = 3;
    node3->x = 30;
    node3->y = 30;
    node3->weight = 30;
    node3->next = NULL;

    // Add edges to the graph
    node *edge1 = malloc(sizeof(node));
    edge1->id = 1;
    edge1->next = node1;
    node1->next = edge1;

    node *edge2 = malloc(sizeof(node));
    edge2->id = 2;
    edge2->next = node2;
    node2->next = edge2;

    node *edge3 = malloc(sizeof(node));
    edge3->id = 3;
    edge3->next = node3;
    node3->next = edge3;

    // Print the graph
    printf("Graph:\n");
    node *current = head;
    while (current!= NULL) {
        printf("Node %d (%d, %d) with weight %d\n", current->id, current->x, current->y, current->weight);
        current = current->next;
    }

    return 0;
}