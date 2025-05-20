//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct edge {
    int source;
    int destination;
} edge;

node *head, *tail;
int num_nodes, num_edges;
edge *edges;

void add_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }

    num_nodes++;
}

void add_edge(int source, int destination) {
    edge new_edge = {source, destination};
    edges = (edge *)realloc(edges, (num_edges + 1) * sizeof(edge));
    edges[num_edges].source = source;
    edges[num_edges].destination = destination;
    num_edges++;
}

void print_nodes() {
    if (head == NULL) {
        printf("Graph is empty!\n");
        return;
    }

    printf("Nodes in the graph:\n");
    node *current = head;
    while (current!= NULL) {
        printf("Node %d -> %d\n", current->data, current->next->data);
        current = current->next;
    }
}

void print_edges() {
    if (num_edges == 0) {
        printf("No edges in the graph!\n");
        return;
    }

    printf("Edges in the graph:\n");
    for (int i = 0; i < num_edges; i++) {
        printf("(%d, %d)\n", edges[i].source, edges[i].destination);
    }
}

int main() {
    int choice, data, source, destination;

    do {
        printf("1. Add Node\n");
        printf("2. Add Edge\n");
        printf("3. Print Nodes\n");
        printf("4. Print Edges\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter node data: ");
                scanf("%d", &data);
                add_node(data);
                break;
            case 2:
                printf("Enter source node data: ");
                scanf("%d", &source);
                printf("Enter destination node data: ");
                scanf("%d", &destination);
                add_edge(source, destination);
                break;
            case 3:
                print_nodes();
                break;
            case 4:
                print_edges();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}