//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 10
#define COLS 10

// Node structure
typedef struct Node {
    int x, y;
    double f, g, h;
    struct Node* parent;
} Node;

// Map grid
int map[ROWS][COLS] = {
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// Calculates Euclidean distance between two points
double euclideanDistance(int x1, int y1, int x2, int y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx*dx + dy*dy);
}

// Returns the node with the lowest f value
Node* getLowestF(Node** openList, int numNodes) {
    Node* lowest = openList[0];
    for (int i = 1; i < numNodes; i++) {
        if (openList[i]->f < lowest->f) {
            lowest = openList[i];
        }
    }
    return lowest;
}

// Checks whether the given node is in the list
int inList(Node** list, int numNodes, Node* node) {
    for (int i = 0; i < numNodes; i++) {
        if (list[i]->x == node->x && list[i]->y == node->y) {
            return 1;
        }
    }
    return 0;
}

// Generates the path from the end node to the start node
Node** generatePath(Node* end, int* numNodes) {
    Node** path = (Node**) malloc(sizeof(Node*)*ROWS*COLS);
    Node* current = end;
    int count = 0;

    while (current->parent != NULL) {
        path[count++] = current;
        current = current->parent;
    }

    path[count] = current;

    *numNodes = count + 1;

    return path;
}

// A* algorithm implementation
Node** aStar(Node* start, Node* end, int* numNodes) {
    Node* openList[ROWS*COLS] = {NULL};
    Node* closedList[ROWS*COLS] = {NULL};
    int numOpen = 0;
    int numClosed = 0;

    // Add start node to open list
    openList[numOpen++] = start;

    while (numOpen > 0) {
        // Get node with lowest f value from open list
        Node* current = getLowestF(openList, numOpen);

        // Move current node from open to closed list
        openList[numOpen--] = NULL;
        closedList[numClosed++] = current;

        // Check if node is the end node
        if (current->x == end->x && current->y == end->y) {
            return generatePath(current, numNodes);
        }

        // Generate successors
        Node* successors[8] = {NULL};
        int numSuccessors = 0;

        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                if (x == 0 && y == 0) {
                    continue;
                }

                int checkX = current->x + x;
                int checkY = current->y + y;

                if (checkX < 0 || checkX >= COLS || checkY < 0 || checkY >= ROWS) {
                    continue;
                }

                if (map[checkY][checkX] == 1) {
                    continue;
                }

                Node* successor = (Node*) malloc(sizeof(Node));
                successor->x = checkX;
                successor->y = checkY;
                successor->parent = current;
                successor->g = current->g + euclideanDistance(current->x, current->y, checkX, checkY);
                successor->h = euclideanDistance(checkX, checkY, end->x, end->y);
                successor->f = successor->g + successor->h;

                if (inList(openList, numOpen, successor) || inList(closedList, numClosed, successor)) {
                    free(successor);
                    continue;
                }

                successors[numSuccessors++] = successor;
            }
        }

        // Add successors to open list
        for (int i = 0; i < numSuccessors; i++) {
            openList[numOpen++] = successors[i];
        }
    }

    // No path found
    return NULL;
}

// Main function
int main() {
    Node* start = (Node*) malloc(sizeof(Node));
    start->x = 0;
    start->y = 0;
    start->parent = NULL;
    start->g = 0;
    start->h = euclideanDistance(start->x, start->y, COLS-1, ROWS-1);
    start->f = start->g + start->h;

    Node* end = (Node*) malloc(sizeof(Node));
    end->x = COLS-1;
    end->y = ROWS-1;
    end->parent = NULL;
    end->g = 0;
    end->h = 0;
    end->f = 0;

    int numNodes;
    Node** path = aStar(start, end, &numNodes);

    if (path != NULL) {
        printf("Path found! Nodes: %d\n", numNodes);
        for (int i = numNodes-1; i >= 0; i--) {
            printf("(%d, %d)\n", path[i]->x, path[i]->y);
        }
    }
    else {
        printf("No path found!\n");
    }

    return 0;
}