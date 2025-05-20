//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10
#define INF 10000

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Node {
    int x, y;
    int f, g, h;
    struct Node* parent;
};

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void AStar(int graph[][COLS], struct Node* startNode, struct Node* endNode) {
    struct Node* openSet[ROWS * COLS];
    struct Node* closedSet[ROWS * COLS];
    int openSetSize = 0;
    int closedSetSize = 0;

    openSet[openSetSize++] = startNode;

    while (openSetSize > 0) {
        struct Node* currentNode = openSet[0];
        int currentIndex = 0;

        for (int i = 1; i < openSetSize; i++) {
            if (openSet[i]->f < currentNode->f) {
                currentNode = openSet[i];
                currentIndex = i;
            }
        }

        if (currentNode->x == endNode->x && currentNode->y == endNode->y) {
            struct Node* pathNode = currentNode;

            while (pathNode) {
                printf("(%d, %d) ", pathNode->x, pathNode->y);
                pathNode = pathNode->parent;
            }

            return;
        }

        openSet[currentIndex] = openSet[--openSetSize];
        closedSet[closedSetSize++] = currentNode;

        for (int move = 0; move < 4; move++) {
            int newX = currentNode->x + dx[move];
            int newY = currentNode->y + dy[move];

            if (newX < 0 || newX >= ROWS || newY < 0 || newY >= COLS || graph[newX][newY] == 0) {
                continue;
            }

            struct Node* neighbor = (struct Node*)malloc(sizeof(struct Node));
            neighbor->x = newX;
            neighbor->y = newY;
            neighbor->parent = currentNode;
            neighbor->g = currentNode->g + 1;
            neighbor->h = heuristic(newX, newY, endNode->x, endNode->y);
            neighbor->f = neighbor->g + neighbor->h;

            int inClosedSet = 0;

            for (int i = 0; i < closedSetSize; i++) {
                if (closedSet[i]->x == neighbor->x && closedSet[i]->y == neighbor->y) {
                    inClosedSet = 1;
                    break;
                }
            }

            if (inClosedSet) {
                continue;
            }

            int inOpenSet = 0;

            for (int i = 0; i < openSetSize; i++) {
                if (openSet[i]->x == neighbor->x && openSet[i]->y == neighbor->y) {
                    inOpenSet = 1;

                    if (neighbor->g < openSet[i]->g) {
                        openSet[i]->g = neighbor->g;
                        openSet[i]->f = openSet[i]->g + openSet[i]->h;
                        openSet[i]->parent = neighbor->parent;
                    }

                    break;
                }
            }

            if (!inOpenSet) {
                openSet[openSetSize++] = neighbor;
            }
        }
    }

    printf("No path found!\n");
}

int main() {
    int graph[ROWS][COLS] = {
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
    };

    struct Node startNode = {0, 0, 0, 0, 0, NULL};
    struct Node endNode = {9, 9, 0, 0, 0, NULL};

    AStar(graph, &startNode, &endNode);

    return 0;
}