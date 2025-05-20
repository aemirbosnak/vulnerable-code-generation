//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

// Node structure for A* pathfinding
typedef struct Node {
    int x, y;
    float g, h, f;
    struct Node *parent;
} Node;

// Queue structure for A* pathfinding
typedef struct Queue {
    Node *nodes[MAX_SIZE];
    int front, rear;
} Queue;

// Create a new node
Node *create_node(int x, int y) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g = 0;
    node->h = 0;
    node->f = 0;
    node->parent = NULL;
    return node;
}

// Enqueue a node into the queue
void enqueue(Queue *queue, Node *node) {
    queue->nodes[queue->rear] = node;
    queue->rear++;
}

// Dequeue a node from the queue
Node *dequeue(Queue *queue) {
    Node *node = queue->nodes[queue->front];
    queue->front++;
    return node;
}

// Check if the queue is empty
int is_empty(Queue *queue) {
    return queue->front == queue->rear;
}

// Get the neighbors of a node
Node **get_neighbors(Node *node, int width, int height) {
    Node **neighbors = (Node **)malloc(sizeof(Node *) * 4);
    int i = 0;

    // Check if the node is on the left edge
    if (node->x > 0) {
        neighbors[i++] = create_node(node->x - 1, node->y);
    }

    // Check if the node is on the right edge
    if (node->x < width - 1) {
        neighbors[i++] = create_node(node->x + 1, node->y);
    }

    // Check if the node is on the top edge
    if (node->y > 0) {
        neighbors[i++] = create_node(node->x, node->y - 1);
    }

    // Check if the node is on the bottom edge
    if (node->y < height - 1) {
        neighbors[i++] = create_node(node->x, node->y + 1);
    }

    return neighbors;
}

// Calculate the heuristic cost of a node
float calculate_h(Node *node, Node *goal) {
    return abs(node->x - goal->x) + abs(node->y - goal->y);
}

// Calculate the A* path from the start node to the goal node
Node *a_star(Node *start, Node *goal, int width, int height) {
    // Create a queue for the open nodes
    Queue *open_queue = (Queue *)malloc(sizeof(Queue));
    open_queue->front = 0;
    open_queue->rear = 0;

    // Create a queue for the closed nodes
    Queue *closed_queue = (Queue *)malloc(sizeof(Queue));
    closed_queue->front = 0;
    closed_queue->rear = 0;

    // Add the start node to the open queue
    enqueue(open_queue, start);

    while (!is_empty(open_queue)) {
        // Get the node with the lowest f cost from the open queue
        Node *current = dequeue(open_queue);

        // Check if the current node is the goal node
        if (current->x == goal->x && current->y == goal->y) {
            return current;
        }

        // Add the current node to the closed queue
        enqueue(closed_queue, current);

        // Get the neighbors of the current node
        Node **neighbors = get_neighbors(current, width, height);

        // For each neighbor of the current node
        for (int i = 0; i < 4; i++) {
            Node *neighbor = neighbors[i];

            // Check if the neighbor is not in the closed queue
            int in_closed_queue = 0;
            for (int j = 0; j < closed_queue->rear - closed_queue->front; j++) {
                Node *node = closed_queue->nodes[closed_queue->front + j];
                if (node->x == neighbor->x && node->y == neighbor->y) {
                    in_closed_queue = 1;
                    break;
                }
            }

            if (in_closed_queue) {
                continue;
            }

            // Calculate the g cost of the neighbor
            neighbor->g = current->g + 1;

            // Calculate the h cost of the neighbor
            neighbor->h = calculate_h(neighbor, goal);

            // Calculate the f cost of the neighbor
            neighbor->f = neighbor->g + neighbor->h;

            // Add the neighbor to the open queue
            enqueue(open_queue, neighbor);

            // Set the parent of the neighbor to the current node
            neighbor->parent = current;
        }
    }

    return NULL;
}

// Print the path from the start node to the goal node
void print_path(Node *goal) {
    Node *current = goal;
    while (current != NULL) {
        printf("(%d, %d)\n", current->x, current->y);
        current = current->parent;
    }
}

int main() {
    // Create the start node
    Node *start = create_node(0, 0);

    // Create the goal node
    Node *goal = create_node(9, 9);

    // Create the grid
    int width = 10;
    int height = 10;
    int grid[width][height];

    // Set the obstacles in the grid
    grid[1][1] = 1;
    grid[1][2] = 1;
    grid[1][3] = 1;
    grid[2][1] = 1;
    grid[2][2] = 1;
    grid[2][3] = 1;
    grid[3][1] = 1;
    grid[3][2] = 1;
    grid[3][3] = 1;

    // Find the path from the start node to the goal node
    Node *path = a_star(start, goal, width, height);

    // Print the path
    if (path != NULL) {
        print_path(path);
    } else {
        printf("No path found.\n");
    }

    return 0;
}