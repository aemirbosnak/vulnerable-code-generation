//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

// Map of the environment
int map[MAP_WIDTH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Node struct for A* algorithm
typedef struct Node {
    int x;
    int y;
    int g; // Cost to reach this node
    int h; // Heuristic estimate of the cost to reach the goal
    int f; // Total cost (g + h)
    struct Node *parent;
} Node;

// Create a new node
Node *createNode(int x, int y, int g, int h, Node *parent) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g = g;
    node->h = h;
    node->f = g + h;
    node->parent = parent;
    return node;
}

// Free a node
void freeNode(Node *node) {
    free(node);
}

// Compare two nodes based on their f values
int compareNodes(const void *a, const void *b) {
    Node *node1 = (Node *)a;
    Node *node2 = (Node *)b;
    return node1->f - node2->f;
}

// Get the neighbors of a node
Node **getNeighbors(Node *node) {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    Node **neighbors = (Node **)malloc(4 * sizeof(Node *));
    for (int i = 0; i < 4; i++) {
        int x = node->x + dx[i];
        int y = node->y + dy[i];
        if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT && map[x][y] == 0) {
            neighbors[i] = createNode(x, y, node->g + 1, abs(x - MAP_WIDTH / 2) + abs(y - MAP_HEIGHT / 2), node);
        } else {
            neighbors[i] = NULL;
        }
    }
    return neighbors;
}

// Find the path from the start node to the goal node
Node *findPath(Node *start, Node *goal) {
    // Create an open set and a closed set
    Node **openSet = (Node **)malloc(MAP_WIDTH * MAP_HEIGHT * sizeof(Node *));
    Node **closedSet = (Node **)malloc(MAP_WIDTH * MAP_HEIGHT * sizeof(Node *));
    int openSetSize = 0;
    int closedSetSize = 0;

    // Add the start node to the open set
    openSet[openSetSize++] = start;

    // While the open set is not empty
    while (openSetSize > 0) {
        // Get the node with the lowest f value from the open set
        qsort(openSet, openSetSize, sizeof(Node *), compareNodes);
        Node *current = openSet[0];

        // If the current node is the goal node, return the path
        if (current->x == goal->x && current->y == goal->y) {
            return current;
        }

        // Move the current node from the open set to the closed set
        openSetSize--;
        closedSet[closedSetSize++] = current;

        // Get the neighbors of the current node
        Node **neighbors = getNeighbors(current);

        // For each neighbor
        for (int i = 0; i < 4; i++) {
            if (neighbors[i] != NULL) {
                // If the neighbor is not in the closed set
                int found = 0;
                for (int j = 0; j < closedSetSize; j++) {
                    if (closedSet[j]->x == neighbors[i]->x && closedSet[j]->y == neighbors[i]->y) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    // Add the neighbor to the open set
                    openSet[openSetSize++] = neighbors[i];
                }
            }
        }

        // Free the neighbors
        for (int i = 0; i < 4; i++) {
            if (neighbors[i] != NULL) {
                freeNode(neighbors[i]);
            }
        }
    }

    // If the open set is empty, there is no path from the start node to the goal node
    return NULL;
}

// Print the path from the start node to the goal node
void printPath(Node *node) {
    if (node->parent != NULL) {
        printPath(node->parent);
    }
    printf("(%d, %d)\n", node->x, node->y);
}

// Main function
int main() {
    // Create the start and goal nodes
    Node *start = createNode(1, 1, 0, abs(1 - MAP_WIDTH / 2) + abs(1 - MAP_HEIGHT / 2), NULL);
    Node *goal = createNode(8, 8, 0, 0, NULL);

    // Find the path from the start node to the goal node
    Node *path = findPath(start, goal);

    // Print the path
    if (path != NULL) {
        printPath(path);
    } else {
        printf("No path found.\n");
    }

    // Free the start and goal nodes
    freeNode(start);
    freeNode(goal);

    return 0;
}