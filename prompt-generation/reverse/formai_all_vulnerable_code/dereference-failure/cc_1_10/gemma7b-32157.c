//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define GRAPH_SIZE 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void graph_insert(Node* node, int data) {
    Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (node == NULL) {
        node = newNode;
    } else {
        node->next = newNode;
        node = newNode;
    }
}

void graph_color(Node* node) {
    int color = 0;
    node->data = color;

    while (node->next) {
        if (node->next->data == color) {
            color++;
        }
        node = node->next;
    }

    node->data = color;
}

int main() {
    Node* graph = NULL;
    graph_insert(graph, 1);
    graph_insert(graph, 2);
    graph_insert(graph, 3);
    graph_insert(graph, 4);
    graph_insert(graph, 5);

    graph_color(graph);

    for (Node* node = graph; node; node = node->next) {
        printf("%d ", node->data);
    }

    return 0;
}