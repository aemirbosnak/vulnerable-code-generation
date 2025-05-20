//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct Node {
    char data;
    struct Node* next;
};

struct Graph {
    struct Node** graph;
    int size;
};

void insert(struct Graph* g, char data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (g->size == 0) {
        g->graph = malloc(g->size * MAX);
    }

    g->graph[g->size++] = newNode;
}

void traverse(struct Graph* g) {
    for (int i = 0; i < g->size; i++) {
        struct Node* current = g->graph[i];
        printf("%c ", current->data);
    }
    printf("\n");
}

int main() {
    struct Graph* g = malloc(sizeof(struct Graph));
    g->size = 0;
    g->graph = NULL;

    insert(g, 'a');
    insert(g, 'b');
    insert(g, 'c');
    insert(g, 'd');
    insert(g, 'e');

    traverse(g);

    return 0;
}