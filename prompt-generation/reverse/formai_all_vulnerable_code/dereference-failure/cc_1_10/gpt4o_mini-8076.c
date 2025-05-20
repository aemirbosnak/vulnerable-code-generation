//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_SIZE 10
#define MAX_OPEN_NODES 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int g; // Cost from start to the current node
    int h; // Heuristic cost to goal
    int f; // Total cost
    struct Node* parent;
} Node;

Node* openList[MAX_OPEN_NODES];
int openListCount = 0;
bool closedList[GRID_SIZE][GRID_SIZE];

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isInOpenList(Point point) {
    for (int i = 0; i < openListCount; i++) {
        if (openList[i]->point.x == point.x && openList[i]->point.y == point.y) {
            return true;
        }
    }
    return false;
}

bool isInClosedList(Point point) {
    return closedList[point.x][point.y];
}

void addToOpenList(Node* node) {
    openList[openListCount++] = node;
}

Node* getLowestCostNode() {
    Node* lowestNode = openList[0];
    for (int i = 1; i < openListCount; i++) {
        if (openList[i]->f < lowestNode->f) {
            lowestNode = openList[i];
        }
    }
    return lowestNode;
}

void removeFromOpenList(Node* node) {
    for (int i = 0; i < openListCount; i++) {
        if (openList[i] == node) {
            openList[i] = openList[--openListCount];
            return;
        }
    }
}

bool isValid(Point point) {
    return point.x >= 0 && point.x < GRID_SIZE && point.y >= 0 && point.y < GRID_SIZE && !closedList[point.x][point.y];
}

void reconstructPath(Node* node) {
    if (node->parent != NULL) {
        reconstructPath(node->parent);
    }
    printf("->(%d, %d) ", node->point.x, node->point.y);
}

void aStar(Point start, Point goal) {
    Node* startNode = (Node*)malloc(sizeof(Node));
    startNode->point = start;
    startNode->g = 0;
    startNode->h = heuristic(start, goal);
    startNode->f = startNode->h;
    startNode->parent = NULL;

    addToOpenList(startNode);

    while (openListCount > 0) {
        Node* currentNode = getLowestCostNode();

        if (currentNode->point.x == goal.x && currentNode->point.y == goal.y) {
            printf("Path found: ");
            reconstructPath(currentNode);
            printf("->(%d, %d)\n", goal.x, goal.y);
            return;
        }

        removeFromOpenList(currentNode);
        closedList[currentNode->point.x][currentNode->point.y] = true;

        Point neighbors[4] = {
            {currentNode->point.x + 1, currentNode->point.y},
            {currentNode->point.x - 1, currentNode->point.y},
            {currentNode->point.x, currentNode->point.y + 1},
            {currentNode->point.x, currentNode->point.y - 1}
        };

        for (int i = 0; i < 4; i++) {
            Point neighbor = neighbors[i];
            if (!isValid(neighbor)) continue;

            int gScore = currentNode->g + 1; // Assuming uniform cost
            bool inOpenList = isInOpenList(neighbor);
            Node* neighborNode = (Node*)malloc(sizeof(Node));
            neighborNode->point = neighbor;
            neighborNode->g = gScore;
            neighborNode->h = heuristic(neighbor, goal);
            neighborNode->f = gScore + neighborNode->h;
            neighborNode->parent = currentNode;

            if (!inOpenList) {
                addToOpenList(neighborNode);
            } else {
                for (int j = 0; j < openListCount; j++) {
                    if (openList[j]->point.x == neighbor.x && openList[j]->point.y == neighbor.y && openList[j]->g > gScore) {
                        openList[j]->g = gScore;
                        openList[j]->f = gScore + openList[j]->h;
                        openList[j]->parent = currentNode;
                    }
                }
            }
        }
        free(currentNode);
    }
    printf("No path found.\n");
}

int main() {
    Point start = {0, 0};
    Point goal = {7, 7};

    aStar(start, goal);
    return 0;
}