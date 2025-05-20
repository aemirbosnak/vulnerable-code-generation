//FormAI DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void print_node(struct node *n) {
    printf("%d ", n->data);
    if (n->next != NULL) {
        print_node(n->next);
    }
}

struct node* add_node(struct node *n, int data) {
    if (n == NULL) {
        n = (struct node*) malloc(sizeof(struct node));
        n->data = data;
        n->next = NULL;
    } else {
        n->next = add_node(n->next, data);
    }
    return n;
}

void free_nodes(struct node *n) {
    if (n->next != NULL) {
        free_nodes(n->next);
    }
    free(n);
}

int main() {
    struct node *head = NULL;
    head = add_node(head, 1);
    add_node(head, 2);
    add_node(head, 3);
    add_node(head, 4);
    add_node(head, 5);

    // Print all nodes
    print_node(head);
    printf("\n");

    // Free all nodes
    free_nodes(head);

    return 0;
}