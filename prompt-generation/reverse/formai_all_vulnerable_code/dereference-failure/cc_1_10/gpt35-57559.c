//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: real-life
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define ROW 10
#define COL 10

// Create a struct for each node in the grid
struct Node {
    int x, y; // x and y coordinates of node
    double f, g, h; // f, g, and h values for A* algorithm
    bool blocked; // if node is blocked or not
    struct Node* parent; // pointer to parent node
};

// Initialize grid with nodes
struct Node* initGrid() {
    struct Node* grid = (struct Node*) malloc(ROW * COL * sizeof(struct Node));
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i*ROW+j].x = i;
            grid[i*ROW+j].y = j;
            grid[i*ROW+j].f = INFINITY;
            grid[i*ROW+j].g = INFINITY;
            grid[i*ROW+j].h = INFINITY;
            grid[i*ROW+j].blocked = false;
            grid[i*ROW+j].parent = NULL;
        }
    }
    return grid;
}

// Calculate Euclidean distance between two nodes
double distance(struct Node* a, struct Node* b) {
    return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));
}

// Check if a node is within the bounds of the grid
bool isInsideGrid(int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

// Check if a node is unblocked and within the bounds of the grid
bool isUnblocked(struct Node* grid, int x, int y) {
    if (isInsideGrid(x, y) && !grid[x*ROW+y].blocked) {
        return true;
    } else {
        return false;
    }
}

// Initialize start and goal nodes
struct Node* initStartGoal(struct Node* grid, int start_x, int start_y, int goal_x, int goal_y) {
    if (!isInsideGrid(start_x, start_y) || !isInsideGrid(goal_x, goal_y)) {
        printf("Start or goal node is out of bounds\n");
        return NULL;
    }
    if (grid[start_x*ROW+start_y].blocked || grid[goal_x*ROW+goal_y].blocked) {
        printf("Start or goal node is blocked\n");
        return NULL;
    }
    struct Node* start = &grid[start_x*ROW+start_y];
    struct Node* goal = &grid[goal_x*ROW+goal_y];
    start->g = 0.0;
    start->h = distance(start, goal);
    start->f = start->g + start->h;
    return goal;
}

// Find the node with the lowest f value in the open list
struct Node* getNextNode(struct Node* openList[], int openSize) {
    double minF = INFINITY;
    struct Node* nextNode = NULL;
    int index = -1;
    for (int i = 0; i < openSize; i++) {
        if (openList[i]->f < minF) {
            minF = openList[i]->f;
            nextNode = openList[i];
            index = i;
        }
    }
    if (index >= 0) {
        for (int i = index; i < openSize-1; i++) {
            openList[i] = openList[i+1];
        }
    }
    return nextNode;
}

// Check if a node is in the given list and return its index
int isInList(struct Node* nodeList[], int listSize, struct Node* node) {
    for (int i = 0; i < listSize; i++) {
        if (nodeList[i] == node) {
            return i;
        }
    }
    return -1;
}

// Update the open list with new nodes and their values
void updateOpenList(struct Node* openList[], int* openSize, struct Node* currentNode, struct Node* goal, struct Node* grid) {
    int x = currentNode->x;
    int y = currentNode->y;
    double newG = 0.0;
    // Look at each adjacent node
    for (int i = x-1; i <= x+1; i++) {
        for (int j = y-1; j <= y+1; j++) {
            // Check if node is unblocked and not the current node
            if (isUnblocked(grid, i, j) && (i != x || j != y)) {
                struct Node* node = &grid[i*ROW+j];
                newG = currentNode->g + distance(currentNode, node);
                // Check if node is not in the closed list and has a lower g value
                int index = isInList(openList, *openSize, node);
                if (index >= 0 && newG < node->g) {
                    node->g = newG;
                    node->f = node->g + node->h;
                    node->parent = currentNode;
                    openList[index] = node;
                // Check if node is not in the open list and add it
                } else if (index < 0) {
                    node->g = newG;
                    node->h = distance(node, goal);
                    node->f = node->g + node->h;
                    node->parent = currentNode;
                    openList[*openSize] = node;
                    (*openSize)++;
                }
            }
        }
    }
}

// Check if two nodes are neighbors
bool areNeighbors(struct Node* a, struct Node* b) {
    if (abs(a->x - b->x) <= 1 && abs(a->y - b->y) <= 1) {
        return true;
    } else {
        return false;
    }
}

// Update the blocked nodes in the grid
void updateGrid(struct Node* grid, struct Node* currentNode) {
    // Look at each node in the grid
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            struct Node* node = &grid[i*ROW+j];
            // Check if node is blocked and not already a neighbor of the current node
            if (node->blocked && !areNeighbors(currentNode, node)) {
                // Check if any adjacent nodes are not blocked
                for (int ii = i-1; ii <= i+1; ii++) {
                    for (int jj = j-1; jj <= j+1; jj++) {
                        if (isUnblocked(grid, ii, jj)) {
                            struct Node* adjNode = &grid[ii*ROW+jj];
                            // Check if node is a neighbor of an adjacent node
                            if (areNeighbors(node, adjNode)) {
                                node->blocked = false;
                            }
                        }
                    }
                }
            }
        }
    }
}

// A* pathfinding algorithm
void AStar(struct Node* grid, int start_x, int start_y, int goal_x, int goal_y) {
    struct Node* goal = initStartGoal(grid, start_x, start_y, goal_x, goal_y);
    if (goal == NULL) {
        return;
    }
    int openSize = 1;
    struct Node* openList[ROW*COL];
    openList[0] = &grid[start_x*ROW+start_y];
    // Look at each node in the grid
    while (openSize > 0) {
        // Find node with lowest f value in open list
        struct Node* currentNode = getNextNode(openList, openSize--);
        // Check if goal node is found
        if (currentNode == goal) {
            return;
        }
        // Add current node to closed list
        currentNode->blocked = true;
        // Update the blocked nodes in the grid
        updateGrid(grid, currentNode);
        // Update open list with new nodes and their values
        updateOpenList(openList, &openSize, currentNode, goal, grid);
    }
    printf("Path not found\n");
}

int main() {
    struct Node* grid = initGrid();
    // Set blocked nodes in grid
    grid[2*ROW+2].blocked = true;
    grid[2*ROW+3].blocked = true;
    grid[3*ROW+2].blocked = true;
    // Find path from start to goal
    AStar(grid, 0, 0, 5, 5);
    return 0;
}