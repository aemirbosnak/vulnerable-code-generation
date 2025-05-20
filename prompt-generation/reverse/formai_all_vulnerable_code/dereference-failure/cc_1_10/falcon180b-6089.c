//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100

struct node {
    char name[20];
    int id;
    struct node *next;
};

struct edge {
    int src_id;
    int dest_id;
    int weight;
    struct edge *next;
};

void add_node(struct node **head, char *name, int id) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    new_node->id = id;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct node *temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void add_edge(struct edge **head, int src_id, int dest_id, int weight) {
    struct edge *new_edge = (struct edge *)malloc(sizeof(struct edge));
    new_edge->src_id = src_id;
    new_edge->dest_id = dest_id;
    new_edge->weight = weight;
    new_edge->next = NULL;

    if (*head == NULL) {
        *head = new_edge;
        return;
    }

    struct edge *temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_edge;
}

void print_nodes(struct node *head) {
    while (head!= NULL) {
        printf("%s - %d\n", head->name, head->id);
        head = head->next;
    }
}

void print_edges(struct edge *head) {
    while (head!= NULL) {
        printf("(%d, %d) - %d\n", head->src_id, head->dest_id, head->weight);
        head = head->next;
    }
}

int main() {
    struct node *head = NULL;
    struct edge *head2 = NULL;

    add_node(&head, "A", 1);
    add_node(&head, "B", 2);
    add_node(&head, "C", 3);
    add_node(&head, "D", 4);
    add_node(&head, "E", 5);

    add_edge(&head2, 1, 2, 3);
    add_edge(&head2, 1, 4, 2);
    add_edge(&head2, 2, 3, 5);
    add_edge(&head2, 2, 5, 1);
    add_edge(&head2, 3, 4, 6);
    add_edge(&head2, 4, 5, 4);

    printf("Nodes:\n");
    print_nodes(head);

    printf("\nEdges:\n");
    print_edges(head2);

    return 0;
}