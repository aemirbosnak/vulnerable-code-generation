//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    struct Node* head;
};

void add_node(struct Graph* g, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (g->head == NULL) {
        g->head = new_node;
    } else {
        struct Node* current = g->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_graph(struct Graph* g) {
    struct Node* current = g->head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    add_node(g, 1);
    add_node(g, 2);
    add_node(g, 3);
    add_node(g, 4);

    printf("Graph: ");
    print_graph(g);

    return 0;
}