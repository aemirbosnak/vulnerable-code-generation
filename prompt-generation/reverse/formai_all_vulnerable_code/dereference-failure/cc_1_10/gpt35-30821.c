//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition of graph node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Definition of priority queue node
typedef struct PQNode {
    int vertex;
    int score;
    struct PQNode* next;
} PQNode;

// Function to create a new node in graph
Node* createNode(int v, int w) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Function to add edge to graph
void addEdge(Node* graph[], int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = graph[u];
    graph[u] = newNode;
}

// Function to create a new node in priority queue
PQNode* createPQNode(int v, int s) {
    PQNode* newNode = (PQNode*) malloc(sizeof(PQNode));
    newNode->vertex = v;
    newNode->score = s;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node in priority queue
void insertPQ(PQNode** queue, PQNode* node) {
    if (*queue == NULL || node->score <= (*queue)->score) {
        node->next = *queue;
        *queue = node;
    } else {
        PQNode* current = *queue;
        while (current->next != NULL && current->next->score < node->score) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}

// Function to remove node from priority queue
PQNode* removePQ(PQNode** queue) {
    PQNode* temp = *queue;
    *queue = (*queue)->next;
    return temp;
}

// Function to calculate the heuristic value for A* algorithm
int heuristic(int source, int destination) {
    return abs(destination - source);
}

// Function for A* algorithm to calculate shortest path between two nodes
void aStar(int source, int destination, Node* graph[], int size) {
    PQNode* openSet = createPQNode(source, 0); // Priority queue to keep track of open set 
    int* gScore = (int*) malloc(size * sizeof(int)); // Array to keep track of g scores
    int* fScore = (int*) malloc(size * sizeof(int)); // Array to keep track of f scores
    
    // Initialize g and f scores as infinity
    for (int i = 0; i < size; i++) {
        gScore[i] = INT_MAX;
        fScore[i] = INT_MAX;
    }
    
    // For the source vertex, g score is 0 and f score is the heuristic value
    gScore[source] = 0;
    fScore[source] = heuristic(source, destination);
    
    while (openSet != NULL) {
        // Remove vertex with lowest f score from open set
        PQNode* current = removePQ(&openSet);
        
        if (current->vertex == destination) {
            // Destination has been reached, print shortest path
            printf("Shortest path from %d to %d: %d\n", source, destination, gScore[destination]);
            return;
        }
        
        Node* neighbors = graph[current->vertex];
        while (neighbors != NULL) {
            int neighbor = neighbors->vertex;
            int tentativeGScore = gScore[current->vertex] + neighbors->weight;
            if (tentativeGScore < gScore[neighbor]) {
                // This is a better path than the one previously found
                gScore[neighbor] = tentativeGScore;
                fScore[neighbor] = tentativeGScore + heuristic(neighbor, destination);
                PQNode* neighborNode = createPQNode(neighbor, fScore[neighbor]);
                insertPQ(&openSet, neighborNode);
            }
            neighbors = neighbors->next;
        }
    }
    
    // Destination was not reached, no path exists
    printf("No path found from %d to %d\n", source, destination);
}

// Driver code to test A* algorithm
int main() {
    int size = 8; // Number of vertices in graph
    Node* graph[size]; // Array of head nodes for each vertex
    
    // Initialize graph with edges and their weights
    addEdge(graph, 0, 1, 3);
    addEdge(graph, 0, 2, 6);
    addEdge(graph, 1, 3, 9);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 2, 5, 5);
    addEdge(graph, 3, 6, 8);
    addEdge(graph, 4, 6, 1);
    addEdge(graph, 4, 7, 4);
    addEdge(graph, 5, 7, 10);
    
    // Test A* algorithm with different source and destination vertices
    aStar(0, 6, graph, size);
    aStar(3, 7, graph, size);
    aStar(1, 2, graph, size);
    
    return 0;
}