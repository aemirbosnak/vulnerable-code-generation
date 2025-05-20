//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 9

// Defines a node for use in the A* algorithm
typedef struct {
    int row;
    int col;
    int f_score;
    int g_score;
    int h_score;
    bool is_obstacle;
    bool is_visited;
    struct Node* parent;
} Node;

// Creates a new node and initializes it with the given values
Node* createNode(int row, int col, bool is_obstacle) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->is_obstacle = is_obstacle;
    node->is_visited = false;
    node->parent = NULL;
    node->f_score = 0;
    node->g_score = 0;
    node->h_score = 0;
    return node;
}

// Calculates the Manhattan distance between two nodes
int manhattanDistance(Node* node1, Node* node2) {
    int dist = abs(node1->row - node2->row) + abs(node1->col - node2->col);
    return dist;
}

// Initializes the grid with nodes
Node*** initGrid() {
    Node*** grid = (Node***) malloc(sizeof(Node**) * ROW);
    for (int row = 0; row < ROW; row++) {
        grid[row] = (Node**) malloc(sizeof(Node*) * COL);
        for (int col = 0; col < COL; col++) {
            bool is_obstacle = false;
            if (row == 1 && col != 3) is_obstacle = true;
            if (row == 2 && col == 5) is_obstacle = true;
            if (row == 3 && col == 2) is_obstacle = true;
            grid[row][col] = createNode(row, col, is_obstacle);
        }
    }
    return grid;
}

// Checks if a given node is within the bounds of the grid
bool isWithinGrid(int row, int col) {
    return row >= 0 && row < ROW && col >= 0 && col < COL;
}

// Checks if a given node is traversable (not an obstacle and within the grid bounds)
bool isTraversable(Node* node) {
    return !node->is_obstacle && isWithinGrid(node->row, node->col);
}

// Retrieves the neighbors of a given node
Node** getNeighbors(Node*** grid, Node* node) {
    Node** neighbors = (Node**) malloc(sizeof(Node*) * 8);
    int index = 0;
    for (int row = node->row - 1; row <= node->row + 1; row++) {
        for (int col = node->col - 1; col <= node->col + 1; col++) {
            if (row == node->row && col == node->col) continue;  // skip current node
            if (!isWithinGrid(row, col)) continue;  // skip nodes outside grid bounds
            Node* neighbor = grid[row][col];
            if (!isTraversable(neighbor)) continue;  // skip obstacles
            neighbors[index++] = neighbor;
        }
    }
    return neighbors;
}

// Implements the A* pathfinding algorithm to find the shortest path between the start and end points
Node** aStarPathfinding(Node*** grid, Node* start, Node* end) {
    Node** openSet = (Node**) malloc(sizeof(Node*) * ROW * COL);
    Node** closedSet = (Node**) malloc(sizeof(Node*) * ROW * COL);
    int numOpen = 0;
    int numClosed = 0;
    openSet[numOpen++] = start;
    while (numOpen > 0) {
        // Find node with lowest f_score in the open set
        int lowestIndex = 0;
        Node* current = openSet[0];
        for (int i = 1; i < numOpen; i++) {
            if (openSet[i]->f_score < current->f_score) {
                current = openSet[i];
                lowestIndex = i;
            }
        }
        // Remove the current node from the open set and add it to the closed set
        openSet[lowestIndex] = openSet[--numOpen];
        closedSet[numClosed++] = current;
        current->is_visited = true;
        // If current node is the end node, reconstruct the path from start to end
        if (current == end) {
            Node** path = (Node**) malloc(sizeof(Node*) * ROW * COL);
            int pathIndex = 0;
            Node* node = end;
            while (node != start) {
                path[pathIndex++] = node;
                node = node->parent;
            }
            path[pathIndex++] = start;
            return path;
        }
        // Get neighbors of current node
        Node** neighbors = getNeighbors(grid, current);
        for (int i = 0; i < 8; i++) {
            Node* neighbor = neighbors[i];
            if (neighbor == NULL) continue;
            // If neighbor is already in the closed set or not traversable, skip it
            if (neighbor->is_visited || !isTraversable(neighbor)) continue;
            int tentative_g_score = current->g_score + manhattanDistance(current, neighbor);
            if (tentative_g_score < neighbor->g_score || !neighbor->is_visited) {
                neighbor->parent = current;
                neighbor->g_score = tentative_g_score;
                neighbor->h_score = manhattanDistance(neighbor, end);
                neighbor->f_score = neighbor->g_score + neighbor->h_score;
                if (!neighbor->is_visited) {
                    openSet[numOpen++] = neighbor;
                }
            }
        }
    }
    return NULL;  // if end node is not found, return NULL
}

int main() {
    Node*** grid = initGrid();
    Node* start = grid[0][0];
    Node* end = grid[ROW-1][COL-1];
    Node** path = aStarPathfinding(grid, start, end);
    if (path == NULL) {
        printf("No path found!\n");
    } else {
        printf("Path found: ");
        for (int i = ROW*COL-1; i >= 0; i--) {
            if (path[i] == NULL) continue;
            printf("(%d,%d) ", path[i]->row, path[i]->col);
        }
        printf("\n");
    }
    return 0;
}