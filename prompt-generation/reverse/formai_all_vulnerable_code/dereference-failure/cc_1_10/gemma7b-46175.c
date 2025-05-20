//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    int x;
    int y;
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
        newNode->next = head;
        head = newNode;
    }
}

void findMazeRoute(Node* head) {
    int x, y;
    printf("Enter the starting x and y coordinates:");
    scanf("%d %d", &x, &y);

    printf("Enter the ending x and y coordinates:");
    scanf("%d %d", &x, &y);

    // Search for the route
    Node* current = head;
    while (current) {
        if (current->x == x && current->y == y) {
            printf("The route is found!\n");
            break;
        } else {
            current = current->next;
        }
    }

    if (current == NULL) {
        printf("No route found.\n");
    }
}

int main() {
    Node* head = NULL;
    insertNode(head, 0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 2, 1);
    insertNode(head, 2, 2);
    insertNode(head, 1, 2);
    insertNode(head, 0, 2);

    findMazeRoute(head);

    return 0;
}