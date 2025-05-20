//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10

#define MAX 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    int gCost;
    int hCost;
    int fCost;
    struct Node* parent;
} Node;

Node* openSet[MAX];
int openSetCount = 0;

Node* closedSet[MAX];
int closedSetCount = 0;

int grid[HEIGHT][WIDTH] = {
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 0, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0}
};

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool inOpenSet(Node* node) {
    for (int i = 0; i < openSetCount; i++) {
        if (openSet[i]->position.x == node->position.x && openSet[i]->position.y == node->position.y) {
            return true;
        }
    }
    return false;
}

bool inClosedSet(Node* node) {
    for (int i = 0; i < closedSetCount; i++) {
        if (closedSet[i]->position.x == node->position.x && closedSet[i]->position.y == node->position.y) {
            return true;
        }
    }
    return false;
}

void addToOpenSet(Node* node) {
    openSet[openSetCount++] = node;
}

void addToClosedSet(Node* node) {
    closedSet[closedSetCount++] = node;
}

Node* createNode(Point pos, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->position = pos;
    node->gCost = parent ? parent->gCost + 1 : 0; 
    node->hCost = heuristic(pos, (Point){WIDTH - 1, HEIGHT - 1});
    node->fCost = node->gCost + node->hCost;
    node->parent = parent;
    return node;
}

void printPath(Node* node) {
    if (node == NULL) return;
    printPath(node->parent);
    printf("-> (%d, %d) ", node->position.x, node->position.y);
}

void aStar(Point startPos) {
    addToOpenSet(createNode(startPos, NULL));

    while (openSetCount > 0) {
        Node* current = openSet[0];
        for (int i = 1; i < openSetCount; i++) {
            if (openSet[i]->fCost < current->fCost || 
                (openSet[i]->fCost == current->fCost && openSet[i]->hCost < current->hCost)) {
                current = openSet[i];
            }
        }

        if (current->position.x == WIDTH - 1 && current->position.y == HEIGHT - 1) {
            printf("Path found: ");
            printPath(current);
            printf("\n");
            return;
        }

        for (int i = 0; i < openSetCount; i++) {
            if (openSet[i] == current) {
                for (int j = i; j < openSetCount - 1; j++) {
                    openSet[j] = openSet[j + 1];
                }
                openSetCount--;
                break;
            }
        }
        
        addToClosedSet(current);

        Point neighbors[4] = {
            {current->position.x + 1, current->position.y},
            {current->position.x - 1, current->position.y},
            {current->position.x, current->position.y + 1},
            {current->position.x, current->position.y - 1}
        };

        for (int i = 0; i < 4; i++) {
            Point neighborPos = neighbors[i];
            if (neighborPos.x < 0 || neighborPos.x >= WIDTH || 
                neighborPos.y < 0 || neighborPos.y >= HEIGHT || 
                grid[neighborPos.y][neighborPos.x] == 1) continue;

            Node* neighborNode = createNode(neighborPos, current);

            if (inClosedSet(neighborNode)) continue;

            if (!inOpenSet(neighborNode)) {
                addToOpenSet(neighborNode);
            } else {
                for (int j = 0; j < openSetCount; j++) {
                    if (openSet[j]->position.x == neighborNode->position.x && openSet[j]->position.y == neighborNode->position.y) {
                        if (neighborNode->gCost < openSet[j]->gCost) {
                            openSet[j]->gCost = neighborNode->gCost;
                            openSet[j]->fCost = neighborNode->fCost;
                            openSet[j]->parent = current;
                        }
                        break;
                    }
                } 
            }
            free(neighborNode);
        }
    }
    printf("No path found.\n");
}

int main() {
    Point start = {0, 0};
    printf("Starting A* Pathfinding from (0, 0) to (9, 9)!\n");
    aStar(start);
    return 0;
}