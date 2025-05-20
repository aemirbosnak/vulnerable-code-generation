//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
    char name[20];
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Graph {
    Node* head;
    Node* tail;
    int size;
} Graph;

void insert_node(Graph* g, char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->next = NULL;
    new_node->prev = NULL;

    if (g->head == NULL) {
        g->head = new_node;
        g->tail = new_node;
    } else {
        g->tail->next = new_node;
        g->tail = new_node;
    }

    g->size++;
}

void traverse_graph(Graph* g) {
    Node* current_node = g->head;

    while (current_node) {
        printf("%s ", current_node->name);
        current_node = current_node->next;
    }

    printf("\n");
}

int main() {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->head = NULL;
    g->tail = NULL;
    g->size = 0;

    insert_node(g, "A");
    insert_node(g, "B");
    insert_node(g, "C");
    insert_node(g, "D");

    traverse_graph(g);

    return 0;
}