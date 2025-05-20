//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct graph {
    Node *head;
    int size;
} Graph;

void add_node(Graph *g, int data) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (g->head == NULL) {
        g->head = new_node;
    } else {
        Node *current = g->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    g->size++;
}

void display_graph(Graph *g) {
    Node *current = g->head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Graph *g = malloc(sizeof(Graph));
    if (g == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    g->head = NULL;
    g->size = 0;

    for (int i = 0; i < 10; i++) {
        int data = rand() % 100;
        add_node(g, data);
    }

    display_graph(g);

    return 0;
}