//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void insertNode(Node* head, int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

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

int distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void findPath(Node* head, int x, int y) {
    insertNode(head, x, y);

    if (x == 0 && y == 0) {
        printf("Path found!\n");
        return;
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newX < MAX_SIZE && newY >= 0 && newY < MAX_SIZE && head->x != newX && head->y != newY) {
            findPath(head, newX, newY);
        }
    }
}

int main() {
    Node* head = NULL;
    findPath(head, 10, 10);

    return 0;
}