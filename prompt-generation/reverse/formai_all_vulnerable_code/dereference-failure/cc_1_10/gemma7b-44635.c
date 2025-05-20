//Gemma-7B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_DISTANCE 100

typedef struct Node {
    int x, y;
    struct Node* next;
    struct Node* prev;
    struct Node* up;
    struct Node* down;
    struct Node* right;
    struct Node* left;
} Node;

Node* newNode(int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->up = NULL;
    newNode->down = NULL;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void connectNeighbors(Node* node) {
    if (node) {
        if (node->x > 0) node->right = newNode(node->x + 1, node->y);
        if (node->x < MAX_DISTANCE - 1) node->left = newNode(node->x - 1, node->y);
        if (node->y > 0) node->up = newNode(node->x, node->y - 1);
        if (node->y < MAX_DISTANCE - 1) node->down = newNode(node->x, node->y + 1);
    }
}

int main() {
    Node* start = newNode(0, 0);
    connectNeighbors(start);

    Node* goal = newNode(MAX_DISTANCE - 1, MAX_DISTANCE - 1);
    connectNeighbors(goal);

    // A* Pathfinding Algorithm
    // (Paranoia-prone version)
    Node* current = start;
    Node* best = NULL;
    int g = 0;
    int h = 0;
    int f = g + h;

    while (current && best == NULL) {
        for (Node* neighbor = current->up; neighbor; neighbor = neighbor->down) {
            if (neighbor->x == goal->x && neighbor->y == goal->y) {
                best = neighbor;
                break;
            }

            int ng = g + 1;
            int nh = h + abs(neighbor->x - goal->x) + abs(neighbor->y - goal->y);
            int nf = ng + nh;

            if (nf < f) {
                current->prev = neighbor;
                current = neighbor;
                g = ng;
                h = nh;
                f = nf;
            }
        }
    }

    if (best) {
        printf("Path found!");
        // Trace path from start to goal
        while (current) {
            printf("(%d, %d) ", current->x, current->y);
            current = current->prev;
        }
    } else {
        printf("No path found.");
    }

    return 0;
}