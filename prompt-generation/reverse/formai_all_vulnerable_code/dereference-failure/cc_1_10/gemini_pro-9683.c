//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to represent a node in the graph
typedef struct Node {
    int x;
    int y;
    struct Node *parent;
    int g;  // Cost from the starting node
    int h;  // Heuristic cost to the goal node
    int f;  // Total cost (g + h)
} Node;

// Structure to represent the graph
typedef struct Graph {
    int width;
    int height;
    Node **nodes;
} Graph;

// Structure to represent the queue of nodes to be processed
typedef struct Queue {
    Node *node;
    struct Queue *next;
} Queue;

// Function to create a new node
Node *create_node(int x, int y) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->parent = NULL;
    node->g = 0;
    node->h = 0;
    node->f = 0;
    return node;
}

// Function to create a new graph
Graph *create_graph(int width, int height) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->width = width;
    graph->height = height;
    graph->nodes = (Node **)malloc(sizeof(Node *) * width * height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            graph->nodes[i * height + j] = create_node(i, j);
        }
    }
    return graph;
}

// Function to add an obstacle to the graph
void add_obstacle(Graph *graph, int x, int y) {
    graph->nodes[x * graph->height + y]->g = -1;
}

// Function to calculate the heuristic cost of a node
int calculate_heuristic_cost(Node *node, Node *goal) {
    return abs(node->x - goal->x) + abs(node->y - goal->y);
}

// Function to calculate the total cost of a node
int calculate_total_cost(Node *node) {
    return node->g + node->h;
}

// Function to add a node to the queue
void add_node_to_queue(Queue **queue, Node *node) {
    Queue *new_node = (Queue *)malloc(sizeof(Queue));
    new_node->node = node;
    new_node->next = NULL;
    if (*queue == NULL) {
        *queue = new_node;
    } else {
        Queue *current_node = *queue;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Function to remove a node from the queue
Node *remove_node_from_queue(Queue **queue) {
    if (*queue == NULL) {
        return NULL;
    }
    Node *node = (*queue)->node;
    *queue = (*queue)->next;
    return node;
}

// Function to find the path from the starting node to the goal node
Node *find_path(Graph *graph, Node *start, Node *goal) {
    // Create a queue of nodes to be processed
    Queue *queue = NULL;

    // Add the starting node to the queue
    add_node_to_queue(&queue, start);

    // While the queue is not empty
    while (queue != NULL) {
        // Get the node with the lowest total cost from the queue
        Node *current_node = remove_node_from_queue(&queue);

        // If the current node is the goal node, return the path
        if (current_node == goal) {
            return current_node;
        }

        // For each neighbor of the current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // If the neighbor is not an obstacle
                if (current_node->x + i >= 0 && current_node->x + i < graph->width && 
                    current_node->y + j >= 0 && current_node->y + j < graph->height && 
                    graph->nodes[(current_node->x + i) * graph->height + (current_node->y + j)]->g != -1) {
                    // Calculate the cost of the neighbor
                    int g = current_node->g + 1;
                    int h = calculate_heuristic_cost(graph->nodes[(current_node->x + i) * graph->height + (current_node->y + j)], goal);
                    int f = calculate_total_cost(graph->nodes[(current_node->x + i) * graph->height + (current_node->y + j)]);

                    // If the neighbor is not already in the queue
                    if (graph->nodes[(current_node->x + i) * graph->height + (current_node->y + j)]->parent == NULL) {
                        // Add the neighbor to the queue
                        add_node_to_queue(&queue, graph->nodes[(current_node->x + i) * graph->height + (current_node->y + j)]);

                        // Set the neighbor's parent to the current node
                        graph->nodes[(current_node->x + i) * graph->height + (current_node->y + j)]->parent = current_node;
                    }
                }
            }
        }
    }

    // No path found
    return NULL;
}

// Function to print the path from the starting node to the goal node
void print_path(Node *node) {
    if (node == NULL) {
        return;
    }
    print_path(node->parent);
    printf("(%d, %d)\n", node->x, node->y);
}

// Main function
int main() {
    // Create a graph
    Graph *graph = create_graph(10, 10);

    // Add obstacles to the graph
    add_obstacle(graph, 2, 2);
    add_obstacle(graph, 2, 3);
    add_obstacle(graph, 2, 4);
    add_obstacle(graph, 6, 6);
    add_obstacle(graph, 6, 7);
    add_obstacle(graph, 6, 8);

    // Create the starting and goal nodes
    Node *start = graph->nodes[0 * graph->height + 0];
    Node *goal = graph->nodes[9 * graph->height + 9];

    // Find the path from the starting node to the goal node
    Node *path = find_path(graph, start, goal);

    // Print the path
    print_path(path);

    return 0;
}