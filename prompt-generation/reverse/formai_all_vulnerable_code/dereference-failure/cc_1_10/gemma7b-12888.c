//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* CreateNode(int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void InsertNode(Node* head, int x, int y) {
    Node* newNode = CreateNode(x, y);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void FindMazeRoute(Node* head) {
    int x, y;
    printf("Maze Route:\n");
    for (x = 0; x < MAX_SIZE; x++) {
        for (y = 0; y < MAX_SIZE; y++) {
            if (head->x == x && head->y == y) {
                printf("(%d, %d) ", x, y);
            } else {
                printf("(-, -) ");
            }
        }
        printf("\n");
    }
}

int main() {
    Node* head = NULL;
    InsertNode(head, 0, 0);
    InsertNode(head, 1, 0);
    InsertNode(head, 2, 0);
    InsertNode(head, 2, 1);
    InsertNode(head, 2, 2);
    InsertNode(head, 3, 2);
    InsertNode(head, 3, 3);
    InsertNode(head, 4, 3);

    FindMazeRoute(head);

    return 0;
}