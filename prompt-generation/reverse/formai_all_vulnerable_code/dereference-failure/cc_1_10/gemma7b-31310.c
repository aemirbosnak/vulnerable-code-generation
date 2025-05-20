//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISTANCE 100

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
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
        head->next = newNode;
        head = newNode;
    }
}

int distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    Node* head = NULL;
    addNode(head, 0, 0);
    addNode(head, 1, 1);
    addNode(head, 2, 2);
    addNode(head, 3, 3);

    int targetX = 3;
    int targetY = 3;

    int currentX = 0;
    int currentY = 0;

    int distanceToTarget = MAX_DISTANCE;

    while (distanceToTarget > 0) {
        int minDistance = MAX_DISTANCE;
        Node* currentNode = head;

        while (currentNode) {
            int d = distance(currentX, currentY, currentNode->x, currentNode->y);
            if (d < minDistance) {
                minDistance = d;
                currentNode = currentNode;
            }
        }

        currentX = currentNode->x;
        currentY = currentNode->y;

        distanceToTarget = minDistance;

        printf("Distance to target: %d\n", distanceToTarget);
    }

    return 0;
}