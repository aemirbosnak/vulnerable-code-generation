//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_NAME_LENGTH 20

typedef struct node {
    char name[MAX_NAME_LENGTH];
    struct node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int count;
} Graph;

void insert(Graph *graph, char *name) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->next = NULL;

    if (graph->head == NULL) {
        graph->head = new_node;
        graph->tail = new_node;
    } else {
        graph->tail->next = new_node;
        graph->tail = new_node;
    }
    graph->count++;
}

void display(Graph *graph) {
    Node *curr = graph->head;
    while (curr!= NULL) {
        printf("%s\n", curr->name);
        curr = curr->next;
    }
}

int main() {
    Graph graph = { 0, 0, 0 };
    insert(&graph, "Alice");
    insert(&graph, "Bob");
    insert(&graph, "Charlie");
    insert(&graph, "David");
    display(&graph);
    return 0;
}