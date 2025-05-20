//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void insertNode(Node* head, int x, int y) {
    Node* newNode = createNode(x, y);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    Node* head = NULL;
    insertNode(head, 0, 0);
    insertNode(head, 1, 1);
    insertNode(head, 2, 2);
    insertNode(head, 3, 3);

    int x = 2;
    int y = 2;

    // Find the route to the target node
    Node* current = head;
    while (current) {
        if (current->x == x && current->y == y) {
            printf("Route found!\n");
            break;
        } else if (current->x > x || current->y > y) {
            printf("No route found.\n");
            break;
        } else {
            current = current->next;
        }
    }

    return 0;
}