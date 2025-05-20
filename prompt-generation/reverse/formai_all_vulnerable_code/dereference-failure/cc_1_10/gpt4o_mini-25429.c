//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define WIDTH 10
#define HEIGHT 10
#define STACK_SIZE 100

typedef struct {
    int x, y;
} Node;

typedef struct {
    Node *nodes;
    int size;
    int capacity;
} NodeList;

typedef struct {
    Node position;
    int gCost;
    int hCost;
    int fCost;
    Node *parent;
} PathNode;

typedef struct {
    PathNode *nodes;
    int size;
    int capacity;
} PathNodeList;

NodeList openSet;
NodeList closedSet;

// Function declarations
void initNodeList(NodeList *list, int capacity);
void addNode(NodeList *list, Node node);
Node removeNode(NodeList *list);
bool isNodeInList(NodeList *list, Node node);
int calculateH(Node a, Node b);
int calculateFCost(PathNode* node);
void reconstructPath(PathNode *node);
bool isWalkable(char grid[HEIGHT][WIDTH], int x, int y);
void aStar(char grid[HEIGHT][WIDTH], Node start, Node end);

// Main function to run A* algorithm
int main() {
    char grid[HEIGHT][WIDTH] = {
        {'S', '.', '.', '#', '.', '.', '.', '#', '.', 'E'},
        {'.', '#', '.', '#', '.', '#', '.', '#', '.', '.'},
        {'.', '#', '.', '.', '.', '.', '.', '#', '#', '.'},
        {'.', '.', '#', '#', '#', '.', '#', '.', '.', '.'},
        {'#', '#', '#', '.', '#', '.', '#', '#', '#', '#'},
        {'.', '.', '.', '.', '.', '.', '#', '.', '.', '.'},
        {'.', '#', '#', '#', '#', '.', '#', '#', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '#', '.'},
        {'#', '#', '#', '#', '#', '.', '#', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };

    Node start = {0, 0}; // Starting Position 'S'
    Node end = {0, 8};   // Ending Position 'E'

    aStar(grid, start, end);
    
    return 0;
}

// A* Pathfinding Algorithm
void aStar(char grid[HEIGHT][WIDTH], Node start, Node end) {
    initNodeList(&openSet, STACK_SIZE);
    initNodeList(&closedSet, STACK_SIZE);

    PathNodeList pathNodeList;
    pathNodeList.nodes = malloc(STACK_SIZE * sizeof(PathNode));
    pathNodeList.size = 0;
    pathNodeList.capacity = STACK_SIZE;

    PathNode startNode = {start, 0, calculateH(start, end), 0, NULL};
    addNode(&openSet, start);

    while (openSet.size > 0) {
        Node current = removeNode(&openSet);
        if (current.x == end.x && current.y == end.y) {
            reconstructPath(&startNode);
            break;
        }

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) + abs(dy) == 1) {
                    int newX = current.x + dx;
                    int newY = current.y + dy;

                    if (isWalkable(grid, newX, newY) && !isNodeInList(&closedSet, (Node){newX, newY})) {
                        PathNode *neighborNode = malloc(sizeof(PathNode));
                        neighborNode->position = (Node){newX, newY};
                        neighborNode->gCost = startNode.gCost + 1;
                        neighborNode->hCost = calculateH((Node){newX, newY}, end);
                        neighborNode->fCost = calculateFCost(neighborNode);
                        neighborNode->parent = &startNode;

                        if (!isNodeInList(&openSet, neighborNode->position)) {
                            addNode(&openSet, neighborNode->position);
                        } else {
                            if (neighborNode->gCost < startNode.gCost) {
                                // Update existing node's details
                                startNode.gCost = neighborNode->gCost;
                                startNode.parent = neighborNode->parent;
                            }
                        }
                    }
                }
            }
        }

        addNode(&closedSet, current);
    }

    free(pathNodeList.nodes);
}

// Initialize a list of nodes
void initNodeList(NodeList *list, int capacity) {
    list->nodes = malloc(capacity * sizeof(Node));
    list->size = 0;
    list->capacity = capacity;
}

// Add a node to the list
void addNode(NodeList *list, Node node) {
    if (list->size < list->capacity) {
        list->nodes[list->size++] = node;
    }
}

// Remove a node from the list
Node removeNode(NodeList *list) {
    if (list->size > 0) {
        Node node = list->nodes[0];
        memmove(list->nodes, &list->nodes[1], (list->size - 1) * sizeof(Node));
        list->size--;
        return node;
    }
    return (Node){-1, -1}; // Indicating no node
}

// Check if the node is in the list
bool isNodeInList(NodeList *list, Node node) {
    for (int i = 0; i < list->size; i++) {
        if (list->nodes[i].x == node.x && list->nodes[i].y == node.y) {
            return true;
        }
    }
    return false;
}

// Calculate the heuristic
int calculateH(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Calculate the F cost
int calculateFCost(PathNode* node) {
    return node->gCost + node->hCost;
}

// Check if the grid position is walkable
bool isWalkable(char grid[HEIGHT][WIDTH], int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[y][x] != '#');
}

// Reconstruct the path
void reconstructPath(PathNode *node) {
    // Traverses back to display the path
    while (node != NULL) {
        printf("Path: (%d, %d)\n", node->position.x, node->position.y);
        node = node->parent; // go to the parent
    }
}