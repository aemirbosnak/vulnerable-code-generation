//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROWS 7
#define COLS 10

// Define the struct for nodes
typedef struct node {
    int row, col;
    int f, g, h;
    struct node *parent;
} node_t;

// Define the start and end nodes
node_t startNode = {3, 0, 0, 0, 0, NULL};
node_t endNode = {3, 9, 0, 0, 0, NULL};

// Define the coordinates of obstacles
int obstacles[5][2] = {{1, 3}, {2, 3}, {2, 2}, {4, 5}, {5, 5}};

// Define the heuristic function
int heuristic(node_t current) {
    int dx = abs(current.col - endNode.col);
    int dy = abs(current.row - endNode.row);
    return dx + dy;
}

// Define the function to check if a node is valid
bool isValid(node_t current, int map[ROWS][COLS]) {
    if (current.row < 0 || current.row >= ROWS || current.col < 0 || current.col >= COLS) {
        return false;
    }
    if (map[current.row][current.col] == 1) { // if obstacle is at current node
        return false;
    }
    return true;
}

// Define the function to check if a node is in the closed list
bool isClosed(node_t current, node_t *closedList) {
    for (int i = 0; i < ROWS * COLS; i++) {
        if (closedList[i].row == current.row && closedList[i].col == current.col) {
            return true;
        }
    }
    return false;
}

// Define the function to check if a node is in the open list and returns the node if it is found
node_t* isOpen(node_t current, node_t **openList, int *numOpen) {
    for (int i = 0; i < *numOpen; i++) {
        if (openList[i]->row == current.row && openList[i]->col == current.col) {
            return openList[i];
        }
    }
    return NULL;
}

// Define the function to add a node to the open list in sorted order
void addOpen(node_t *current, node_t **openList, int *numOpen) {
    int i;
    for (i = 0; i < *numOpen; i++) {
        if (current->f < openList[i]->f) {
            break;
        }
    }
    for (int j = *numOpen - 1; j >= i; j--) {
        openList[j + 1] = openList[j];
    }
    openList[i] = current;
    (*numOpen)++;
}

// Define the function to print the map with path
void printMap(int map[ROWS][COLS], node_t *startNode, node_t *endNode) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (startNode->row == i && startNode->col == j) {
                printf("S ");
            } else if (endNode->row == i && endNode->col == j) {
                printf("E ");
            } else if (map[i][j] == 1) {
                printf("X ");
            } else if (map[i][j] == 2) {
                printf(". ");
            } else if (map[i][j] == 3) {
                printf("* ");
            }
        }
        printf("\n");
    }
}

// Define the main function
int main() {
    // Initialize the map
    int map[ROWS][COLS] = {0};
    for (int i = 0; i < 5; i++) {
        map[obstacles[i][0]][obstacles[i][1]] = 1;
    }
    map[startNode.row][startNode.col] = 2;
    map[endNode.row][endNode.col] = 2;

    // Initialize the open and closed lists
    node_t **openList = calloc(ROWS * COLS, sizeof(node_t*));
    int numOpen = 0;
    node_t *closedList = calloc(ROWS * COLS, sizeof(node_t));
    int numClosed = 0;

    // Add the start node to the open list
    addOpen(&startNode, openList, &numOpen);

    // Loop through until the end node is found or open list is empty
    while (numOpen > 0) {
        // Take the node with the lowest f score from the open list
        node_t *current = openList[0];
        for (int i = 0; i < numOpen - 1; i++) {
            openList[i] = openList[i + 1];
        }
        numOpen--;

        // Add the current node to the closed list
        closedList[numClosed] = *current;
        numClosed++;

        // Check if the current node is the end node
        if (current->row == endNode.row && current->col == endNode.col) {
            node_t *path = current;
            // Mark the path on the map
            while (path != NULL) {
                map[path->row][path->col] = 3;
                path = path->parent;
            }
            printMap(map, &startNode, &endNode);
            break;
        }

        // Generate the neighboring nodes
        node_t neighbors[4];
        neighbors[0] = (node_t) {current->row - 1, current->col, 0, 0, 0, current};
        neighbors[1] = (node_t) {current->row, current->col + 1, 0, 0, 0, current};
        neighbors[2] = (node_t) {current->row + 1, current->col, 0, 0, 0, current};
        neighbors[3] = (node_t) {current->row, current->col - 1, 0, 0, 0, current};

        // Loop through the neighbors
        for (int i = 0; i < 4; i++) {
            // Check if the neighbor is valid
            if (!isValid(neighbors[i], map)) {
                continue;
            }
            // Calculate the g, h, and f scores for the neighbor
            neighbors[i].g = current->g + 1; // Each movement to an adjacent square costs 1
            neighbors[i].h = heuristic(neighbors[i]);
            neighbors[i].f = neighbors[i].g + neighbors[i].h;
            // Check if the neighbor is already in the closed list
            if (isClosed(neighbors[i], closedList)) {
                continue;
            }
            // Check if the neighbor is already in the open list and update its f score if needed
            node_t *openNode = isOpen(neighbors[i], openList, &numOpen);
            if (openNode != NULL) {
                if (neighbors[i].f < openNode->f) {
                    openNode->f = neighbors[i].f;
                    openNode->g = neighbors[i].g;
                    openNode->h = neighbors[i].h;
                    openNode->parent = neighbors[i].parent;
                }
                continue;
            }
            // Add the neighbor to the open list
            node_t *newNeighbor = calloc(1, sizeof(node_t));
            *newNeighbor = neighbors[i];
            addOpen(newNeighbor, openList, &numOpen);
            // Mark the neighbor on the map
            map[neighbors[i].row][neighbors[i].col] = 2;
        }
    }

    // Free the memory allocated for the open and closed lists
    for (int i = 0; i < numOpen; i++) {
        free(openList[i]);
    }
    free(openList);
    free(closedList);

    return 0;
}