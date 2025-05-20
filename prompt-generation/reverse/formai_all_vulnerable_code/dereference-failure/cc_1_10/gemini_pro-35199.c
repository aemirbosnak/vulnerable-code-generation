//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Node structure
typedef struct Node {
    int x, y;
    struct Node *parent;
    float g, h, f;
} Node;

// Grid structure
typedef struct Grid {
    int width, height;
    Node **nodes;
} Grid;

// Queue structure
typedef struct Queue {
    Node **nodes;
    int front, rear;
    int size;
} Queue;

// Queue functions
Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->nodes = (Node **)malloc(sizeof(Node *) * size);
    queue->front = queue->rear = -1;
    queue->size = size;
    return queue;
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

int isFull(Queue *queue) {
    return (queue->rear + 1) % queue->size == queue->front;
}

void enqueue(Queue *queue, Node *node) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    } else if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
        queue->nodes[queue->rear] = node;
    } else {
        queue->rear = (queue->rear + 1) % queue->size;
        queue->nodes[queue->rear] = node;
    }
}

Node *dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return NULL;
    } else if (queue->front == queue->rear) {
        int node = queue->nodes[queue->front];
        queue->front = queue->rear = -1;
        return node;
    } else {
        int node = queue->nodes[queue->front];
        queue->front = (queue->front + 1) % queue->size;
        return node;
    }
}

// Grid functions
Grid *createGrid(int width, int height) {
    Grid *grid = (Grid *)malloc(sizeof(Grid));
    grid->width = width;
    grid->height = height;
    grid->nodes = (Node **)malloc(sizeof(Node *) * width * height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            grid->nodes[i * height + j] = (Node *)malloc(sizeof(Node));
            grid->nodes[i * height + j]->x = i;
            grid->nodes[i * height + j]->y = j;
            grid->nodes[i * height + j]->parent = NULL;
            grid->nodes[i * height + j]->g = 0;
            grid->nodes[i * height + j]->h = 0;
            grid->nodes[i * height + j]->f = 0;
        }
    }
    return grid;
}

void destroyGrid(Grid *grid) {
    for (int i = 0; i < grid->width; i++) {
        for (int j = 0; j < grid->height; j++) {
            free(grid->nodes[i * grid->height + j]);
        }
    }
    free(grid->nodes);
    free(grid);
}

// A* algorithm functions
Node *findPath(Grid *grid, Node *start, Node *end) {
    // Initialize the open and closed sets
    Queue *openSet = createQueue(grid->width * grid->height);
    Queue *closedSet = createQueue(grid->width * grid->height);

    // Add the start node to the open set
    enqueue(openSet, start);

    // While the open set is not empty
    while (!isEmpty(openSet)) {
        // Get the node with the lowest f score from the open set
        Node *current = openSet->nodes[openSet->front];
        for (int i = openSet->front + 1; i < openSet->rear; i++) {
            if (openSet->nodes[i]->f < current->f) {
                current = openSet->nodes[i];
            }
        }

        // Move the current node from the open set to the closed set
        dequeue(openSet);
        enqueue(closedSet, current);

        // If the current node is the end node, return the path
        if (current == end) {
            return current;
        }

        // For each neighbor of the current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int x = current->x + i;
                int y = current->y + j;
                if (x >= 0 && x < grid->width && y >= 0 && y < grid->height && grid->nodes[x * grid->height + y]->parent == NULL) {
                    // Calculate the g score of the neighbor
                    float g = current->g + sqrt(pow(x - current->x, 2) + pow(y - current->y, 2));

                    // Calculate the h score of the neighbor
                    float h = sqrt(pow(x - end->x, 2) + pow(y - end->y, 2));

                    // Calculate the f score of the neighbor
                    float f = g + h;

                    // If the neighbor is not in the open set or the f score of the neighbor is lower than the f score of the neighbor in the open set
                    if (!isNodeInQueue(openSet, grid->nodes[x * grid->height + y]) || grid->nodes[x * grid->height + y]->f > f) {
                        // Add the neighbor to the open set
                        grid->nodes[x * grid->height + y]->parent = current;
                        grid->nodes[x * grid->height + y]->g = g;
                        grid->nodes[x * grid->height + y]->h = h;
                        grid->nodes[x * grid->height + y]->f = f;
                        enqueue(openSet, grid->nodes[x * grid->height + y]);
                    }
                }
            }
        }
    }

    // No path found
    return NULL;
}

int isNodeInQueue(Queue *queue, Node *node) {
    for (int i = queue->front; i <= queue->rear; i++) {
        if (queue->nodes[i] == node) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    // Create a grid
    Grid *grid = createGrid(10, 10);

    // Set the start and end nodes
    Node *start = grid->nodes[0];
    Node *end = grid->nodes[9 * 10 + 9];

    // Find the path
    Node *path = findPath(grid, start, end);

    // Print the path
    if (path != NULL) {
        while (path != NULL) {
            printf("(%d, %d)\n", path->x, path->y);
            path = path->parent;
        }
    } else {
        printf("No path found!\n");
    }

    // Destroy the grid
    destroyGrid(grid);

    return 0;
}