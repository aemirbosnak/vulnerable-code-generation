//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 8
#define COLS 8

typedef struct {
    int row;
    int col;
} Node;

typedef struct {
    Node parent;
    double f;
    double g;
    double h;
} PathNode;

Node startNode = {0, 0};
Node endNode = {7, 7};
int grid[ROWS][COLS] = {
        {1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 1, 1, 1, 1, 0}
};

PathNode* createNode(int row, int col, double f, double g, double h, Node parent) {
    PathNode* node = malloc(sizeof(PathNode));
    node->parent = parent;
    node->f = f;
    node->g = g;
    node->h = h;
    return node;
}

double calculateHValue(Node node) {
    return sqrt(pow((double)(node.row - endNode.row), 2) + pow((double)(node.col - endNode.col), 2));
}

double calculateGValue(Node node) {
    return node.row + node.col;
}

double calculateFValue(Node node) {
    return calculateHValue(node) + calculateGValue(node);
}

int checkIfInList(PathNode** list, Node node, int listLength) {
    for (int i = 0; i < listLength; i++) {
        if (list[i]->parent.row == node.row && list[i]->parent.col == node.col) {
            return i;
        }
    }
    return -1;
}

void printPath(PathNode** path, int pathLength) {
    printf("Path:\n");
    for (int i = 0; i < pathLength; i++) {
        printf("(%d,%d) ", path[i]->parent.row, path[i]->parent.col);
    }
    printf("\n");
}

void findPath() {
    PathNode* openList[ROWS * COLS];
    int openListLength = 1;
    PathNode* closedList[ROWS * COLS];
    int closedListLength = 0;
    PathNode* current = createNode(startNode.row, startNode.col, 0, 0, 0, startNode);
    openList[0] = current;
    while (openListLength > 0) {
        int currentIndex = 0;
        for (int i = 0; i < openListLength; i++) {
            if (openList[i]->f < openList[currentIndex]->f) {
                currentIndex = i;
            }
        }
        current = openList[currentIndex];
        if (current->parent.row == endNode.row && current->parent.col == endNode.col) {
            PathNode* path[ROWS * COLS];
            int pathLength = 0;
            path[0] = current;
            pathLength++;
            while (path[pathLength - 1]->parent.row != startNode.row || path[pathLength - 1]->parent.col != startNode.col) {
                int i = checkIfInList(closedList, path[pathLength - 1]->parent, closedListLength);
                path[pathLength] = closedList[i];
                pathLength++;
            }
            printPath(path, pathLength);
            return;
        }
        for (int rowOffset = -1; rowOffset <= 1; rowOffset++) {
            for (int colOffset = -1; colOffset <= 1; colOffset++) {
                if (rowOffset == 0 && colOffset == 0) {
                    continue;
                }
                Node neighbor = {current->parent.row + rowOffset, current->parent.col + colOffset};
                if (neighbor.row < 0 || neighbor.row >= ROWS || neighbor.col < 0 || neighbor.col >= COLS) {
                    continue;
                }
                if (grid[neighbor.row][neighbor.col] == 0) {
                    continue;
                }
                double g = current->g + sqrt(pow((double)rowOffset, 2) + pow((double)colOffset, 2));
                double h = calculateHValue(neighbor);
                double f = g + h;
                int index = checkIfInList(closedList, neighbor, closedListLength);
                if (index >= 0 && closedList[index]->f <= f) {
                    continue;
                }
                index = checkIfInList(openList, neighbor, openListLength);
                if (index >= 0 && openList[index]->f <= f) {
                    continue;
                }
                PathNode* node = createNode(neighbor.row, neighbor.col, f, g, h, current->parent);
                openList[openListLength] = node;
                openListLength++;
            }
        }
        closedList[closedListLength] = current;
        closedListLength++;
        for (int i = currentIndex; i < openListLength - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openListLength--;
    }
    printf("No path found.\n");
}

int main() {
    findPath();
    return 0;
}