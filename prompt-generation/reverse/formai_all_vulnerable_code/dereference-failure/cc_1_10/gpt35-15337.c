//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Struct to represent each node in the graph
typedef struct Node {
    int data;
    int n_neighbors;
    struct Node** neighbors;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->n_neighbors = 0;
    newNode->neighbors = NULL;
    return newNode;
}

// Function to add a neighbor to a node
void addNeighbor(Node* node, Node* neighbor) {
    node->neighbors = (Node**) realloc(node->neighbors, sizeof(Node*) * ++node->n_neighbors);
    node->neighbors[node->n_neighbors-1] = neighbor;
}

// Function to traverse the graph using BFS and find the shortest path
void findPath(Node* start, Node* end) {
    if (start == end) {
        printf("Start and end nodes are the same!\n");
        return;
    }

    // Create a queue for BFS traversal
    Node** queue = (Node**) malloc(sizeof(Node*) * (start->n_neighbors + 1));
    int queueStart = 0, queueEnd = 0, nVisited = 0;
    int* visited = (int*) calloc(start->n_neighbors, sizeof(int));
    queue[queueEnd++] = start;
    visited[start->data] = 1;

    // Start BFS traversal
    while (queueStart < queueEnd) {
        Node* curr = queue[queueStart++];
        if (curr == end) {
            printf("Path found!\n");
            return;
        }
        for (int i = 0; i < curr->n_neighbors; i++) {
            Node* neighbor = curr->neighbors[i];
            if (!visited[neighbor->data]) {
                queue[queueEnd++] = neighbor;
                visited[neighbor->data] = 1;
            }
        }
        nVisited++;
    }

    printf("No path found!\n");
    free(queue);
    free(visited);
}

int main() {
    // Create nodes
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    // Connect nodes to form a graph
    addNeighbor(node1, node2);
    addNeighbor(node1, node3);
    addNeighbor(node2, node3);
    addNeighbor(node3, node4);
    addNeighbor(node4, node5);

    // Find shortest path using BFS
    findPath(node1, node5);

    // Free memory
    free(node1->neighbors);
    free(node1);
    free(node2->neighbors);
    free(node2);
    free(node3->neighbors);
    free(node3);
    free(node4->neighbors);
    free(node4);
    free(node5->neighbors);
    free(node5);

    return 0;
}