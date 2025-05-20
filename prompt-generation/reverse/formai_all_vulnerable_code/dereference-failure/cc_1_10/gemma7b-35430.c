//Gemma-7B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISTANCE 100

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

int distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void findPath(int x, int y, int targetX, int targetY) {
    Node* current = createNode(x, y);
    Node* openList = NULL;
    Node* closedList = NULL;

    openList = current;
    closedList = NULL;

    while (current->x != targetX || current->y != targetY) {
        int minDistance = MAX_DISTANCE;
        Node* nextNode = NULL;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;

                int newX = current->x + dx;
                int newY = current->y + dy;

                if (newX >= 0 && newX < targetX && newY >= 0 && newY < targetY) {
                    int newDistance = distance(x, y, newX, newY);
                    if (newDistance < minDistance) {
                        minDistance = newDistance;
                        nextNode = createNode(newX, newY);
                    }
                }
            }
        }

        if (nextNode) {
            current = nextNode;
            openList = nextNode;
            closedList = current;
        } else {
            printf("No path found.\n");
            return;
        }
    }

    printf("Path found: (%d, %d) to (%d, %d)\n", current->x, current->y, targetX, targetY);
    free(current);
    free(closedList);
}

int main() {
    findPath(0, 0, 5, 5);
    return 0;
}