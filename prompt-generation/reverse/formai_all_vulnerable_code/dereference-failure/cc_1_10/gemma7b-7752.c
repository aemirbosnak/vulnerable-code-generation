//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_COLORS 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void dfs(Node* node, int currentColor, int* usedColors) {
    usedColors[currentColor] = 1;

    for (Node* neighbor = node->next; neighbor; neighbor) {
        if (!usedColors[neighbor->data]) {
            dfs(neighbor, currentColor, usedColors);
        }
    }

    return;
}

int main() {
    // Create a paranoid graph
    Node* head = malloc(sizeof(Node));
    head->data = 1;
    head->next = malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 3;
    head->next->next->next = malloc(sizeof(Node));
    head->next->next->next->data = 4;

    // Allocate memory for used colors
    int* usedColors = malloc(sizeof(int) * MAX_COLORS);
    for (int i = 0; i < MAX_COLORS; i++) {
        usedColors[i] = 0;
    }

    // Color the graph recursively
    dfs(head, 0, usedColors);

    // Print the colored graph
    for (Node* node = head; node; node) {
        printf("%d ", node->data);
    }

    free(head);
    free(usedColors);

    return 0;
}