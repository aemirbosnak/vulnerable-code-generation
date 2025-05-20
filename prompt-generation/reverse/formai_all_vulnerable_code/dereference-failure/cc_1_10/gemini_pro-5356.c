//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node struct to represent a cell in the grid
typedef struct Node {
    int x, y;              // Coordinates of the cell
    int f, g, h;          // f, g, and h values for A*
    struct Node *parent;   // Parent node in the path
} Node;

// Grid struct to represent the 2D grid
typedef struct Grid {
    int width, height;     // Width and height of the grid
    Node **nodes;         // Array of nodes
} Grid;

// Function to create a new grid
Grid* createGrid(int width, int height) {
    Grid *grid = (Grid*)malloc(sizeof(Grid));
    grid->width = width;
    grid->height = height;
    grid->nodes = (Node**)malloc(sizeof(Node*) * width * height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            grid->nodes[i * height + j] = (Node*)malloc(sizeof(Node));
            grid->nodes[i * height + j]->x = i;
            grid->nodes[i * height + j]->y = j;
            grid->nodes[i * height + j]->f = INT_MAX;
            grid->nodes[i * height + j]->g = INT_MAX;
            grid->nodes[i * height + j]->h = INT_MAX;
            grid->nodes[i * height + j]->parent = NULL;
        }
    }
    return grid;
}

// Function to free the memory allocated for the grid
void freeGrid(Grid *grid) {
    for (int i = 0; i < grid->width; i++) {
        for (int j = 0; j < grid->height; j++) {
            free(grid->nodes[i * grid->height + j]);
        }
    }
    free(grid->nodes);
    free(grid);
}

// Function to set the obstacle cells in the grid
void setObstacles(Grid *grid, int numObstacles) {
    while (numObstacles--) {
        int x = rand() % grid->width;
        int y = rand() % grid->height;
        grid->nodes[x * grid->height + y]->f = INT_MAX;
    }
}

// Function to calculate the h value for a node
int calculateHValue(Node *node, Node *goal) {
    return abs(node->x - goal->x) + abs(node->y - goal->y);
}

// Function to calculate the f value for a node
int calculateFValue(Node *node) {
    return node->g + node->h;
}

// Function to find the neighbors of a node
Node** getNeighbors(Grid *grid, Node *node) {
    Node **neighbors = (Node**)malloc(sizeof(Node*) * 4);
    int index = 0;
    if (node->x > 0) neighbors[index++] = grid->nodes[(node->x - 1) * grid->height + node->y];
    if (node->x < grid->width - 1) neighbors[index++] = grid->nodes[(node->x + 1) * grid->height + node->y];
    if (node->y > 0) neighbors[index++] = grid->nodes[node->x * grid->height + (node->y - 1)];
    if (node->y < grid->height - 1) neighbors[index++] = grid->nodes[node->x * grid->height + (node->y + 1)];
    return neighbors;
}

// Function to implement the A* algorithm
Node* aStar(Grid *grid, Node *start, Node *goal) {
    // Initialize the open and closed lists
    Node **openList = (Node**)malloc(sizeof(Node*) * grid->width * grid->height);
    int openListSize = 0;
    Node **closedList = (Node**)malloc(sizeof(Node*) * grid->width * grid->height);
    int closedListSize = 0;
    
    // Add the start node to the open list
    openList[openListSize++] = start;
    
    // While the open list is not empty
    while (openListSize > 0) {
        // Find the node with the lowest f value in the open list
        Node *currentNode = openList[0];
        for (int i = 1; i < openListSize; i++) {
            if (openList[i]->f < currentNode->f) {
                currentNode = openList[i];
            }
        }
        
        // If the current node is the goal node, return it
        if (currentNode == goal) {
            return currentNode;
        }
        
        // Move the current node from the open list to the closed list
        openListSize--;
        for (int i = 0; i < openListSize; i++) {
            if (openList[i] == currentNode) {
                openList[i] = openList[openListSize];
                break;
            }
        }
        closedList[closedListSize++] = currentNode;
        
        // Get the neighbors of the current node
        Node **neighbors = getNeighbors(grid, currentNode);
        
        // For each neighbor of the current node
        for (int i = 0; i < 4; i++) {
            Node *neighbor = neighbors[i];
            
            // If the neighbor is not in the closed list and is not an obstacle
            if (!neighbor || neighbor->f == INT_MAX) {
                continue;
            }
            
            // Calculate the g value for the neighbor
            int g = currentNode->g + 1;
            
            // If the neighbor is not in the open list or the new g value is lower than the old g value
            if (!neighbor || g < neighbor->g) {
                // Update the neighbor's g, h, and f values
                neighbor->g = g;
                neighbor->h = calculateHValue(neighbor, goal);
                neighbor->f = calculateFValue(neighbor);
                
                // Add the neighbor to the open list
                openList[openListSize++] = neighbor;
                
                // Set the neighbor's parent to the current node
                neighbor->parent = currentNode;
            }
        }
    }
    
    // If the goal node was not found, return NULL
    return NULL;
}

// Function to print the path from the start node to the goal node
void printPath(Node *goal) {
    if (!goal) {
        printf("No path found\n");
        return;
    }
    Node *current = goal;
    while (current) {
        printf("(%d, %d)\n", current->x, current->y);
        current = current->parent;
    }
}

// Main function
int main() {
    // Create a grid
    Grid *grid = createGrid(10, 10);
    
    // Set some obstacles in the grid
    setObstacles(grid, 5);
    
    // Create the start and goal nodes
    Node *start = grid->nodes[0];
    Node *goal = grid->nodes[9 * grid->height + 9];
    
    // Find the path from the start node to the goal node
    Node *path = aStar(grid, start, goal);
    
    // Print the path
    printPath(path);
    
    // Free the memory allocated for the grid
    freeGrid(grid);
    
    return 0;
}