//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Define maze
int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

// Define start and end points
int startX = 1, startY = 1;
int endX = 8, endY = 8;

// Define node structure
typedef struct node {
    int x;
    int y;
    struct node* prev;
} Node;

// Define queue structure
typedef struct queue {
    int size;
    Node* front;
    Node* back;
} Queue;

// Create a new Node
Node* newNode(int x, int y, Node* prev) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->prev = prev;
    return node;
}

// Create a new queue
Queue* newQueue() {
    Queue* queue = malloc(sizeof(Queue));
    queue->size = 0;
    queue->front = NULL;
    queue->back = NULL;
    return queue;
}

// Add a node to the back of the queue
void enqueue(Queue* queue, Node* node) {
    if (queue->size == 0) {
        queue->front = node;
        queue->back = node;
    } else {
        queue->back->prev = node;
        queue->back = node;
    }
    queue->size++;
}

// Remove and return the node at the front of the queue
Node* dequeue(Queue* queue) {
    if (queue->size == 0) {
        return NULL;
    }
    Node* node = queue->front;
    queue->front = node->prev;
    queue->size--;
    return node;
}

// Check if node is within the bounds of the maze and open
bool isValid(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 0;
}

// Find the shortest path from start to end in the maze using BFS
void findShortestPath() {
    Queue* queue = newQueue();
    Node* start = newNode(startX, startY, NULL);
    enqueue(queue, start);
    while (queue->size > 0) {
        Node* node = dequeue(queue);
        if (node->x == endX && node->y == endY) {
            // Found the end, print the path
            printf("Found shortest path: ");
            while (node != NULL) {
                printf("(%d,%d) ", node->x, node->y);
                node = node->prev;
            }
            printf("\n");
            return;
        }
        // Add neighbors to the queue
        if (isValid(node->x+1, node->y)) {
            Node* neighbor = newNode(node->x+1, node->y, node);
            enqueue(queue, neighbor);
            maze[node->x+1][node->y] = 2; // Mark as visited
        }
        if (isValid(node->x-1, node->y)) {
            Node* neighbor = newNode(node->x-1, node->y, node);
            enqueue(queue, neighbor);
            maze[node->x-1][node->y] = 2; // Mark as visited
        }
        if (isValid(node->x, node->y+1)) {
            Node* neighbor = newNode(node->x, node->y+1, node);
            enqueue(queue, neighbor);
            maze[node->x][node->y+1] = 2; // Mark as visited
        }
        if (isValid(node->x, node->y-1)) {
            Node* neighbor = newNode(node->x, node->y-1, node);
            enqueue(queue, neighbor);
            maze[node->x][node->y-1] = 2; // Mark as visited
        }
    }
    printf("Could not find a path from start to end.\n");
}

// Main function
int main() {
    findShortestPath();
    return 0;
}