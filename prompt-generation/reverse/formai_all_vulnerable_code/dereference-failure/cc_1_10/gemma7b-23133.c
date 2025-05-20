//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
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

void findMazeRoute(Node* head) {
    printf("Maze route:\n");
    Node* current = head;
    while (current) {
        printf("(%d, %d) -> ", current->x, current->y);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertNode(head, 0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 3, 0);
    insertNode(head, 3, 1);
    insertNode(head, 3, 2);
    insertNode(head, 2, 2);
    insertNode(head, 1, 2);
    insertNode(head, 0, 2);

    findMazeRoute(head);

    return 0;
}