//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROWS 6
#define COLS 7
#define WALL 1
#define EMPTY 0

typedef struct Node {
    int x, y;
    int gCost, hCost;
    struct Node* parent;
} Node;

Node* create_node(int x, int y, int gCost, int hCost, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->gCost = gCost;
    node->hCost = hCost;
    node->parent = parent;
    return node;
}

int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

Node* find_min_fcost(Node* openList[], int openLen) {
    Node* minNode = openList[0];
    int i;
    for (i = 1; i < openLen; i++) {
        if ((openList[i]->gCost + openList[i]->hCost) < (minNode->gCost + minNode->hCost)) {
            minNode = openList[i];
        }
    }
    return minNode;
}

bool is_same_node(Node* node1, Node* node2) {
    return node1->x == node2->x && node1->y == node2->y;
}

bool is_valid_node(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}

int main() {
    int grid[ROWS][COLS] = {
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

    Node* startNode = create_node(0, 0, 0, 0, NULL); // start at top-left corner
    Node* endNode = create_node(5, 6, 0, 0, NULL); // end at bottom-right corner

    Node* openList[ROWS*COLS] = {};
    Node* closedList[ROWS*COLS] = {};
    int openLen = 0;
    int closedLen = 0;

    openList[openLen++] = startNode;

    while (openLen > 0) {
        Node* currentNode = find_min_fcost(openList, openLen);

        if (is_same_node(currentNode, endNode)) {
            // reached the destination, construct path
            Node* path[ROWS*COLS] = {};
            int pathLen = 0;

            while (currentNode != NULL) {
                path[pathLen++] = currentNode;
                currentNode = currentNode->parent;
            }

            printf("Path found:\n");
            int i;
            for (i = pathLen - 1; i >= 0; i--) {
                printf("(%d, %d)\n", path[i]->x, path[i]->y);
            }
            return 0;
        }

        // move currentNode from openList to closedList
        int i;
        for (i = 0; i < openLen; i++) {
            if (is_same_node(openList[i], currentNode)) {
                break;
            }
        }
        openList[i] = openList[--openLen];
        closedList[closedLen++] = currentNode;

        // generate adjacent nodes
        int dx[4] = { 0, 1, 0, -1 };
        int dy[4] = { 1, 0, -1, 0 };
        for (i = 0; i < 4; i++) {
            int x = currentNode->x + dx[i];
            int y = currentNode->y + dy[i];

            if (!is_valid_node(x, y)) {
                continue;
            }

            if (grid[x][y] == WALL) {
                continue;
            }

            Node* adjacentNode = create_node(x, y, currentNode->gCost + 1, manhattan_distance(x, y, endNode->x, endNode->y), currentNode);

            // check if adjacentNode is already in openList or closedList
            bool skipNode = false;
            int j;
            for (j = 0; j < openLen; j++) {
                if (is_same_node(openList[j], adjacentNode) && adjacentNode->gCost >= openList[j]->gCost) {
                    skipNode = true;
                    break;
                }
            }
            if (!skipNode) {
                for (j = 0; j < closedLen; j++) {
                    if (is_same_node(closedList[j], adjacentNode) && adjacentNode->gCost >= closedList[j]->gCost) {
                        skipNode = true;
                        break;
                    }
                }
            }
            if (skipNode) {
                free(adjacentNode);
                continue;
            }

            openList[openLen++] = adjacentNode;
        }
    }

    // failed to find a path
    printf("Path not found\n");
    return 0;
}