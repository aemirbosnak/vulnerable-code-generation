//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Create a node struct
typedef struct Node {
    int x;
    int y;
    struct Node* parent;
    float g;
    float h;
    float f;
} Node;

// Create a grid struct
typedef struct Grid {
    int width;
    int height;
    int** grid;
} Grid;

// Create a priority queue struct
typedef struct PriorityQueue {
    int size;
    Node** nodes;
} PriorityQueue;

// Create a new node
Node* createNode(int x, int y, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->parent = parent;
    node->g = 0;
    node->h = 0;
    node->f = 0;
    return node;
}

// Create a new grid
Grid* createGrid(int width, int height) {
    Grid* grid = (Grid*)malloc(sizeof(Grid));
    grid->width = width;
    grid->height = height;
    grid->grid = (int**)malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        grid->grid[i] = (int*)malloc(sizeof(int) * width);
    }
    return grid;
}

// Create a new priority queue
PriorityQueue* createPriorityQueue() {
    PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->nodes = (Node**)malloc(sizeof(Node*) * 100);
    return queue;
}

// Insert a node into the priority queue
void insertNode(PriorityQueue* queue, Node* node) {
    int i = queue->size;
    while (i > 0 && node->f < queue->nodes[i - 1]->f) {
        queue->nodes[i] = queue->nodes[i - 1];
        i--;
    }
    queue->nodes[i] = node;
    queue->size++;
}

// Get the first node from the priority queue
Node* getNode(PriorityQueue* queue) {
    Node* node = queue->nodes[0];
    queue->size--;
    for (int i = 0; i < queue->size; i++) {
        queue->nodes[i] = queue->nodes[i + 1];
    }
    return node;
}

// Check if a node is valid
bool isValid(Grid* grid, Node* node) {
    return node->x >= 0 && node->x < grid->width && node->y >= 0 && node->y < grid->height && grid->grid[node->y][node->x] == 0;
}

// Calculate the heuristic cost
float calculateHeuristic(Node* node, Node* goal) {
    return abs(node->x - goal->x) + abs(node->y - goal->y);
}

// Calculate the path
void calculatePath(Grid* grid, Node* start, Node* goal) {
    // Create a priority queue
    PriorityQueue* queue = createPriorityQueue();

    // Insert the start node into the priority queue
    insertNode(queue, start);

    // While the priority queue is not empty
    while (queue->size > 0) {
        // Get the first node from the priority queue
        Node* node = getNode(queue);

        // Check if the node is the goal node
        if (node->x == goal->x && node->y == goal->y) {
            break;
        }

        // For each valid neighbor of the node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                Node* neighbor = createNode(node->x + i, node->y + j, node);
                if (isValid(grid, neighbor)) {
                    // Calculate the cost of the neighbor
                    neighbor->g = node->g + 1;
                    neighbor->h = calculateHeuristic(neighbor, goal);
                    neighbor->f = neighbor->g + neighbor->h;

                    // Insert the neighbor into the priority queue
                    insertNode(queue, neighbor);
                }
            }
        }
    }

    // Print the path
    Node* node = goal;
    while (node != start) {
        printf("(%d, %d)\n", node->x, node->y);
        node = node->parent;
    }
    printf("(%d, %d)\n", start->x, start->y);
}

int main() {
    // Create a grid
    Grid* grid = createGrid(10, 10);

    // Set some obstacles
    grid->grid[1][2] = 1;
    grid->grid[2][3] = 1;
    grid->grid[3][4] = 1;
    grid->grid[4][5] = 1;
    grid->grid[5][6] = 1;

    // Create the start and goal nodes
    Node* start = createNode(0, 0, NULL);
    Node* goal = createNode(9, 9, NULL);

    // Calculate the path
    calculatePath(grid, start, goal);

    return 0;
}