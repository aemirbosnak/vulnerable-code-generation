//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define a structure for graph node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Define a structure for graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Define a structure for the queue
typedef struct Queue {
    int items[100];
    int front;
    int rear;
} Queue;

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Allocate memory for the adjacency lists
    graph->adjLists = malloc(vertices * sizeof(Node*));

    // Initialize each adjacency list
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to create a queue
Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to add an item to the queue
void enqueue(Queue* q, int value) {
    if (q->rear == 99) {
        printf("Queue is full!\n");
        return;
    } 
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to remove an item from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1; // reset queue
    }
    return item;
}

// Function to perform BFS on the graph
void bfs(Graph* graph, int startVertex) {
    Queue* q = createQueue();
    int* visited = malloc(graph->numVertices * sizeof(int));

    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0; // Initialize all vertices as unvisited
    }

    visited[startVertex] = 1; // Mark the starting node as visited
    enqueue(q, startVertex); // Enqueue the starting node

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1; // Mark adjacent vertex as visited
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    
    free(visited);
    free(q);
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph->adjLists);
    free(graph);
}

// Main function to demonstrate the graph representation and BFS
int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);

    // Adding edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    
    printf("Breadth-First Search starting from vertex 0:\n");
    bfs(graph, 0);

    // Freeing graph memory
    freeGraph(graph);
    
    return 0;
}