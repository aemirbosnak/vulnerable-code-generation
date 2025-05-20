//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Node struct for the graph
typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

// Graph struct
typedef struct Graph {
    int num_nodes;
    Node* head;
} Graph;

// Queue struct for the BFS algorithm
typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

// Function to create a new node
Node* create_node(int x, int y) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->x = x;
    new_node->y = y;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new graph
Graph* create_graph() {
    Graph* new_graph = (Graph*) malloc(sizeof(Graph));
    new_graph->num_nodes = 0;
    new_graph->head = NULL;
    return new_graph;
}

// Function to add a node to the graph
void add_node(Graph* graph, int x, int y) {
    Node* new_node = create_node(x, y);
    if (graph->head == NULL) {
        graph->head = new_node;
    } else {
        Node* current_node = graph->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    graph->num_nodes++;
}

// Function to create a new queue
Queue* create_queue() {
    Queue* new_queue = (Queue*) malloc(sizeof(Queue));
    new_queue->head = NULL;
    new_queue->tail = NULL;
    return new_queue;
}

// Function to enqueue a node to the queue
void enqueue(Queue* queue, Node* node) {
    if (queue->head == NULL) {
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }
}

// Function to dequeue a node from the queue
Node* dequeue(Queue* queue) {
    if (queue->head == NULL) {
        return NULL;
    } else {
        Node* node = queue->head;
        queue->head = node->next;
        if (queue->head == NULL) {
            queue->tail = NULL;
        }
        return node;
    }
}

// Function to check if a node is in the queue
int is_in_queue(Queue* queue, Node* node) {
    Node* current_node = queue->head;
    while (current_node != NULL) {
        if (current_node->x == node->x && current_node->y == node->y) {
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

// Function to perform a BFS on the graph
int bfs(Graph* graph, Node* start, Node* end) {
    Queue* queue = create_queue();
    enqueue(queue, start);
    while (queue->head != NULL) {
        Node* current_node = dequeue(queue);
        if (current_node->x == end->x && current_node->y == end->y) {
            return 1;
        }
        Node* current_node_next = current_node->next;
        while (current_node_next != NULL) {
            if (!is_in_queue(queue, current_node_next)) {
                enqueue(queue, current_node_next);
            }
            current_node_next = current_node_next->next;
        }
    }
    return 0;
}

// Main function
int main() {
    // Create a graph
    Graph* graph = create_graph();

    // Add nodes to the graph
    add_node(graph, 0, 0);
    add_node(graph, 1, 0);
    add_node(graph, 2, 0);
    add_node(graph, 3, 0);
    add_node(graph, 0, 1);
    add_node(graph, 1, 1);
    add_node(graph, 2, 1);
    add_node(graph, 3, 1);
    add_node(graph, 0, 2);
    add_node(graph, 1, 2);
    add_node(graph, 2, 2);
    add_node(graph, 3, 2);

    // Create a start and end node
    Node* start = create_node(0, 0);
    Node* end = create_node(3, 2);

    // Perform a BFS on the graph
    int result = bfs(graph, start, end);

    // Print the result
    if (result == 1) {
        printf("Path found!\n");
    } else {
        printf("Path not found.\n");
    }

    return 0;
}