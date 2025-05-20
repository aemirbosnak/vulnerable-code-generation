//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 5
#define COL 5

// Define a structure for the Node in the pathfinding algorithm
typedef struct Node {
    int x;
    int y;
    int cost;
    int heuristic;
    int f; // Total cost
    struct Node* parent;
} Node;

// Function to create a new Node
Node* createNode(int x, int y, int cost, int heuristic, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->cost = cost;
    newNode->heuristic = heuristic;
    newNode->f = cost + heuristic;
    newNode->parent = parent;
    return newNode;
}

// Comparison function for A* search
int compare(const void* a, const void* b) {
    return ((Node*)a)->f - ((Node*)b)->f;
}

// Function for the heuristic estimation (Manhattan distance)
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Check if the given cell is within the grid and walkable
int isValid(int grid[ROW][COL], int visited[ROW][COL], int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL && grid[x][y] == 0 && !visited[x][y]);
}

// Function to implement A* algorithm
void AStar(int grid[ROW][COL], int startX, int startY, int endX, int endY) {
    int visited[ROW][COL] = {0}; // Track visited nodes
    Node* openList[ROW * COL]; // To store open nodes
    int openCount = 0;

    Node* startNode = createNode(startX, startY, 0, heuristic(startX, startY, endX, endY), NULL);
    openList[openCount++] = startNode;

    while (openCount > 0) {
        // Sort and retrieve the node with the lowest f value
        qsort(openList, openCount, sizeof(Node*), compare);
        Node* currentNode = openList[0];

        // Check if we reached the destination
        if (currentNode->x == endX && currentNode->y == endY) {
            printf("Path found:\n");
            Node* temp = currentNode;
            while(temp) {
                printf("(%d, %d) -> ", temp->x, temp->y);
                temp = temp->parent;
            }
            printf("Goal\n");
            free(currentNode);
            break;
        }

        // Remove current node from open list
        visited[currentNode->x][currentNode->y] = 1;
        openCount--;
        for (int i = 0; i < openCount; i++) {
            if (openList[i] == currentNode) {
                openList[i] = openList[openCount]; // Swap with the last element
                break;
            }
        }

        // Explore neighbors
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx + dy) == 1) { // Valid moves only: up, down, left, right
                    int newX = currentNode->x + dx;
                    int newY = currentNode->y + dy;

                    if (isValid(grid, visited, newX, newY)) {
                        int newCost = currentNode->cost + 1; // Assume cost between nodes is 1
                        Node* neighborNode = createNode(newX, newY, newCost, heuristic(newX, newY, endX, endY), currentNode);

                        // Check if the node is already in the open list
                        int found = 0;
                        for (int j = 0; j < openCount; j++) {
                            if (openList[j]->x == neighborNode->x && openList[j]->y == neighborNode->y) {
                                found = 1;
                                if (newCost < openList[j]->cost) {
                                    // Replace with the cheaper cost node
                                    openList[j] = neighborNode;
                                }
                                break;
                            }
                        }
                        if (!found) {
                            openList[openCount++] = neighborNode;
                        } else {
                            free(neighborNode); // Free memory if already in open list
                        }
                    }
                }
            }
        }
        free(currentNode); // Free memory for the current node
    }

    // Clean up remaining open nodes
    for (int i = 0; i < openCount; i++) {
        free(openList[i]);
    }
}

// Main function to test the A* algorithm
int main() {
    // Example grid: 0 = walkable, 1 = blocked
    int grid[ROW][COL] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };

    int startX = 0, startY = 0;
    int endX = 4, endY = 4;

    AStar(grid, startX, startY, endX, endY);

    return 0;
}