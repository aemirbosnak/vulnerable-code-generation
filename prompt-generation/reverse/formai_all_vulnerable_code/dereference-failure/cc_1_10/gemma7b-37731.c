//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

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

void addNode(Node* head, int x, int y) {
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
    printf("The route is:");
    while (head) {
        x = head->x;
        y = head->y;
        printf("(%d, %d) ", x, y);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    addNode(head, 0, 0);
    addNode(head, 1, 0);
    addNode(head, 2, 0);
    addNode(head, 3, 0);
    addNode(head, 4, 0);
    addNode(head, 5, 0);
    addNode(head, 6, 0);
    addNode(head, 7, 0);
    addNode(head, 8, 0);
    addNode(head, 9, 0);
    findMazeRoute(head);
    return 0;
}