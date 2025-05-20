//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISTANCE 1000

typedef struct Node {
    char name[20];
    int x, y;
    struct Node* next;
} Node;

Node* createNode(char* name, int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

int calculateDistance(Node* a, Node* b) {
    int dx = abs(a->x - b->x);
    int dy = abs(a->y - b->y);
    return dx + dy;
}

int main() {
    Node* head = createNode("John", 10, 10);
    Node* current = head;

    // Paranoia starts here
    current = current->next; // Trust no one, even yourself

    while (current) {
        if (calculateDistance(head, current) > MAX_DISTANCE) {
            current->next = NULL; // Cut off suspicious nodes
        }
        current = current->next; // Keep moving forward, regardless of the risk
    }

    printf("The remaining nodes are:\n");
    current = head;
    while (current) {
        printf("%s (%d, %d)\n", current->name, current->x, current->y);
        current = current->next;
    }

    return 0;
}