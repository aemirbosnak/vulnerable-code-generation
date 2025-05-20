//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the grid size
#define ROW 5
#define COL 5

// Define the structure of a node in the grid
struct Node {
    int row;
    int col;
    int fScore;
    int gScore;
    int hScore;
    bool closed;
    struct Node* prev;
};

// Define the heuristic function to calculate the Manhattan distance between two nodes
int heuristic(struct Node* node1, struct Node* node2) {
    int distance = abs(node1->row - node2->row) + abs(node1->col - node2->col);
    return distance;
}

// Define the function to find the lowest fScore node
struct Node* minFScore(struct Node* grid[ROW][COL]) {
    int minF = ROW*COL+1;
    struct Node* minNode;
    for (int row=0; row < ROW; row++) {
        for (int col=0; col < COL; col++) {
            if (!grid[row][col]->closed && grid[row][col]->fScore < minF) {
                minF = grid[row][col]->fScore;
                minNode = grid[row][col];
            }
        }
    }
    return minNode;
}

// Define the function to check if a node is in a list
bool inList(struct Node* list[], struct Node* node) {
    for (int i=0; i<ROW*COL; i++) {
        if (list[i] == node) {
            return true;
        }
    }
    return false;
}

// Define the function to get all the neighbors of a node
void getNeighbors(struct Node* grid[ROW][COL], struct Node* node, struct Node* neighbors[]) {
    if (node->row > 0) {
        neighbors[0] = grid[node->row-1][node->col]; // Up
    } else {
        neighbors[0] = NULL;
    }
    if (node->row < ROW-1) {
        neighbors[1] = grid[node->row+1][node->col]; // Down
    } else {
        neighbors[1] = NULL;
    }
    if (node->col > 0) {
        neighbors[2] = grid[node->row][node->col-1]; // Left
    } else {
        neighbors[2] = NULL;
    }
    if (node->col < COL-1) {
        neighbors[3] = grid[node->row][node->col+1]; // Right
    } else {
        neighbors[3] = NULL;
    }
}

// Define the function to reconstruct the path from start to end node
void reconstructPath(struct Node* start, struct Node* end) {
    struct Node* current = end;
    while (current != start) {
        printf("(%d,%d) ", current->row, current->col);
        current = current->prev;
    }
    printf("(%d,%d)\n", start->row, start->col);
}

// Define the A* pathfinding algorithm
void AStar(struct Node* grid[ROW][COL], struct Node* start, struct Node* end) {
    // Add the start node to the open list
    struct Node* openList[ROW*COL];
    int openListLen = 0;
    openList[openListLen] = start;
    openListLen++;

    // Initially, all nodes are not closed
    for (int row=0; row < ROW; row++) {
        for (int col=0; col < COL; col++) {
            grid[row][col]->closed = false;
        }
    }

    // Set the gScore of the start node to 0
    start->gScore = 0;

    // While the open list is not empty
    while (openListLen > 0) {
        // Find the node with the lowest fScore
        struct Node* current = minFScore(grid);

        // If the current node is the end node
        if (current == end) {
            reconstructPath(start, end);
            return;
        }

        // Remove the current node from the open list
        for (int i=0; i<openListLen; i++) {
            if (openList[i] == current) {
                openList[i] = openList[openListLen-1];
                openListLen--;
            }
        }

        // Set the current node as closed
        current->closed = true;

        // Get all the neighbors of the current node
        struct Node* neighbors[4];
        getNeighbors(grid, current, neighbors);

        // For each neighbor of the current node
        for (int i=0; i<4; i++) {
            if (neighbors[i] == NULL) {
                continue;
            }
            // If the neighbor is already closed
            if (neighbors[i]->closed) {
                continue;
            }
            // Calculate the tentative gScore and hScore
            int tentativeGScore = current->gScore + 1;
            int tentativeHScore = heuristic(neighbors[i], end);
            int tentativeFScore = tentativeGScore + tentativeHScore;
            // If the neighbor is not in the open list
            if (!inList(openList, neighbors[i])) {
                // Add it to the open list
                openList[openListLen] = neighbors[i];
                openListLen++;
                // Set the tentative scores
                neighbors[i]->gScore = tentativeGScore;
                neighbors[i]->hScore = tentativeHScore;
                neighbors[i]->fScore = tentativeFScore;
                // Set the previous node to the current node
                neighbors[i]->prev = current;
            } else {
                // If the neighbor is already in the open list
                // Update its scores if the tentative score is lower
                if (tentativeFScore < neighbors[i]->fScore) {
                    neighbors[i]->gScore = tentativeGScore;
                    neighbors[i]->hScore = tentativeHScore;
                    neighbors[i]->fScore = tentativeFScore;
                    neighbors[i]->prev = current;
                }
            }
        }
    }

    // If the end node is not reached
    printf("Path not found\n");
}

// Define the main function
int main() {
    // Initialize the grid
    struct Node* grid[ROW][COL];
    for (int row=0; row < ROW; row++) {
        for (int col=0; col < COL; col++) {
            grid[row][col] = malloc(sizeof(struct Node));
            grid[row][col]->row = row;
            grid[row][col]->col = col;
            grid[row][col]->fScore = ROW*COL+1;
            grid[row][col]->gScore = ROW*COL+1;
            grid[row][col]->hScore = ROW*COL+1;
            grid[row][col]->closed = false;
            grid[row][col]->prev = NULL;
        }
    }

    // Set the start and end nodes
    struct Node* start = grid[0][0];
    struct Node* end = grid[ROW-1][COL-1];

    // Find the path from start to end
    AStar(grid, start, end);

    return 0;
}