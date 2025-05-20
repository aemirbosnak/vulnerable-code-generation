//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct node {
    int temperature;
    int humidity;
    struct node *next;
};

struct graph {
    struct node *head;
};

void create_graph(struct graph *g) {
    g->head = NULL;
}

void add_node(struct graph *g, int temperature, int humidity) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->temperature = temperature;
    n->humidity = humidity;
    n->next = g->head;
    g->head = n;
}

void display_graph(struct graph *g) {
    struct node *current = g->head;
    while (current != NULL) {
        printf("[%d, %d]", current->temperature, current->humidity);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct graph g;
    create_graph(&g);

    // Add some nodes to the graph
    add_node(&g, 20, 60);
    add_node(&g, 25, 75);
    add_node(&g, 30, 90);
    add_node(&g, 35, 100);

    // Display the graph
    display_graph(&g);

    return 0;
}