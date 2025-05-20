//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10

// define the node structure
typedef struct Node {
    int x, y;
    int f, g, h;
    struct Node* parent;
} Node;

// initialize the grid
int grid[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// define the open and closed lists
Node* openList[ROWS * COLS];
Node* closedList[ROWS * COLS];

// initialize the open and closed list count
int openListCount = 0;
int closedListCount = 0;

// define the start and end nodes
Node* startNode = NULL;
Node* endNode = NULL;

// define the heuristic function, in this case Manhattan distance
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// define the function to check if a node is in the closed list
int inClosedList(Node* node) {
    int i;
    for (i = 0; i < closedListCount; i++) {
        if (closedList[i]->x == node->x && closedList[i]->y == node->y) {
            return 1;
        }
    }
    return 0;
}

// define the function to check if a node is in the open list
int inOpenList(Node* node) {
    int i;
    for (i = 0; i < openListCount; i++) {
        if (openList[i]->x == node->x && openList[i]->y == node->y) {
            return 1;
        }
    }
    return 0;
}

// define the function to add a node to the open list
void addToOpenList(Node* node) {
    openList[openListCount++] = node;
}

// define the function to remove a node from the open list
void removeFromOpenList(Node* node) {
    int i;
    for (i = 0; i < openListCount; i++) {
        if (openList[i] == node) {
            while (i < openListCount - 1) {
                openList[i] = openList[i + 1];
                i++;
            }
            openListCount--;
            return;
        }
    }
}

// define the function to get the node with the lowest F value from the open list
Node* getLowestFNodeFromOpenList() {
    int i;
    Node* lowestFNode = openList[0];
    for (i = 1; i < openListCount; i++) {
        if (openList[i]->f < lowestFNode->f) {
            lowestFNode = openList[i];
        }
    }
    return lowestFNode;
}

// define the function to generate the path
void generatePath(Node* node) {
    if (node == startNode) {
        printf("(%d, %d)\n", node->x, node->y);
        return;
    }
    generatePath(node->parent);
    printf("(%d, %d)\n", node->x, node->y);
}

int main() {
    // set the start and end nodes
    startNode = (Node*)malloc(sizeof(Node));
    startNode->x = 0;
    startNode->y = 0;
    endNode = (Node*)malloc(sizeof(Node));
    endNode->x = 9;
    endNode->y = 9;

    // initialize the start node's F, G and H values
    startNode->f = 0;
    startNode->g = 0;
    startNode->h = heuristic(startNode->x, startNode->y, endNode->x, endNode->y);

    // add the start node to the open list
    addToOpenList(startNode);

    // loop until the end node is found
    while (openListCount > 0) {
        // get the node with the lowest F value from the open list
        Node* currentNode = getLowestFNodeFromOpenList();

        // if the current node is the end node, generate the path and break out of the loop
        if (currentNode->x == endNode->x && currentNode->y == endNode->y) {
            generatePath(currentNode);
            break;
        }

        // remove the current node from the open list and add it to the closed list
        removeFromOpenList(currentNode);
        closedList[closedListCount++] = currentNode;

        // check the neighbor nodes
        int i, j;
        for (i = -1; i <= 1; i++) {
            for (j = -1; j <= 1; j++) {
                // skip the current node
                if (i == 0 && j == 0) continue;

                // calculate the neighbor node's coordinates
                int x = currentNode->x + i;
                int y = currentNode->y + j;

                // if the neighbor node is out of bounds, skip it
                if (x < 0 || x >= ROWS || y < 0 || y >= COLS) continue;

                // if the neighbor node is a wall or already in the closed list, skip it
                if (grid[x][y] == 1 || inClosedList(&(Node){x, y, 0, 0, 0, NULL})) continue;

                // calculate the neighbor node's G and H values
                int g = currentNode->g + 1;
                int h = heuristic(x, y, endNode->x, endNode->y);

                // create a new neighbor node and set its F, G and H values, and parent
                Node* neighborNode = (Node*)malloc(sizeof(Node));
                neighborNode->x = x;
                neighborNode->y = y;
                neighborNode->f = g + h;
                neighborNode->g = g;
                neighborNode->h = h;
                neighborNode->parent = currentNode;

                // if the neighbor node is already in the open list, update its G value and parent if necessary
                if (inOpenList(neighborNode)) {
                    Node* openListNode = openList[i];
                    if (g + h < openListNode->f) {
                        openListNode->f = g + h;
                        openListNode->g = g;
                        openListNode->h = h;
                        openListNode->parent = currentNode;
                    }
                }
                // otherwise, add the neighbor node to the open list
                else {
                    addToOpenList(neighborNode);
                }
            }
        }
    }

    return 0;
}