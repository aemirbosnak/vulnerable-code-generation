//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROW 9
#define COL 10

int graph[ROW][COL] = {
    {1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 0, 0},
    {1, 0, 1, 1, 0, 1, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 1, 0, 1, 0, 0, 1}
};

typedef struct {
    int row;
    int col;
} Point;

typedef struct _Node {
    Point point;
    int gCost;
    int hCost;
    struct _Node *parent;
} Node;

Node *openList[ROW * COL];
int openListCount = 0;

Node *closedList[ROW * COL];
int closedListCount = 0;

Point start = {0, 0};
Point end = {ROW - 1, COL - 1};

int calculateDistance(Point p1, Point p2) {
    int dx = abs(p1.row - p2.row);
    int dy = abs(p1.col - p2.col);
    return dx + dy;
}

void clearLists() {
    openListCount = 0;
    closedListCount = 0;
}

void addToOpenList(Node *node) {
    openList[openListCount++] = node;
}

void addToClosedList(Node *node) {
    closedList[closedListCount++] = node;
}

Node *getNodeWithLowestFCost() {
    int lowestFNodeIndex = 0;
    for (int i = 0; i < openListCount; i++) {
        if (openList[i]->gCost + openList[i]->hCost < openList[lowestFNodeIndex]->gCost + openList[lowestFNodeIndex]->hCost) {
            lowestFNodeIndex = i;
        }
    }
    Node *lowestFNode = openList[lowestFNodeIndex];
    for (int i = lowestFNodeIndex; i < openListCount - 1; i++) {
        openList[i] = openList[i + 1];
    }
    openListCount--;
    return lowestFNode;
}

bool isInList(Point point, Node **list, int count) {
    for (int i = 0; i < count; i++) {
        if (list[i]->point.row == point.row && list[i]->point.col == point.col) {
            return true;
        }
    }
    return false;
}

bool isWalkable(Point point) {
    if (graph[point.row][point.col] == 1) {
        return true;
    } else {
        return false;
    }
}

void addNeighbours(Node *current) {
    int row = current->point.row;
    int col = current->point.col;
    Point points[] = {
        {row - 1, col - 1}, {row - 1, col}, {row - 1, col + 1},
        {row, col - 1},                 {row, col + 1},
        {row + 1, col - 1}, {row + 1, col}, {row + 1, col + 1}
    };
    for (int i = 0; i < 8; i++) {
        if (points[i].row < 0 || points[i].row >= ROW || points[i].col < 0 || points[i].col >= COL) {
            continue;
        }
        if (!isWalkable(points[i])) {
            continue;
        }
        if (isInList(points[i], closedList, closedListCount)) {
            continue;
        }
        int tentativeGCost = current->gCost + calculateDistance(current->point, points[i]);
        Node *neighbour;
        if (isInList(points[i], openList, openListCount)) {
            for (int j = 0; j < openListCount; j++) {
                if (openList[j]->point.row == points[i].row && openList[j]->point.col == points[i].col) {
                    neighbour = openList[j];
                    break;
                }
            }
            if (tentativeGCost < neighbour->gCost) {
                neighbour->gCost = tentativeGCost;
                neighbour->parent = current;
            }
        } else {
            neighbour = (Node *)malloc(sizeof(Node));
            neighbour->point = points[i];
            neighbour->gCost = tentativeGCost;
            neighbour->hCost = calculateDistance(points[i], end);
            neighbour->parent = current;
            addToOpenList(neighbour);
        }
    }
}

void printPath(Node *node) {
    if (node->parent != NULL) {
        printPath(node->parent);
    }
    printf("(%d,%d) ", node->point.row, node->point.col);
}

void findPath() {
    Node *startNode = (Node *)malloc(sizeof(Node));
    startNode->point = start;
    startNode->gCost = 0;
    startNode->hCost = calculateDistance(start, end);
    startNode->parent = NULL;
    addToOpenList(startNode);
    
    while (openListCount > 0) {
        Node *currentNode = getNodeWithLowestFCost();
        addToClosedList(currentNode);
        if (currentNode->point.row == end.row && currentNode->point.col == end.col) {
            printf("Path: ");
            printPath(currentNode);
            printf("\n");
            return;
        }
        addNeighbours(currentNode);
    }
    
    printf("Path not found\n");
}

int main() {
    findPath();
    clearLists();
    start = (Point){2, 3};
    findPath();
    return 0;
}