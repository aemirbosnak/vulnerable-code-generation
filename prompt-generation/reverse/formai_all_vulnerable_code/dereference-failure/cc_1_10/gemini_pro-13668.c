//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5
#define INF 99999

// Node struct
typedef struct Node {
    int x;
    int y;
    int cost;
    struct Node* parent;
} Node;

// Queue struct
typedef struct Queue {
    struct Node* nodes[ROWS * COLS];
    int front;
    int rear;
} Queue;

// Create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Add a node to the queue
void enqueue(Queue* queue, Node* node) {
    if (queue->rear == ROWS * COLS - 1) {
        printf("Queue is full\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->nodes[queue->rear] = node;
    }
}

// Remove a node from the queue
Node* dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    } else {
        Node* node = queue->nodes[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return node;
    }
}

// Create a new node
Node* createNode(int x, int y, int cost, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->cost = cost;
    node->parent = parent;
    return node;
}

// Check if a node is valid
bool isValid(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

// Check if a node is blocked
bool isBlocked(int x, int y) {
    // TODO: Implement this function
    return false;
}

// Find the path from the start node to the end node
Node* findPath(int start_x, int start_y, int end_x, int end_y) {
    // Create a queue to store the nodes
    Queue* queue = createQueue();

    // Create a 2D array to store the costs of the nodes
    int costs[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            costs[i][j] = INF;
        }
    }

    // Set the cost of the start node to 0
    costs[start_x][start_y] = 0;

    // Add the start node to the queue
    Node* start_node = createNode(start_x, start_y, 0, NULL);
    enqueue(queue, start_node);

    // While the queue is not empty
    while (!isEmpty(queue)) {
        // Get the node with the lowest cost from the queue
        Node* node = dequeue(queue);

        // Check if the node is the end node
        if (node->x == end_x && node->y == end_y) {
            return node;
        }

        // Get the neighbors of the node
        int neighbors[4][2] = {
            {node->x - 1, node->y},
            {node->x + 1, node->y},
            {node->x, node->y - 1},
            {node->x, node->y + 1}
        };

        // For each neighbor
        for (int i = 0; i < 4; i++) {
            int x = neighbors[i][0];
            int y = neighbors[i][1];

            // Check if the neighbor is valid and not blocked
            if (isValid(x, y) && !isBlocked(x, y)) {
                // Calculate the cost of the neighbor
                int cost = node->cost + 1;

                // If the cost of the neighbor is less than the current cost of the neighbor
                if (cost < costs[x][y]) {
                    // Update the cost of the neighbor
                    costs[x][y] = cost;

                    // Add the neighbor to the queue
                    Node* neighbor_node = createNode(x, y, cost, node);
                    enqueue(queue, neighbor_node);
                }
            }
        }
    }

    // No path found
    return NULL;
}

// Print the path from the start node to the end node
void printPath(Node* node) {
    if (node == NULL) {
        return;
    }

    printPath(node->parent);
    printf("(%d, %d)\n", node->x, node->y);
}

// Main function
int main() {
    // Start node coordinates
    int start_x = 0;
    int start_y = 0;

    // End node coordinates
    int end_x = 4;
    int end_y = 4;

    // Find the path from the start node to the end node
    Node* path = findPath(start_x, start_y, end_x, end_y);

    // Print the path
    printPath(path);

    return 0;
}