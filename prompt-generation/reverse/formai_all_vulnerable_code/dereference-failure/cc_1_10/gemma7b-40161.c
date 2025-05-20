//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    *head = malloc(sizeof(Node));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->next = NULL;
}

void addNode(Node** head, int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if ((*head)->next == NULL) {
        (*head)->next = newNode;
    } else {
        ((*head)->next)->next = newNode;
    }
}

void findPath(Node* head, int targetX, int targetY) {
    if (head == NULL) {
        return;
    }

    if (head->x == targetX && head->y == targetY) {
        printf("Path found!\n");
        return;
    }

    findPath(head->next, targetX, targetY);

    if (head->x + 1 == targetX && head->y == targetY) {
        printf("Eastward movement.\n");
        head->x++;
    } else if (head->x - 1 == targetX && head->y == targetY) {
        printf("Westward movement.\n");
        head->x--;
    } else if (head->y + 1 == targetY && head->x == targetX) {
        printf("Northward movement.\n");
        head->y++;
    } else if (head->y - 1 == targetY && head->x == targetX) {
        printf("Southward movement.\n");
        head->y--;
    }
}

int main() {
    Node* head = NULL;
    createMaze(&head);
    addNode(head, 0, 0);
    addNode(head, 1, 0);
    addNode(head, 2, 0);
    addNode(head, 2, 1);
    addNode(head, 2, 2);
    addNode(head, 3, 2);

    findPath(head, 3, 2);

    return 0;
}