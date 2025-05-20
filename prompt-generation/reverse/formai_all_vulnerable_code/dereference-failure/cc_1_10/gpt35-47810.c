//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLUMNS 10

// A structure to store nodes of the grid
struct Node {
    int x, y;
    // F, G and H values for a* algorithm
    int f, g, h;
    // Parent of the current node
    struct Node* parent;
};

// Function to return a new node with given parameters
struct Node* newNode(int x, int y) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->x = x;
    node->y = y;
    node->f = 0;
    node->g = 0;
    node->h = 0;
    node->parent = NULL;
    return node;
}

// Function to find the manhattan distance between two nodes
int manhattanDistance(struct Node* a, struct Node* b) {
    int distance = abs(a->x - b->x) + abs(a->y - b->y);
    return distance;
}

// Function to check if the given node is inside the grid
int isInsideGrid(int x, int y) {
    if (x >= 0 && x < ROWS && y >= 0 && y < COLUMNS)
        return 1;
    else
        return 0;
}

// Function to check if the given node is passable or not
int isPassable(int grid[ROWS][COLUMNS], int x, int y) {
    if (grid[x][y] == 1)
        return 1;
    else
        return 0;
}

// Function to check if the given node is the destination node
int isDestination(int x, int y, struct Node* destination) {
    if (x == destination->x && y == destination->y)
        return 1;
    else
        return 0;
}

// Function to print the path from start node to destination node
void printPath(struct Node* destination) {
    if (destination->parent != NULL) {
        printPath(destination->parent);
        printf("(%d,%d) ", destination->x, destination->y);
    }
    else {
        printf("(%d,%d) ", destination->x, destination->y);
    }
}

// Function to perform A* search on the given grid
void aStarSearch(int grid[ROWS][COLUMNS], struct Node* source, struct Node* destination) {
    // Create open and closed lists
    struct Node* openList[ROWS * COLUMNS];
    struct Node* closedList[ROWS * COLUMNS];

    // Add source node to open list
    int openListCount = 0;
    openList[openListCount] = source;
    openList[openListCount]->f = 0;
    openList[openListCount]->g = 0;
    openList[openListCount]->h = 0;
    openListCount++;

    // Loop until the destination node is reached or the open list is empty
    int destinationReached = 0;
    while (openListCount != 0 && destinationReached == 0) {
        // Get the node with the lowest F score from the open list
        int currentIndex = 0;
        for (int i = 0; i < openListCount; i++) {
            if (openList[i]->f < openList[currentIndex]->f) {
                currentIndex = i;
            }
        }
        struct Node* currentNode = openList[currentIndex];

        // Remove current node from open list and add to closed list
        for (int i = currentIndex; i < openListCount - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openListCount--;
        closedList[currentNode->x * COLUMNS + currentNode->y] = currentNode;

        // Check if the current node is the destination node
        if (isDestination(currentNode->x, currentNode->y, destination)) {
            destinationReached = 1;
            printPath(destination);
            return;
        }

        // Generate successors of the current node
        struct Node* successors[4];
        int successorCount = 0;
        int x = currentNode->x;
        int y = currentNode->y;

        if (isInsideGrid(x - 1, y) == 1 && isPassable(grid, x - 1, y) == 1) {
            successors[successorCount] = newNode(x - 1, y);
            successorCount++;
        }

        if (isInsideGrid(x + 1, y) == 1 && isPassable(grid, x + 1, y) == 1) {
            successors[successorCount] = newNode(x + 1, y);
            successorCount++;
        }

        if (isInsideGrid(x, y - 1) == 1 && isPassable(grid, x, y - 1) == 1) {
            successors[successorCount] = newNode(x, y - 1);
            successorCount++;
        }

        if (isInsideGrid(x, y + 1) == 1 && isPassable(grid, x, y + 1) == 1) {
            successors[successorCount] = newNode(x, y + 1);
            successorCount++;
        }

        // For each successor, calculate the F, G and H values
        for (int i = 0; i < successorCount; i++) {
            successors[i]->g = currentNode->g + 1;
            successors[i]->h = manhattanDistance(successors[i], destination);
            successors[i]->f = successors[i]->g + successors[i]->h;
            successors[i]->parent = currentNode;

            // Check if the successor is already in the closed list
            int duplicateFound = 0;
            int index = -1;
            for (int j = 0; j < ROWS * COLUMNS; j++) {
                if (closedList[j] != NULL && successors[i]->x == closedList[j]->x && successors[i]->y == closedList[j]->y) {
                    duplicateFound = 1;
                    index = j;
                    break;
                }
            }

            // Check if the successor is already in the open list
            if (duplicateFound == 0) {
                int index = -1;
                for (int j = 0; j < openListCount; j++) {
                    if (openList[j]->x == successors[i]->x && openList[j]->y == successors[i]->y) {
                        index = j;
                        break;
                    }
                }

                // Add the successor to the open list if it is not already in the list
                if (index == -1) {
                    openList[openListCount] = successors[i];
                    openListCount++;
                }
                else {
                    // Update G value of the successor if the new G value is smaller
                    if (successors[i]->g < openList[index]->g) {
                        openList[index]->g = successors[i]->g;
                        openList[index]->parent = successors[i]->parent;
                    }
                }
            }
            else {
                // Update G value of the successor if the new G value is smaller
                if (successors[i]->g < closedList[index]->g) {
                    closedList[index]->g = successors[i]->g;
                    closedList[index]->parent = successors[i]->parent;

                    // Add the successor back to the open list
                    openList[openListCount] = closedList[index];
                    openListCount++;

                    // Remove the successor from the closed list
                    for (int j = index; j < ROWS * COLUMNS - 1; j++) {
                        closedList[j] = closedList[j + 1];
                    }
                }
            }
        }
    }

    // Destination node cannot be reached
    printf("Destination cannot be reached.");
    return;
}

// Main function to test the A* algorithm
int main() {
    int grid[ROWS][COLUMNS] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    struct Node* source = newNode(1, 1);
    struct Node* destination = newNode(8, 8);
    aStarSearch(grid, source, destination);
    return 0;
}